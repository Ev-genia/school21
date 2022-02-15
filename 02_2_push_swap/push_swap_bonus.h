/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:52:28 by mlarra            #+#    #+#             */
/*   Updated: 2022/02/14 16:24:57 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
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
int		get_next_line(char **line);
t_list	*ft_fill_stack(char **argv);

int		ft_check_args(char **s, t_sort *inf);
int		ft_get_length(char **s);

void	ft_exit_argv(void);
void	ft_exit_argc(void);
void	ft_exit_malloc(void);

t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst);
t_list	*ft_lstlast(t_list *lst);

void	swap(t_list **l);
void	ss(t_list **s_a, t_list **s_b);
void	push(t_list **a, t_list **b);
void	rotate(t_list **l);
void	rr(t_list **s_a, t_list **s_b);
void	reverse(t_list **l);
void	rrr(t_list **s_a, t_list **s_b);

#endif