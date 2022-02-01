/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 12:41:11 by mlarra            #+#    #+#             */
/*   Updated: 2022/01/31 15:48:11 by mlarra           ###   ########.fr       */
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
	int				score_a_r;
	int				score_a_rr;
	int				score_b_r;
	int				score_b_rr;
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
void	sa(t_list **s_a);
void	sb(t_list **s_b);
void	ss(t_list **s_a, t_list **s_b);

void	swap(t_list **l);
void	pa(t_list **s_b, t_list **s_a);
void	pb(t_list **s_a, t_list **s_b);

void	push(t_list **a, t_list **b);
void	ra(t_list **s_a);
void	rb(t_list **s_b);
void	rr(t_list **s_a, t_list **s_b);

void	rotate(t_list **l);
void	rra(t_list **s_a);
void	rrb(t_list **s_b);
void	rrr(t_list **s_a, t_list **s_b);

void	reverse(t_list **l);
t_list	*ft_lstlast(t_list *lst);


#endif