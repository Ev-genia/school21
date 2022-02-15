/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 01:43:42 by mlarra            #+#    #+#             */
/*   Updated: 2022/02/15 11:58:47 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_int(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	ft_get_med(t_sort *data)
{
	int	i;
	int	j;

	j = -1;
	while (++j < data->len_arr)
	{
		i = 0;
		while (i < data->len_arr - 1)
		{
			if (data->arr[i] > data->arr[i + 1])
				swap_int(&data->arr[i], &data->arr[i + 1]);
			i++;
		}
	}
	data->med = data->arr[(data->len_arr - 1) / 2];
	free(data->arr);
	return (data->med);
}

void	ft_func_rotate(int count, t_list **a, void (func)(t_list **))
{
	while (count > 0)
	{
		func(a);
		count--;
	}
}

void	ft_func_rotate2(int count, t_list **a, t_list **b,
	void (func2)(t_list **, t_list **))
{
	while (count > 0)
	{
		func2(a, b);
		count--;
	}
}

t_list	*ft_find_min(t_list *stack)
{
	t_list	*min;

	min = stack;
	while (stack->next)
	{
		if (min->min_score > stack->next->min_score)
			min = stack->next;
		stack = stack->next;
	}
	return (min);
}
