/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 11:30:26 by mlarra            #+#    #+#             */
/*   Updated: 2021/11/08 15:22:31 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_f(t_print	*print)
{
	print[0].symb = 'c';
	print[0].type = FT_PRINT_C;
	print[1].symb = 's';
	print[1].type = FT_PRINT_S;
	print[2].symb = 'd';
	print[2].type = FT_PRINT_D;
	print[3].symb = 'i';
	print[3].type = FT_PRINT_I;
	print[4].symb = 'u';
	print[4].type = FT_PRINT_U;
	print[5].symb = 'x';
	print[5].type = FT_PRINT_x;
	print[6].symb = 'X';
	print[6].type = FT_PRINT_X;
	print[7].symb = 'p';
	print[7].type = FT_PRINT_P;
}

void	ft_init_arr(t_arr_f	print_arr_f)
{
	print_arr_f[0] = ft_print_c;
	print_arr_f[1] = ft_print_s;
	print_arr_f[2] = ft_print_i;
	print_arr_f[3] = ft_print_i;
	print_arr_f[4] = ft_print_u;
	print_arr_f[5] = ft_print_x;
	print_arr_f[6] = ft_print_X;
	print_arr_f[7] = ft_print_p;
}

void	ft_init_flags(t_flags *flags)
{
	flags->percent = 0;
	flags->plus = 0;
	flags->minus = 0;
	flags->sharp = 0;
	flags->space = 0;
	flags->zero = 0;
	flags->width = 0;
	flags->presicion = 0;
	flags->point = 0;
}

char	*ft_inti_null_str(char *dest)
{
	dest[0] = '(';
	dest[1] = 'n';
	dest[2] = 'u';
	dest[3] = 'l';
	dest[4] = 'l';
	dest[5] = ')';
	dest[6] = '\0';
	return (dest);
}

char	*ft_init_str_min_value_d(char *dest)
{
	dest[0] = '-';
	dest[1] = '2';
	dest[2] = '1';
	dest[3] = '4';
	dest[4] = '7';
	dest[5] = '4';
	dest[6] = '8';
	dest[7] = '3';
	dest[8] = '6';
	dest[9] = '4';
	dest[10] = '8';
	dest[11] = '\0';
	return (dest);
}
