/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 01:27:31 by mlarra            #+#    #+#             */
/*   Updated: 2022/02/15 10:18:41 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three_elem(t_list **list, t_sort *inf)
{
	int	meedle;
	t_list	*tmp;

	tmp = *list;
	meedle = (*list)->val;
	ft_find_local_min(*list, inf);
	while (tmp)
	{
		if (tmp->val != inf->min && tmp->val != inf->max)
			meedle = tmp->val;
		tmp = tmp->next;
	}
	if (((*list)->val == inf->min && (*list)->next->val == inf->max) ||
		((*list)->val == meedle && (*list)->next->val == inf->min) ||
		((*list)->val == inf->max && (*list)->next->val == meedle))
		sa(list);
	else
		return ;
}

void	ft_if_yes(t_list *min, t_list **a_begin, t_list **b_begin)
{
	if (min->score_b_r <= min->score_b_rr)
	{
		if (min->score_a_r >= min->score_b_r)
		{
			ft_func_rotate2(min->score_b_r, a_begin, b_begin, rr);
			ft_func_rotate(min->score_a_r - min->score_b_r, a_begin, ra);
		}
		else
		{
			ft_func_rotate2(min->score_a_r, a_begin, b_begin, rr);
			ft_func_rotate(min->score_b_r - min->score_a_r, b_begin, rb);
		}
	}
	else
	{
		ft_func_rotate(min->score_a_r, a_begin, ra);
		ft_func_rotate(min->score_b_rr, b_begin, rrb);
	}
}

void	ft_if_no(t_list *min, t_list **a_begin, t_list **b_begin)
{
	if (min->score_b_r <= min->score_b_rr)
	{
		ft_func_rotate(min->score_a_rr, a_begin, rra);
		ft_func_rotate(min->score_b_r, b_begin, rb);
	}
	else
	{
		if (min->score_a_rr >= min->score_b_rr)
		{
			ft_func_rotate2(min->score_b_rr, a_begin, b_begin, rrr);
			ft_func_rotate(min->score_a_rr - min->score_b_rr, a_begin, rra);
		}
		else
		{
			ft_func_rotate2(min->score_a_rr, a_begin, b_begin, rrr);
			ft_func_rotate(min->score_b_rr - min->score_a_rr, b_begin, rrb);
		}
	}
}

void	ft_sort_all(t_list **a, t_list **b, t_sort *data)
{
	int		i;
	t_list	*min;

	i = data->len_arr;
	while (i > 3)
	{
		pb(a, b);
		if ((*b)->val > data->med && ft_lstsize(*b) > 2)
			rb(b);
		i--;
	}
	ft_sort_three_elem(a, data);
	while(*b)
	{
		ft_score_init(*a, *b, data);
		min = ft_find_min(*b);
		if (min->score_a_r <= min->score_a_rr)
			ft_if_yes(min, a, b);
		else
			ft_if_no(min, a, b);
		pa(b, a);
	}
}

void	ft_finish_sort(t_list **a, t_sort *data)
{
	int	score_ra;
	int	score_rra;

	ft_find_local_min(*a, data);
	score_ra = ft_get_b_r(*a, data->min);
	score_rra = ft_lstsize(*a) - score_ra;
	while (*a && (*a)->val != data->min)
	{
		if (score_ra < score_rra)
			ra(a);
		else
			rra(a);
	}
}
