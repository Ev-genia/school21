/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:08:50 by mlarra            #+#    #+#             */
/*   Updated: 2022/02/09 15:08:54 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **l)
{
	t_list	*temp;
	t_list	*last;

	if (!(*l) || !(*l)->next)
		return ;
	last = ft_lstlast(*l);
	temp = *l;
	*l = (*l)->next;
	last->next = temp;
	temp->next = NULL;
}

void	ra(t_list **s_a)
{
	rotate(s_a);
	write(1, "ra\n", 3);
}

void	rb(t_list **s_b)
{
	rotate(s_b);
	write(1, "rb\n", 3);
}

void	rr(t_list **s_a, t_list **s_b)
{
	rotate(s_a);
	rotate(s_b);
	write(1, "rr\n", 3);
}