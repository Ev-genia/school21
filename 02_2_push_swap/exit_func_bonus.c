/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_func_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:39:00 by mlarra            #+#    #+#             */
/*   Updated: 2022/02/14 13:23:53 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_exit_argc(void)
{
	// write(2, "./push-swap {ARG}\n", 18);
	exit(1);
}

void	ft_exit_symbol(t_list *stack)
{
	ft_lstclear(&stack);
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_exit_argv(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_exit_malloc(void)
{
	write(2, "Memory don't allocated\n", 23);
	exit(1);
}

void	ft_exit_arr(char **str, char ***words, int **ar_int)
{
	free(str);
	free(words);
	free(ar_int);
	ft_exit_argv();
}
