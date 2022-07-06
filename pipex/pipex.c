/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarsha <fmarsha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 21:14:39 by fmarsha           #+#    #+#             */
/*   Updated: 2022/06/15 21:14:39 by fmarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parent_free(t_pipex *s)
{
	int	i;

	i = -1;
	close(s->infile);
	close(s->outfile);
	if (s->here_doc)
		unlink(".heredoc_tmp");
	while (s->cmd_paths[++i])
		free(s->cmd_paths[i]);
	free(s->cmd_paths);
	free(s->pp);
}

char	*find_path(char **env)
{
	while (ft_strncmp("PATH", *env, 4))
		env++;
	return (*env + 5);
}

void	get_files(int argc, char **argv, t_pipex *s)
{
	if (s->here_doc)
	{
		here_doc(argv[2], s);
		s->outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	}
	else
	{
		s->infile = open(argv[1], O_RDONLY);
		s->outfile = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	}
	if (s->outfile < 0)
		msg_error(ERR_OUTFILE);
	if (s->infile < 0)
	{
		if (s->here_doc)
			unlink(".heredoc_tmp");
		msg_error(ERR_INFILE);
	}
}

void	create_pipes(t_pipex *s)
{
	int	i;

	i = 0;
	while (i < s->cmd_nms - 1)
	{
		if (pipe(s->pp + 2 * i) < 0)
			parent_free(s);
		i++;
	}
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	g_d;

	if (argc < 5)
		return (msg(ERR_INPUT));
	g_d.here_doc = !ft_strncmp("here_doc", argv[1], 9);
	if (g_d.here_doc && argc < 6)
		return (msg(ERR_INPUT));
	get_files(argc, argv, &g_d);
	g_d.cmd_nms = argc - 3 - g_d.here_doc;
	g_d.cmd_paths = ft_split(find_path(env), ':');
	if (!g_d.cmd_paths)
		pipe_free(&g_d);
	g_d.pipe_nms = 2 * (g_d.cmd_nms - 1);
	g_d.pp = (int *)malloc(sizeof(int) * g_d.pipe_nms);
	if (!g_d.pp)
		msg_error(ERR_PIPE);
	create_pipes(&g_d);
	g_d.id = -1;
	while (++(g_d.id) < g_d.cmd_nms)
		child(g_d, argv, env);
	close_pipes(&g_d);
	waitpid(-1, NULL, 0);
	parent_free(&g_d);
	return (0);
}
