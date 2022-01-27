/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 12:41:11 by mlarra            #+#    #+#             */
/*   Updated: 2022/01/26 16:40:31 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				val;
	int				score;
	struct s_list	*next;
}	t_list;

typedef struct s_sort
{
	int	min;
	int	med;
	int	max;
	int	len_arr;
	int	*arr;
}	t_sort;

char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
int		ft_atoi(const char *str);
void	swap(t_list **l);
void	push(t_list **a, t_list **b);
void	rotate(t_list **l);
void	reverse(t_list **l);
t_list	*ft_lstlast(t_list *lst);


#endif