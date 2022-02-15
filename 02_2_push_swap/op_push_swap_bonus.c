/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push_swap_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:51:41 by mlarra            #+#    #+#             */
/*   Updated: 2022/02/14 16:00:34 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	swap(t_list **l)
{
	t_list	*temp;

	temp = (*l)->next;
	(*l)->next = (*l)->next->next;
	temp->next = (*l);
	(*l) = temp;
}

void	ss(t_list **s_a, t_list **s_b)
{
	swap(s_a);
	swap(s_b);
}

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
