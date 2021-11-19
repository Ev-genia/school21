/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 11:38:44 by mlarra            #+#    #+#             */
/*   Updated: 2021/10/17 13:05:10 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int a);
int	ft_isdigit(int a);

int	ft_isalnum(int a)
{
	if (ft_isalpha(a) || ft_isdigit(a))
		return (1);
	return (0);
}
