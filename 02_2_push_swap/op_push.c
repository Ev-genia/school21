/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:04:32 by mlarra            #+#    #+#             */
/*   Updated: 2022/02/18 14:59:56 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **a, t_list **b)
{
	t_list	*temp;

	if (*a)
	{
		temp = *a;
		*a = (*a)->next;
		temp->next = *b;
		*b = temp;
	}
}

void	pa(t_list **s_b, t_list **s_a)
{
	push(s_b, s_a);
	write(1, "pa\n", 3);
}

void	pb(t_list **s_a, t_list **s_b)
{
	push(s_a, s_b);
	write(1, "pb\n", 3);
}
