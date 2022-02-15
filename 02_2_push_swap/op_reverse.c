/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:11:51 by mlarra            #+#    #+#             */
/*   Updated: 2022/02/15 11:35:47 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	rra(t_list **s_a)
{
	reverse(s_a);
	write(1, "rra\n", 4);
}

void	rrb(t_list **s_b)
{
	reverse(s_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_list **s_a, t_list **s_b)
{
	reverse(s_a);
	reverse(s_b);
	write(1, "rrr\n", 4);
}
