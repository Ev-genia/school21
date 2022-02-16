/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:52:03 by mlarra            #+#    #+#             */
/*   Updated: 2022/02/16 10:42:06 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n < 1)
		return (0);
	while (n > 1 && *s1 != '\0' && *s2 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
		n--;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

void	ft_commands(const char *s, t_list **a_begin, t_list **b_begin)
{
	if (ft_strncmp(s, "sa", 3) == 0)
		swap(a_begin);
	else if (ft_strncmp(s, "sb", 3) == 0)
		swap(b_begin);
	else if (ft_strncmp(s, "ss", 3) == 0)
		ss(a_begin, b_begin);
	else if (ft_strncmp(s, "pa", 3) == 0)
		push(b_begin, a_begin);
	else if (ft_strncmp(s, "pb", 3) == 0)
		push(a_begin, b_begin);
	else if (ft_strncmp(s, "ra", 3) == 0)
		rotate(a_begin);
	else if (ft_strncmp(s, "rb", 3) == 0)
		rotate(b_begin);
	else if (ft_strncmp(s, "rr", 3) == 0)
		rr(a_begin, b_begin);
	else if (ft_strncmp(s, "rra", 4) == 0)
		reverse(a_begin);
	else if (ft_strncmp(s, "rrb", 4) == 0)
		reverse(b_begin);
	else if (ft_strncmp(s, "rrr", 4) == 0)
		rrr(a_begin, b_begin);
	else
		ft_exit_error((char *)s);
}

int	ft_check_sort_list(t_list *lst, t_list *b)
{
	if (b)
		return (1);
	while (lst && lst->next)
	{
		if (lst->val < lst->next->val)
			lst = lst->next;
		else
			return (1);
	}
	return (0);
}

void	ft_main_checker(t_list **a, t_list **b)
{
	char	*str;

	while (get_next_line(&str))
	{
		ft_commands((const char *)str, a, b);
		free(str);
	}
	if (ft_check_sort_list(*a, *b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_sort	info;

	if (argc > 1)
	{
		ft_check_args(argv, &info);
		stack_a = ft_fill_stack(argv);
		stack_b = NULL;
		ft_main_checker(&stack_a, &stack_b);
		ft_lstclear(&stack_a);
	}
	return (0);
}
