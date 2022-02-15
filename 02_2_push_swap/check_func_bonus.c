/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_func_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 01:06:05 by mlarra            #+#    #+#             */
/*   Updated: 2022/02/15 12:58:28 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_check_symbol(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((s[i] < '0' || s[i] > '9') && s[i] != ' ' && s[i] != '+'
			&& s[i] != '-')
			ft_exit_argv();
		i++;
	}
	return (0);
}

int	*ft_fill_arr(int length, char **s)
{
	int		i;
	int		j;
	int		k;
	int		*ar;
	char	**wd;

	ar = (int *) malloc(sizeof(int) * length + 1);
	if (!ar)
		ft_exit_malloc();
	i = 0;
	k = -1;
	while (s[++i] && s[i] != NULL)
	{
		j = -1;
		wd = ft_split((const char *)s[i], ' ');
		while (wd[++j])
		{
			ar[++k] = my_atoi(wd[j]);
			free(wd[j]);
		}
		free(wd);
	}
	return (ar);
}

int	ft_check_double(int *mas, int length)
{
	int	i;
	int	j;

	i = 0;
	while (mas[i])
	{
		j = 1;
		while (mas[i + j] && j < length)
		{
			if (mas[i] == mas[i + j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_args(char **s, t_sort *inf)
{
	int	i;

	i = 0;
	while (s[++i])
		ft_check_symbol(s[i]);
	inf->len_arr = ft_get_length(s);
	inf->arr = ft_fill_arr(inf->len_arr, s);
	if (ft_check_double(inf->arr, inf->len_arr) != 0)
	{
		free(inf->arr);
		ft_exit_argv();
	}
	return (0);
}
