/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 12:41:11 by mlarra            #+#    #+#             */
/*   Updated: 2022/02/15 12:14:33 by mlarra           ###   ########.fr       */
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
	int				min_score;
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
int		my_atoi(const char *str);
void	sa(t_list **s_a);
void	sb(t_list **s_b);
void	ss(t_list **s_a, t_list **s_b);
void	pa(t_list **s_b, t_list **s_a);
void	pb(t_list **s_a, t_list **s_b);
void	ra(t_list **s_a);
void	rb(t_list **s_b);
void	rr(t_list **s_a, t_list **s_b);
void	rra(t_list **s_a);
void	rrb(t_list **s_b);
void	rrr(t_list **s_a, t_list **s_b);
t_list	*ft_lstlast(t_list *lst);
void	ft_exit_argc(void);
void	ft_exit_symbol(t_list *stack);
void	ft_exit_argv(void);
void	ft_exit_malloc(void);
void	ft_exit_arr(char **str, char ***words, int **ar_int);

t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst);
int		ft_lstsize(t_list *lst);

int		ft_check_args(char **s, t_sort *inf);
int		ft_get_length(char **s);
int		ft_get_med(t_sort *data);

void	ft_sort_three_elem(t_list **list, t_sort *inf);
void	ft_sort_all(t_list **a, t_list **b, t_sort *data);
void	ft_finish_sort(t_list **a, t_sort *data);

void	ft_func_rotate(int count, t_list **a, void (func)(t_list **));
void	ft_func_rotate2(int count, t_list **a, t_list **b,
			void (func2)(t_list **, t_list **));
void	ft_find_local_min(t_list *tmp, t_sort *data);
void	ft_score_init(t_list *a, t_list *b, t_sort *data);
t_list	*ft_find_min(t_list *stack);

void	ft_score_init(t_list *a, t_list *b, t_sort *data);
int		ft_get_b_r(t_list *lst, int nbr);

#endif