/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarsha <fmarsha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 23:51:33 by fmarsha           #+#    #+#             */
/*   Updated: 2022/06/16 16:01:24 by fmarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_free(t_pipex *s)
{
	int	i;

	i = -1;
	while (s->cmd_args[++i])
		free(s->cmd_args[i]);
	free(s->cmd_args);
	free(s->cmd);
}

static char	*get_cmd(char **paths, char *cmd)
{
	char	*tmp;

	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		tmp = ft_strjoin(tmp, cmd);
		if (access(tmp, F_OK) == 0)
			return (tmp);
		free(tmp);
		paths++;
	}
	return (NULL);
}

void	close_pipes(t_pipex *s)
{
	int	i;

	i = -1;
	while (++i < (s->pipe_nms))
		close(s->pp[i]);
}

static void	ft_dup(int fd1, int fd2)
{
	dup2(fd1, 0);
	dup2(fd2, 1);
}

void	child(t_pipex s, char **argv, char **env)
{
	s.pid = fork();
	if (s.pid)
		return ;
	if (s.id == 0)
		ft_dup(s.infile, s.pp[1]);
	else if (s.id == s.cmd_nms - 1)
		ft_dup(s.pp[2 * (s.id - 1)], s.outfile);
	else
		ft_dup(s.pp[2 * (s.id - 1)], s.pp[2 * s.id + 1]);
	close_pipes(&s);
	s.cmd_args = ft_split(argv[2 + s.here_doc + s.id], ' ');
	s.cmd = get_cmd(s.cmd_paths, s.cmd_args[0]);
	if (!s.cmd)
	{
		msg_pipe(s.cmd_args[0]);
		child_free(&s);
		exit(1);
	}
	execve(s.cmd, s.cmd_args, env);
	msg_error("Execve:");
}
