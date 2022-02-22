/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotates_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:00:00 by mlarra            #+#    #+#             */
/*   Updated: 2022/02/22 10:25:51 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

void	rr(t_list **s_a, t_list **s_b)
{
	rotate(s_a);
	rotate(s_b);
}

void	reverse(t_list **l)
{
	t_list	*temp;
	t_list	*last;

	if (!(*l) || !(*l)->next)
		return ;
	temp = *l;
	last = ft_lstlast(*l);
	while ((*l)->next->next != NULL)
		(*l) = (*l)->next;
	(*l)->next = NULL;
	last->next = temp;
	(*l) = last;
}

void	rrr(t_list **s_a, t_list **s_b)
{
	reverse(s_a);
	reverse(s_b);
}
