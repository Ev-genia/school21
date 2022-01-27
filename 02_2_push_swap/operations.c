/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:11:51 by mlarra            #+#    #+#             */
/*   Updated: 2022/01/26 16:20:45 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

void	swap(t_list **l)
{
	t_list	*temp;

	temp = (*l)->next;
	(*l)->next = (*l)->next->next;
	temp->next = (*l);
	(*l) = temp;
}

void	push(t_list **a, t_list **b)
{
	t_list	*temp;

	temp = *a;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
}

void	rotate(t_list **l)
{
	t_list	*temp;
	t_list	*last;

	temp = (*l)->next;
	last = ft_lstlast(*l);
	last->next = *l;
	(*l)->next = NULL;
	(*l) = temp;
}

void	reverse(t_list **l)
{
	t_list	*temp;
	t_list	*last;

	temp = *l;
	last = ft_lstlast(*l);
	while ((*l)->next->next != NULL)
		(*l) = (*l)->next;
	(*l)->next = NULL;
	last->next = temp;
	(*l) = last;
}