/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 12:40:06 by mlarra            #+#    #+#             */
/*   Updated: 2022/02/10 02:32:22 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_fill_stack(char **argv)
{
	int		i;
	int		j;
	t_list	*new;
	t_list	*stack;
	char	**words;

	i = 1;
	stack = NULL;
	while (argv[i])
	{
		words = ft_split(argv[i], ' ');
		j = 0;
		while (words[j])
		{
			new = ft_lstnew(my_atoi(words[j]));
			ft_lstadd_back(&stack, new);
			free(words[j]);
			j++;
		}
		free(words);
		i++;
	}
	return (stack);
}

int	ft_get_length(char **s)
{
	int		k;
	int		i;
	int		j;
	char	**wd;

	k = 0;
	i = 1;
	while (s[i])
	{
		j = 0;
		wd = ft_split((const char *)s[i], ' ');
		while (wd[j])
		{
			k++;
			free(wd[j]);
			j++;
		}
		free(wd);
		i++;
	}
	return (k);
}

void	ft_init_info(t_sort *info)
{
	int	i;

	i = 0;
	info->min = info->arr[i];
	info->max = info->arr[i];
	while (i < info->len_arr)
	{
		if (info->arr[i] < info->min)
			info->min = info->arr[i];
		if (info->arr[i] > info->max)
			info->max = info->arr[i];
		i++;
	}
	info->med = ft_get_med(info);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_sort	info;

	if (argc == 1)
		ft_exit_argc();
	ft_check_args(argv, &info);
	stack_a = ft_fill_stack(argv);
	stack_b = NULL;
	ft_init_info(&info);
	if (info.len_arr <= 3)
		ft_sort_three_elem(&stack_a, &info);
	else
		ft_sort_all(&stack_a, &stack_b, &info);
	ft_finish_sort(&stack_a, &info);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
// while (1) {};
}
