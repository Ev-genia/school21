/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:02:01 by mlarra            #+#    #+#             */
/*   Updated: 2022/02/09 15:02:17 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **l)
{
	t_list	*temp;

	temp = (*l)->next;
	(*l)->next = (*l)->next->next;
	temp->next = (*l);
	(*l) = temp;
}

void	sa(t_list **s_a)
{
	swap(s_a);
	write(1, "sa\n", 3);
}

void	sb(t_list **s_b)
{
	swap(s_b);
	write(1, "sb\n", 3);
}

void	ss(t_list **s_a, t_list **s_b)
{
	swap(s_a);
	swap(s_b);
	write(1, "ss\n", 3);
}
