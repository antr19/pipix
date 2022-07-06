/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarsha <fmarsha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 15:56:35 by fmarsha           #+#    #+#             */
/*   Updated: 2022/06/16 15:57:39 by fmarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# include "ft_gnl/get_next_line.h"

# define ERR_INFILE "Infile"
# define ERR_OUTFILE "Outfile"
# define ERR_INPUT "Invalid number of arguments.\n"
# define ERR_PIPE "Pipe"
# define ERR_ENVP "Environment"
# define ERR_CMD "Command not found: "
# define ERR_HEREDOC "here_doc"

typedef struct s_pipex
{
	int		pid;
	int		tube[2];
	int		infile;
	int		outfile;
	char	**cmd_paths;
	char	**cmd_args;
	char	*cmd;
	int		here_doc;
	int		cmd_nms;
	int		pipe_nms;
	int		*pp;
	int		id;
}	t_pipex;

void	child(t_pipex s, char **argv, char **env);
void	close_pipes(t_pipex *s);

void	here_doc(char *argv, t_pipex *s);

void	pipe_free(t_pipex *s);

int		msg(char *err);
void	msg_pipe(char *arg);
void	msg_error(char *err);

char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);
#endif