/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:54:53 by mlarra            #+#    #+#             */
/*   Updated: 2022/03/09 17:20:03 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_first_child(char **argv, int *fd_pipe, char **env)
{
	int	fd_in;

	fd_in = open(argv[1], O_RDONLY, 0644);
	if (fd_in == -1)
	{
		close(fd_pipe[0]);
		close(fd_pipe[1]);
		ft_perror(argv[1]);
	}
	if (dup2(fd_in, 0) == -1 || dup2(fd_pipe[1], 1) == -1)
	{
		close(fd_pipe[0]);
		close(fd_pipe[1]);
		ft_perror("Can not create copy of descriptor1");
	}
	close(fd_pipe[0]);
	close(fd_in);
	close(fd_pipe[1]);
	ft_execve(env, argv[2]);
}

void	ft_second_child(int ac, char **argv, int *fd_pipe, char **env)
{
	int	fd_out;

	fd_out = open(argv[ac - 1], O_WRONLY + O_TRUNC + O_CREAT, 0644);
	if (fd_out == -1)
	{
		close(fd_pipe[0]);
		close(fd_pipe[1]);
		ft_perror(argv[ac - 1]);
	}
	if (dup2(fd_out, 1) == -1 || dup2(fd_pipe[0], 0) == -1)
	{
		close(fd_pipe[0]);
		close(fd_pipe[1]);
		ft_perror("Can not create copy of descriptor2");
	}
	close(fd_pipe[1]);
	close(fd_out);
	close(fd_pipe[0]);
	ft_execve(env, argv[ac - 2]);
}

void	pipex(int argc, char **argv, char **env)
{
	pid_t	pid1;
	pid_t	pid2;
	int		fd_pipe[2];

	if (pipe(fd_pipe) == -1)
		ft_perror("Pipe failed");
	pid1 = fork();
	if (pid1 == -1)
		ft_perror("Pipe failed");
	if (pid1 == 0)
		ft_first_child(argv, fd_pipe, env);
	pid2 = fork();
	if (pid2 == -1)
		ft_perror("Pipe failed");
	if (pid2 == 0)
		ft_second_child(argc, argv, fd_pipe, env);
	close(fd_pipe[0]);
	close(fd_pipe[1]);
	if (waitpid(pid1, NULL, 0) == -1)
		ft_perror("Error of terminated 1 child process");
	if (waitpid(pid2, NULL, 0) == -1)
		ft_perror("Error of terminated 2 child process");
}

int	main(int argc, char **argv, char **env)
{
	if (argc != 5)
	{
		write(2, "Error numbers of arguments\n", 27);
		return (1);
	}
	if (env == 0)
		ft_perror("env error");
	pipex(argc, argv, env);
	return (0);
}
