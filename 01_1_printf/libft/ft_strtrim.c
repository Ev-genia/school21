/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 15:14:02 by mlarra            #+#    #+#             */
/*   Updated: 2021/10/21 11:51:11 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_start(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]) != NULL)
		i++;
	return (i);
}

int	ft_stop(const char *s1, const char *set)
{
	int	i;

	i = ft_strlen(s1) - 1;
	while (s1[i] && ft_strchr(set, s1[i]) != NULL && i > 0)
		i--;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dest;
	int		start;
	int		stop;
	int		i;

	if (!s1 || !set)
		return (NULL);
	start = ft_start(s1, set);
	stop = ft_stop(s1, set);
	if (start >= stop)
		return (ft_strdup(""));
	dest = (char *)malloc(sizeof(char) * (stop - start + 1 + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (start <= stop)
	{
		dest[i] = s1[start];
		i++;
		start++;
	}
	dest[i] = '\0';
	return (dest);
}
