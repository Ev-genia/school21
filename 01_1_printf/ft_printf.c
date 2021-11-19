/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 14:59:27 by mlarra            #+#    #+#             */
/*   Updated: 2021/11/08 17:49:04 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_string(const char ***s)
{
	char	*string;
	int		i;

	i = 0;
	while ((**s)[i] && (**s)[i] != 'd' && (**s)[i] != 'i' && (**s)[i] != 's'
		&& (**s)[i] != 'c' && (**s)[i] != 'x' && (**s)[i] != 'X'
		&& (**s)[i] != 'u' && (**s)[i] != 'p' && (**s)[i] != '%')
		i++;
	string = malloc (sizeof(char) * (i + 1));
	i = 0;
	while ((***s) && ***s != 'd' && ***s != 'i' && ***s != 's'
		&& ***s != 'c' && ***s != 'x' && ***s != 'X'
		&& ***s != 'u' && ***s != 'p' && ***s != '%')
	{
		string[i] = ***s;
		i++;
		(**s)++;
	}
	if (***s == '%')
	{
		string[i] = '%';
		i++;
	}
	string[i] = '\0';
	return (string);
}

void	ft_pars_string(char *str, t_flags *flags)
{
	while (*str && *str < '1' && !(*str == '.') && !(*str == '%'))
	{
		if (*str == '-')
			flags->minus = 1;
		if (*str == '+')
			flags->plus = 1;
		if (*str == '0')
			flags->zero = 1;
		if (*str == '#')
			flags->sharp = 1;
		if (*str == ' ')
			flags->space = 1;
		str++;
	}
	if (*str && !(*str == '.'))
		flags->width = ft_atoi(str);
	while (*str && *str != '.' && *str != '%')
		str++;
	if (*str == '.')
	{
		flags->point = 1;
		str++;
		flags->presicion = ft_atoi(str);
	}
	ft_check_percent(str, flags);
}

void	ft_check_symb(va_list argptr, int *i, const char **src)
{
	int		j;
	t_print	print[10];
	t_arr_f	print_arr_f;
	char	*string;
	t_flags	flags;

	ft_init_f(print);
	ft_init_arr(print_arr_f);
	string = ft_get_string(&src);
	ft_init_flags(&flags);
	ft_pars_string(string, &flags);
	free(string);
	if (flags.percent == 1)
	{
		ft_print_percent(flags, i);
		return ;
	}
	j = 0;
	while (**src != print[j].symb)
		j++;
	if (**src == print[j].symb)
		(print_arr_f[print[j].type])(argptr, i, flags);
}

int	ft_printf(const	char *src, ...)
{
	va_list	argptr;
	int		i;

	va_start(argptr, src);
	i = 0;
	while (*src)
	{
		if (*src == '%')
		{
			src++;
			ft_check_symb(argptr, &i, &src);
		}
		else
			ft_putchar(*src, &i);
		src++;
	}
	va_end(argptr);
	return (i);
}
