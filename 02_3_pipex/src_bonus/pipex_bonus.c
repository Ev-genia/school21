/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:54:53 by mlarra            #+#    #+#             */
/*   Updated: 2022/03/09 12:26:27 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_open_outfile(int ac, char **av)
{
	int	fd;

	if (ft_strncmp(av[1], "here_doc", 8) == 0)
		fd = open(av[ac - 1], O_WRONLY + O_APPEND + O_CREAT, 0644);
	else
		fd = open(av[ac - 1], O_WRONLY + O_TRUNC + O_CREAT, 0644);
	return (fd);
}

void	ft_first_child(int i, int *fd_pipe, t_pipe pipe_str)
{
	int	fd_in;

	close(fd_pipe[0]);
	if (i == pipe_str.ac - 2)
		exit(1);
	if (i == 2)
	{
		fd_in = open(pipe_str.av[1], O_RDONLY, 0644);
		if (fd_in == -1)
		{
			close(fd_pipe[1]);
			ft_perror(pipe_str.av[1]);
		}
		if (dup2(fd_in, STDIN_FILENO) == -1)
		{
			close(fd_pipe[1]);
			ft_perror("Can not create copy of descriptor1");
		}
	}
	dup2(fd_pipe[1], 1);
	close(fd_pipe[1]);
	ft_execve(pipe_str.env, pipe_str.av[i]);
}

void	ft_parent_proc(int i, int *fd_pipe, int pid, t_pipe pipe_str)
{
	int	fd_out;

	close(fd_pipe[1]);
	if (i == pipe_str.ac - 2)
	{
		waitpid(pid, NULL, 0);
		fd_out = ft_open_outfile(pipe_str.ac, pipe_str.av);
		if (fd_out == -1)
		{
			close(fd_pipe[0]);
			ft_perror(pipe_str.av[pipe_str.ac - 1]);
		}
		if (dup2(fd_out, STDOUT_FILENO) == -1)
		{
			close(fd_pipe[0]);
			ft_perror("Can not create copy of descriptor2");
		}
		close(fd_out);
		close(fd_pipe[0]);
		ft_execve(pipe_str.env, pipe_str.av[pipe_str.ac - 2]);
	}
	dup2(fd_pipe[0], 0);
	close(fd_pipe[0]);
}

void	pipex(t_pipe pipe_struct, int num)
{
	pid_t	pid1;
	int		fd_pipe[2];

	if (pipe(fd_pipe) == -1)
		ft_perror("Pipe failed");
	pid1 = fork();
	if (pid1 == -1)
		ft_perror("Pipe failed");
	if (pid1 == 0)
		ft_first_child(num, fd_pipe, pipe_struct);
	else
		ft_parent_proc(num, fd_pipe, pid1, pipe_struct);
}

int	main(int argc, char **argv, char **env)
{
	int		i;
	t_pipe	str_pipex;

	if (argc >= 5)
	{
		if (argc >= 6 && ft_strncmp(argv[1], "here_doc", 8) == 0)
		{
			pipex_heredoc(argv);
			i = 3;
		}
		else
			i = 2;
		ft_init_struct(argc, argv, env, &str_pipex);
		while (i < argc - 1)
		{
			pipex(str_pipex, i);
			i++;
		}
	}
	else
	{
		write(2, "Too few arguments\n", 18);
		return (1);
	}
	return (0);
}
