/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 12:40:06 by mlarra            #+#    #+#             */
/*   Updated: 2022/02/01 15:56:12 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

t_list	*ft_lstnew(int content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (new);
	new->val = content;
	new->next = NULL;
	return (new);
}

// void	ft_lstadd_front(t_list **lst, t_list *new)
// {
// 	new->next = *lst;
// 	*lst = new;
// }

void	ft_exit_argc(void)
{
	write(2, "./push-swap {ARG}\n", 18);
	exit(1);
}

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return ((t_list *)0);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*list;

	if (*lst)
	{
		list = ft_lstlast(*lst);
		list->next = new;
	}
	else
		*lst = new;
}

int	ft_check_symbol(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((s[i] < '0' || s[i] > '9') && s[i] != ' ' && s[i] != '+' && \
			s[i] != '-')
			return (1);
		i++;
	}
	return (0);
}

void	ft_lstdelone(t_list *lst)
{
	if (!lst)
		return ;
	free(lst);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*temp;
	t_list	*list;

	list = *lst;
	while (list)
	{
		temp = list->next;
		ft_lstdelone(list);
		list = temp;
	}
	*lst = NULL;
}

void	ft_exit_symbol(t_list *stack)
{
	ft_lstclear(&stack);
	write(2, "Error\n", 6);
// while (1) {};
	exit(1);
}

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
			new = ft_lstnew(ft_atoi(words[j]));
			ft_lstadd_back(&stack, new);
			free(words[j]);
			j++;
		}
		free(words);
		i++;
	}
	return (stack);
}

void	ft_exit_argv(void)
{
	write(2, "Error\n", 6);
// while (1) {};
	exit(1);
}

void	ft_exit_malloc(void)
{
	write(2, "Memory don't allocated\n", 23);
	exit(1);
}

void	ft_exit_arr(char **str, char ***words, int **ar_int)
{
	free(str);
	free(words);
	free(ar_int);
	ft_exit_argv();
}

int	*ft_fill_arr(int length, char **s)
{
	int		i;
	int		j;
	int		k;
	int		*ar;
	char	**wd;

	ar = (int *) malloc(sizeof(int) * length + 1);
	if (!ar)
		ft_exit_malloc();
	i = 0;
	k = 0;
	while (s[++i] && s[i] != NULL)
	{
		j = -1;
		wd = ft_split((const char *)s[i], ' ');
		while (wd[++j])
		{
			//add ckeck +0 -0
			// if (wd[j] == "+0")
			// 	ar[k] = ft_atoi(wd[j]);
			// else if (wd[j] == "-0")
			// 	ar[k] = ft_atoi(wd[j]);
			ar[k] = ft_atoi(wd[j]);
			if ((ft_strchr(wd[j], '+') || ft_strchr(wd[j], '-')) && ar[k] == 0)
			{
				//free malloc
				// free(wd[j]);
				// free(wd);
				// free(ar);
printf("text1\n");
				ft_exit_argv();
				// ft_exit_arr(&wd[j], &wd, &ar);
			}
// printf("*ar[%d]: %d\n", k, ar[k]);
			free(wd[j]);
			k++;
		}
		free(wd);
	}
	return (ar);
}

int	ft_check_double(int *mas, int length)
{
	int	i;
	int	j;

	i = 0;
	while (mas[i])
	{
		j = 1;
		while (mas[i + j] && j < length)
		{
			if (mas[i] == mas[i + j])
					return (1);
			j++;
		}
		i++;
	}
	return (0);
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

int	ft_check_sort(int *elem, int length)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (i < length - 1)
	{
		if (elem[i] < elem[i + 1])
				k++;
		i++;
	}
	if (k == i)
		return (0);
	return (1);
}

int	ft_check_min_max(int *arr, int len)
{
	int	i;

	i = 0;
	while (arr[i] && i < len)
	{
		if (arr[i] >= 2147483647 || arr[i] < -2147483648)
		{
			if ((unsigned int)arr[i] > 2147483647)
				return (1);
		}
		i++;
	}
	return (0);
}

int	ft_check_args(char **s, t_sort *inf)
{
	int	i;

	i = 1;
	while(s[i])
	{
		if (ft_check_symbol(s[i]) != 0)
			ft_exit_argv();
		i++;
	}
	inf->len_arr = ft_get_length(s);
	inf->arr = ft_fill_arr(inf->len_arr, s);
	if (ft_check_double(inf->arr, inf->len_arr) != 0)
		ft_exit_argv();
	if (ft_check_min_max(inf->arr, inf->len_arr) != 0)
		ft_exit_argv();
	if (ft_check_sort(inf->arr, inf->len_arr) == 0)
	{
		free(inf->arr);
		// ft_exit_sort();
// while (1) {};
// printf("sort\n");
		exit(0);
	}
	return (0);
}

void	swap_int(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	ft_get_med(t_sort *data)
{
	int	*sort_arr;
	int	i;
	int	j;

	sort_arr = malloc(sizeof(int) * data->len_arr);
	if (!sort_arr)
		ft_exit_malloc();
	i = -1;
	while (++i < data->len_arr)
		sort_arr[i] = data->arr[i];
	j = -1;
	while (++j < data->len_arr - 1)
	{
		i = 0;
		while (i < data->len_arr - 1)
		{
			if (sort_arr[i] > sort_arr[i + 1])
				swap_int(&sort_arr[i], &sort_arr[i + 1]);
			i++;
		}
	}
	data->med = sort_arr[data->len_arr / 2];
	free(sort_arr);
	return (data->med);
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

void	ft_sort_three_elem(t_list **list, t_sort inf)
{

// t_list	*stack_a_copy;
// printf("\ninput 3_elems:\n");
// stack_a_copy = *list;
// while (stack_a_copy)
// {
// 	printf("%d, ", stack_a_copy->val);
// 	stack_a_copy = stack_a_copy->next;
// }
// printf("\n");

	if (((*list)->val == inf.min && (*list)->next->val == inf.max) ||
		((*list)->val == inf.med && (*list)->next->val == inf.min) ||
		((*list)->val == inf.max && (*list)->next->val == inf.med))
		sa(list);
	else
		return ;

// stack_a_copy = *list;
// printf("\n3 elems:\n");
// while (stack_a_copy)
// {
// 	printf("%d, ", stack_a_copy->val);
// 	stack_a_copy = stack_a_copy->next;
// }
// printf("\n");

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

int	ft_get_a_r(t_list *a, t_list *b)
{
	int		i;

// t_list	*tmp;
// tmp = a;
// printf("\ninput get_a_r a:\n");
// while (tmp)
// {
// 	printf("%d, ", tmp->val);
// 	tmp = tmp->next;
// }
// printf("\n");
// tmp = b;
// printf("\ninput get_a_r b:\n");
// while (tmp)
// {
// 	printf("%d, ", tmp->val);
// 	tmp = tmp->next;
// }
// printf("\n");

	i = 0;
	while (a)
	{
		if ((a->val > b->val) && (ft_lstlast(a)->val < b->val))
			return (i);
		a = a->next;
		i++;
	}
	return (i);
}

// int	ft_get_b_r(t_list *a, t_list *b)
// {
// 	int		i;

// 	i = 0;
// 	while (b)
// 	{
// 		if ((b->val < a->val) && (ft_lstlast(a)->val < b->val))
// 			return (i);
// 		b = b->next;
// 		i++;
// 	}
// 	return (i);
// }

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

int	ft_get_min_score(t_list elem)
{
	if (elem.score_a_r < elem.score_a_rr)
	{
		if (elem.score_b_r < elem.score_b_rr)
			elem.min_score = elem.score_a_r + elem.score_b_r;
		else
			elem.min_score = elem.score_a_r + elem.score_b_rr;
	}
	else
	{
		if (elem.score_b_r < elem.score_b_rr)
			elem.min_score = elem.score_a_rr + elem.score_b_r;
		else
			elem.min_score = elem.score_a_rr + elem.score_b_rr;
	}
	return (elem.min_score);
}

int	ft_find_min(t_list *stack)
{
	int	min;

	min = stack->min_score;
	while (stack)
	{
		if (stack->min_score < min)
			min = stack->min_score;
		stack = stack->next;
	}
	return (min);
}

void	ft_sort_all(t_list **a, t_list **b, t_sort data)
{
	int		i;
	int		min;
	t_list	*b_begin;

// t_list	*tmp;
// tmp = *a;
// printf("\ninput ft_sort_all a:\n");
// while (tmp)
// {
// 	printf("%d, ", tmp->val);
// 	tmp = tmp->next;
// }
// printf("\n");
// tmp = *b;
// printf("\ninput ft_sort_all b:\n");
// printf("%p\n", tmp);
// while (tmp)
// {
// 	printf("%d, %p", tmp->val, tmp->next);
// 	tmp = tmp->next;
// }
// printf("\n");

	i = 0;
	while ((*a)->next != NULL && i < data.len_arr)
	{
// printf("(*a)->val: %d\n", (*a)->val);
		if ((*a)->val == data.min || (*a)->val == data.med || (*a)->val == data.max)
		{
			ra(a);
			// data.len_arr--;
		}
		else
			pb(a, b);
		i++;
	}

// tmp = *a;
// printf("\noutput ft_sort_all a:\n");
// while (tmp)
// {
// 	printf("%d, ", tmp->val);
// 	tmp = tmp->next;
// }
// printf("\n");

// tmp = *b;
// printf("\noutput ft_sort_all b:\n");
// while (tmp)
// {
// 	printf("%d, ", tmp->val);
// 	tmp = tmp->next;
// }

	ft_sort_three_elem(a, data);

// tmp = *b;
// printf("\noutput ft_sort_all b:\n");
// while (tmp)
// {
// 	printf("%d, ", tmp->val);
// 	tmp = tmp->next;
// }
// printf("\n");

	b_begin = *b;
	while (*b)
	{

// tmp = *b;
// printf("\nwhile ft_sort_all b:\n");
// while (tmp)
// {
// 	printf("%d, ", tmp->val);
// 	tmp = tmp->next;
// }
// printf("\n");

		(*b)->score_a_r = ft_get_a_r(*a, *b);
		(*b)->score_a_rr = ft_lstsize(*a) - (*b)->score_a_r;

// tmp = *a;
// printf("\nstack a:\n");
// while (tmp)
// {
// 	printf("%d, ", tmp->val);
// 	tmp = tmp->next;
// }

// tmp = *b;
// printf("\nstack b:\n");
// while (tmp)
// {
// 	printf("%d, ", tmp->val);
// 	tmp = tmp->next;
// }
// printf("\n");

// printf("val: %d, score_a_r: %d, score_a_rr: %d\n", (*b)->val, (*b)->score_a_r, (*b)->score_a_rr);

		// (*b)->score_b_r = ft_get_b_r(*a, *b);
		(*b)->score_b_r = ft_get_b_r(b_begin, (*b)->val);
		// (*b)->score_b_rr = ft_lstsize(*b) - (*b)->score_b_r;
		(*b)->score_b_rr = ft_lstsize(b_begin) - (*b)->score_b_r;

// printf("score_b_r: %d, score_b_rr: %d\n", (*b)->score_b_r, (*b)->score_b_rr);

		(*b) = (*b)->next;
	}
	(*b) = b_begin;

// tmp = *b;
// printf("\nbetween while ft_sort_all b:\n");
// while (tmp)
// {
// 	printf("%d, ", tmp->val);
// 	tmp = tmp->next;
// }
// printf("\n");
	
	while(*b)
	{

// tmp = *b;
// printf("\ninsile while ft_sort_all b:\n");
// while (tmp)
// {
// 	printf("%d, ", tmp->val);
// 	tmp = tmp->next;
// }
// printf("\n");
	

		// (*b) = b_begin;
		while (*b)
		{

// tmp = *b;
// printf("\ninsile whilewhile ft_sort_all b:\n");
// while (tmp)
// {
// 	printf("%d, ", tmp->val);
// 	tmp = tmp->next;
// }
// printf("\n");

// tmp = *a;
// printf("\ninsile whilewhile ft_sort_all a:\n");
// while (tmp)
// {
// 	printf("%d, ", tmp->val);
// 	tmp = tmp->next;
// }
// printf("\n");	

			(*b)->min_score = ft_get_min_score(**b);
// printf("min score: %d\n", (*b)->min_score);
			(*b) = (*b)->next;
		}
		(*b) = b_begin;

// tmp = *b;
// printf("\nbetw 2 while ft_sort_all b:\n");
// while (tmp)
// {
// 	printf("%d, ", tmp->val);
// 	tmp = tmp->next;
// }
// printf("\n");

		min = ft_find_min(*b);
// printf("min: %d\n", min);

// printf("b_begin->val: %d\n", b_begin->val);
		// (*b) = b_begin;
		while ((*b)->min_score != min)
		{
			(*b) = (*b)->next;
			// b_begin = (*b);
		}
		b_begin = (*b)->next;

// printf("b_begin->next->val: %d\n", b_begin->val);
// tmp = b_begin;
// printf("\nb_begin:\n");
// while (tmp)
// {
// 	printf("%d, ", tmp->val);
// 	tmp = tmp->next;
// }
// printf("\n");

		if ((*b)->min_score == 0)
			pa(b, a);
		// else
		// {

		// }
		(*b) = b_begin;

// tmp = *b;
// printf("\nafter while ft_sort_all b:\n");
// while (tmp)
// {
// 	printf("%d, ", tmp->val);
// 	tmp = tmp->next;
// }
// printf("\n");

	}


// tmp = *b;
// printf("\noutput ft_sort_all b:\n");
// while (tmp)
// {
// 	printf("%d, ", tmp->val);
// 	tmp = tmp->next;
// }
// printf("\n");



// printf("\n");
}

int	ft_finish_score_ra(t_list *a, int min)
{
	int	i;

// t_list	*tmp;
// tmp = a;
// printf("\ninput get_score_ra:\n");
// while (tmp != NULL)
// {
	// printf("%d, ", tmp->val);
	// tmp = tmp->next;
// }
// printf("\n");

	i = 0;
	while (a->val != min)
	{
		a = a->next;
		i++;
	}
// printf("i: %d\n", i);
	return (i);
}

void	ft_finish_sort(t_list **a, t_sort data)
{
	int	score_ra;
	int	score_rra;
	t_list	*a_copy;

// t_list	*tmp;
// tmp = *a;
// printf("\ninput finish sort a:\n");
// while (tmp)
// {
// 	printf("%d, ", tmp->val);
// 	tmp = tmp->next;
// }
// printf("\n");

// tmp = *a;
// printf("\n1meedle finish sort a:\n");
// while (tmp)
// {
// 	printf("%d, ", tmp->val);
// 	tmp = tmp->next;
// }
// printf("\n");

	score_ra = ft_finish_score_ra(*a, data.min);

// printf("score_ra: %d\n", score_ra);

// tmp = *a;
// printf("\n2meedle finish sort a:\n");
// while (tmp)
// {
// 	printf("%d, ", tmp->val);
// 	tmp = tmp->next;
// }
// printf("\n");

	a_copy = *a;
	score_rra = ft_lstsize(a_copy) - score_ra;
// printf("score_rra: %d\n", score_rra);
	if (score_ra < score_rra)
	{
		while ((*a)->val != data.min && score_ra > 0)
		{
// printf("(*a)->val: %d\n", (*a)->val);
			ra(a);
			score_ra--;
		}
	}
	else
	{
		while ((*a)->val != data.min && score_rra > 0)
		{
			rra(a);
			score_rra--;
		}
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_sort	info;

t_list	*stack_a_copy;

	if (argc == 1)
		ft_exit_argc();
	ft_check_args(argv, &info);
	stack_a = ft_fill_stack(argv);

// stack_a_copy = stack_a;
// printf("\nstack_a sort:\n");
// while (stack_a_copy)
// {
// 	printf("%d, ", stack_a_copy->val);
// 	stack_a_copy = stack_a_copy->next;
// }
// printf("\n");

	stack_b = NULL;
	ft_init_info(&info);
printf("len: %d, min:, %d, med: %d, max: %d\n", info.len_arr, info.min, info.med, info.max);
	if (info.len_arr <= 3)
		ft_sort_three_elem(&stack_a, info);
	else
		ft_sort_all(&stack_a, &stack_b, info);


stack_a_copy = stack_a;
printf("\nstack_a meedle main:\n");
while (stack_a_copy)
{
	printf("%d, ", stack_a_copy->val);
	stack_a_copy = stack_a_copy->next;
}
printf("\n");
printf("--\n");

	ft_finish_sort(&stack_a, info);

stack_a_copy = stack_a;
printf("\nstack_a end main:\n");
while (stack_a_copy)
{
	printf("%d, ", stack_a_copy->val);
	stack_a_copy = stack_a_copy->next;
}
printf("\n");

printf("\nstack_b end main:\n");
while (stack_b)
{
	printf("%d, ", stack_b->val);
	stack_b = stack_b->next;
}
printf("\n");

	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);

// while (1) {};
}