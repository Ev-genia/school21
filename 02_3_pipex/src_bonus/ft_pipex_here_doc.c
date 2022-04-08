/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_here_doc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:52:24 by mlarra            #+#    #+#             */
/*   Updated: 2022/03/09 15:47:26 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_perror(char *str)
{
	perror(str);
	exit(1);
}

void	ft_init_struct(int argc, char **argv, char **env, t_pipe *str_pipex)
{
	str_pipex->ac = argc;
	str_pipex->av = argv;
	str_pipex->env = env;
}

void	ft_child_h_d(char **argv, int *fd_pipe)
{
	char	*term_str;
	char	*stop;

	close(fd_pipe[0]);
	stop = ft_strjoin(argv[2], "\n");
	write(0, "pipex here_doc> ", 16);
	term_str = get_next_line(0);
	while (term_str != NULL && ft_strncmp(term_str, stop, ft_strlen(stop)) != 0)
	{
		ft_putstr_fd(term_str, fd_pipe[1]);
		free(term_str);
		write(0, "pipex here_doc> ", 16);
		term_str = get_next_line(0);
	}
	if (term_str != NULL)
		free(term_str);
	free(stop);
	exit(0);
}

void	pipex_heredoc(char **argv)
{
	pid_t	pid1;
	int		fd_pipe[2];

	if (pipe(fd_pipe) == -1)
		ft_perror("Pipe error");
	pid1 = fork();
	if (pid1 == -1)
		ft_perror("Pipe error");
	if (pid1 == 0)
		ft_child_h_d(argv, fd_pipe);
	else
	{
		close(fd_pipe[1]);
		dup2(fd_pipe[0], 0);
		close(fd_pipe[0]);
		if (waitpid(pid1, NULL, 0) == -1)
			ft_perror("Error of terminated 1 child process");
	}
}
