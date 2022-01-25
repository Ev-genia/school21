/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 12:40:06 by mlarra            #+#    #+#             */
/*   Updated: 2022/01/24 19:14:13 by mlarra           ###   ########.fr       */
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

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

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
		if ((s[i] < '0' || s[i] > '9') && s[i] != ' ')
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

void	ft_exit_symbol(t_list *stak)
{
	ft_lstclear(&stak);
	write(2, "Error\n", 6);
// while (1) {};
	exit(1);
}

t_list	*ft_fill_stak(char **argv)
{
	int		i;
	int		j;
	t_list	*new;
	t_list	*stak;
	char	**words;

	i = 1;
	stak = NULL;
	while (argv[i])
	{
		words = ft_split(argv[i], ' ');
		j = 0;
		while (words[j])
		{
			new = ft_lstnew(ft_atoi(words[j]));
			ft_lstadd_back(&stak, new);
			free(words[j]);
			j++;
		}
		free(words);
		i++;
	}
	return (stak);
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
			ar[k] = ft_atoi(wd[j]);
// printf("*ar[%d]: %d\n", k, ar[k]);
			free(wd[j]);
			k++;
		}
		free(wd);
	}
	return (ar);
}

int	ft_check_double(int *mas)
{
	int	i;
	int	j;

	i = 0;
	while (mas[i])
	{
		j = 0;
		while (mas[i + j])
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

int	ft_check_args(char **s)
{
	int	i;
	int	len;
	int	*arr;

	i = 1;
	while(s[i])
	{
		if (ft_check_symbol(s[i]) != 0)
			ft_exit_argv();
		i++;
	}
	len = ft_get_length(s);
	arr = ft_fill_arr(len, s);

	if (!ft_check_double(arr))
		ft_exit_argv();
	// if (!ft_check_sort(arr))
	// 	ft_exit_sort();
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	*stak_a;

	if (argc == 1)
		ft_exit_argc();
// printf("ft_check_args(argv): %d\n", ft_check_args(argv));
	ft_check_args(argv);
	stak_a = ft_fill_stak(argv);
	
}