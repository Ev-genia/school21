/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push-swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 12:40:06 by mlarra            #+#    #+#             */
/*   Updated: 2022/01/20 17:43:31 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push-swap.h"

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
		if (s[i] < '0' || s[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

void	ft_exit_symbol(void)
{
	//clear malloc
	write(2, "Error\n", 6);
	exit(1);
}


t_list	*ft_fill_stak(char **argv)
{
	int		i;
	int		j;
	t_list	*new;
	t_list	*stek;
	char	**words;

	i = 1;
	stek = NULL;
	while (argv[i])
	{
		words = ft_split(argv[i], ' ');
		j = 0;
		while (words[j])
		{
			if (ft_check_symbol(words[j]) != 0)
				ft_exit_symbol();
			new = ft_lstnew(ft_atoi(words[j]));
			ft_lstadd_back(&stek, new);
			free(words[j]);
printf("(i) %d, (j) %d : %d\n", i, j, new->val);
			j++;
		}
		free(words);
		i++;
	}
	
// 	stek = ft_lstnew(ft_atoi(argv[1]));
// printf("%d\n", stek->val);
// 	i = 2;
// 	while (argv[i])
// 	{
// 		new = ft_lstnew(ft_atoi(argv[i]));
// 		ft_lstadd_back(&stek, new);
// printf("%d: %d\n", i, new->val);
// 		i++;
// 	}
	return (stek);
}

int	main(int argc, char **argv)
{
	t_list	*stek_a;

	if (argc == 1)
		ft_exit_argc();
	stek_a = ft_fill_stak(argv);
}