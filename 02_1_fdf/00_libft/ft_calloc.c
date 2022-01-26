/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 17:41:23 by mlarra            #+#    #+#             */
/*   Updated: 2021/10/19 18:16:01 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*call;

	call = malloc(count * size);
	if (call == NULL)
		return ((void *)0);
	ft_bzero(call, count * size);
	return ((void *)call);
}
