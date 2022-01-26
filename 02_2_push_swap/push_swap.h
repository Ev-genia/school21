/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 12:41:11 by mlarra            #+#    #+#             */
/*   Updated: 2022/01/25 16:30:32 by mlarra           ###   ########.fr       */
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

char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
int		ft_atoi(const char *str);
void	swap(t_list **l);


#endif