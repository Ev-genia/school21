/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 01:38:30 by mlarra            #+#    #+#             */
/*   Updated: 2022/02/10 01:43:59 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_find_local_min(t_list *tmp, t_sort *data)
{
	data->min = tmp->val;
	data->max = tmp->val;
	while (tmp)
	{
		if (tmp->val < (data->min))
			data->min = tmp->val;
		if (tmp->val > (data->max))
			data->max = tmp->val;
		tmp = tmp->next;
	}
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

int	ft_get_b_r(t_list *lst, int nbr)
{
	int	i;

	i = 0;
	while (lst->val != nbr)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

int	ft_get_a_r(t_list *lst, int nbr, t_sort *data)
{
	int	i;

	i = 0;
	ft_find_local_min(lst, data);
	if (nbr < data->min || nbr > data->max)
		return (ft_get_b_r(lst, data->min));
	if (lst->val > nbr && ft_lstlast(lst)->val < nbr)
		return (i);
	while (lst->next != NULL)
	{
		if (lst->val < nbr && lst->next->val > nbr)
			return (++i);
		lst = lst->next;
		i++;
	}
	return (i);
}

void	ft_score_init(t_list *a, t_list *b, t_sort *data)
{
	t_list	*b_begin;
	int		min;

	b_begin = b;
	while (b)
	{
		b->score_a_r = ft_get_a_r(a, b->val, data);
		b->score_a_rr = ft_lstsize(a) - b->score_a_r;
		if (b->score_a_r < b->score_a_rr)
			min = b->score_a_r;
		else
			min = b->score_a_rr;
		b->score_b_r = ft_get_b_r(b_begin, b->val);
		b->score_b_rr = ft_lstsize(b_begin) - b->score_b_r;
		if (b->score_b_r < b->score_b_rr)
			b->min_score = min + b->score_b_r;
		else
			b->min_score = min + b->score_b_rr;
		(b) = (b)->next;
	}
}
