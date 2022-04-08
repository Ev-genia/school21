/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:55:17 by mlarra            #+#    #+#             */
/*   Updated: 2022/03/09 15:47:20 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <stdlib.h>
# include <stdio.h>
# include "get_next_line.h"

typedef struct s_pipe
{
	int		ac;
	char	**av;
	char	**env;
}	t_pipe;

char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	pipex_heredoc(char **argv);
void	ft_execve(char **env, char *cmd);
void	ft_write(char *s);
void	ft_free(char **mas);
void	ft_perror(char *str);
size_t	ft_strlen(const char *s);
void	ft_putstr(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_init_struct(int argc, char **argv, char **env, t_pipe *str_pipex);

#endif