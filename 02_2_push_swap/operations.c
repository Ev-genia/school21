/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:11:51 by mlarra            #+#    #+#             */
/*   Updated: 2022/02/07 11:29:12 by mlarra           ###   ########.fr       */
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

void	push(t_list **a, t_list **b)
{
	t_list	*temp;

	if (*a)
	{
		temp = *a;
		*a = (*a)->next;
		// if (*b)
			temp->next = *b;
		// else
			// temp->next = NULL;
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


void	rotate(t_list **l)
{
	t_list	*temp;
	t_list	*last;

// t_list	*tmp;
// tmp = *l;
// printf("\ninput rotate:\n");
// while (tmp)
// {
// 	printf("%d, ", tmp->val);
// 	tmp = tmp->next;
// }
// printf("\n");

	if (!(*l) || !(*l)->next)
		return ;
	last = ft_lstlast(*l);
	temp = *l;
	*l = (*l)->next;
	last->next = temp;
	temp->next = NULL;
	
	// temp = (*l)->next;
	// last = ft_lstlast(*l);
	// last->next = *l;
	// (*l)->next = NULL;
	// l = &temp;

// tmp = *l;
// printf("\noutput rotate:\n");
// while (tmp)
// {
// 	printf("%d, ", tmp->val);
// 	tmp = tmp->next;
// }
// printf("\n");

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

// void	rra(t_list **a)
// {
// 	t_list	*last_prev;

// 	if (!*a || !(*a)->next)
// 		return ;
// 	last_prev = *a;
// 	while (last_prev->next->next)
// 		last_prev = last_prev->next;
// 	last_prev->next->next = *a;
// 	*a = last_prev->next;
// 	last_prev->next = 0;
// 	write(1, "rra\n", 4);
// }

void	reverse(t_list **l)
{
	t_list	*temp;
	t_list		*last;
	// t_list	*last_prev;

	if (!(*l) || !(*l)->next)
		return ;
	// last_prev = *l;
	// while (last_prev->next->next != NULL)
	// 	last_prev = last_prev->next;
	// last_prev->next->next = *l;
	// *l = last_prev->next;
	// last_prev->next = 0;

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
