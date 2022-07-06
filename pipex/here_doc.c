/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarsha <fmarsha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 00:21:26 by fmarsha           #+#    #+#             */
/*   Updated: 2022/06/16 16:53:24 by fmarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	msg(char *err)
{
	write(2, err, ft_strlen(err));
	return (1);
}

void	msg_pipe(char *arg)
{
	write(2, ERR_CMD, ft_strlen(ERR_CMD));
	write(2, arg, ft_strlen(arg));
	write(2, "\n", 1);
}

void	msg_error(char *err)
{
	perror(err);
	exit (1);
}

void	pipe_free(t_pipex *s)
{
	close(s->infile);
	close(s->outfile);
	if (s->here_doc)
		unlink(".heredoc_tmp");
	free(s->pp);
	msg(ERR_ENVP);
	exit(1);
}

void	here_doc(char *argv, t_pipex *pipex)
{
	int		file;
	char	*buf;

	file = open(".heredoc_tmp", O_CREAT | O_WRONLY | O_TRUNC, 0000644);
	if (file < 0)
		msg_error(ERR_HEREDOC);
	while (1)
	{
		write(1, "heredoc> ", 9);
		buf = get_next_line(0);
		if (buf == 0)
			exit(1);
		if (!ft_strncmp(argv, buf, ft_strlen(argv)))
			break ;
		write(file, buf, ft_strlen(buf));
		free(buf);
	}
	free(buf);
	close(file);
	pipex->infile = open(".heredoc_tmp", O_RDONLY);
}
