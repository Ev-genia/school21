/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 01:06:05 by mlarra            #+#    #+#             */
/*   Updated: 2022/02/10 02:31:49 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_symbol(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((s[i] < '0' || s[i] > '9') && s[i] != ' ' && s[i] != '+' && s[i] != '-')
			ft_exit_argv();
		i++;
	}
	return (0);
}

int	ft_check_sort(int *elem, int length)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (i < length - 1)
	{
		if (elem[i] < elem[i + 1])
				k++;
		i++;
	}
	if (k == i)
		return (0);
	return (1);
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
	while(s[++i])
		ft_check_symbol(s[i]);
	inf->len_arr = ft_get_length(s);
	inf->arr = ft_fill_arr(inf->len_arr, s);
	if (ft_check_double(inf->arr, inf->len_arr) != 0)
	{
		free(inf->arr);
		ft_exit_argv();
	}
	if (ft_check_sort(inf->arr, inf->len_arr) == 0)
	{
		free(inf->arr);
		exit(0);
	}
	return (0);
}
