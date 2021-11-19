/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 12:01:33 by mlarra            #+#    #+#             */
/*   Updated: 2021/10/22 00:20:39 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_words(char const *str, char c)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else
		{
			k++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (k);
}

char	*ft_wd(char const *str, char c)
{
	int		i;
	char	*wd;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	wd = malloc(sizeof(char) * (i + 1));
	if (wd == NULL)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != c)
	{
		wd[i] = str[i];
		i++;
	}
	wd[i] = '\0';
	return (wd);
}

void	free_words(int i, char **ptr)
{
	while (i > 0)
	{
		free(ptr[i - 1]);
		i--;
	}
	free(ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr_words;
	int		words;
	int		i;

	if (!s)
		return (NULL);
	words = ft_words(s, c);
	ptr_words = malloc(sizeof(char *) * (words + 1));
	if (ptr_words == NULL)
		return (NULL);
	i = 0;
	while (i < words)
	{
		while (*s && *s == c)
			s++;
		ptr_words[i] = ft_wd(s, c);
		if (ptr_words[i] == NULL)
			free_words(i, ptr_words);
		while (*s && *s != c)
			s++;
		i++;
	}
	ptr_words[i] = NULL;
	return (ptr_words);
}
