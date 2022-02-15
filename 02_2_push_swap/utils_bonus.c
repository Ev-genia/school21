/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:20:54 by mlarra            #+#    #+#             */
/*   Updated: 2022/02/15 12:13:05 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

int	get_next_line(char **line)
{
	int		i;
	int		j;
	char	*buf;

	buf = (char *) malloc(sizeof(char) * 4);
	if (!buf)
		ft_exit_argc();
	i = 0;
	j = read(0, &buf[i], 1);
	while (j > 0 && buf[i] != '\0' && buf[i] != '\n')
	{
		i++;
		j = read(0, &buf[i], 1);
	}
	buf[i] = '\0';
	*line = buf;
	return (j);
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
