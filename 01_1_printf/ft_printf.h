/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 18:30:19 by mlarra            #+#    #+#             */
/*   Updated: 2021/11/08 17:49:17 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

enum e_print_type
{
	FT_PRINT_C,
	FT_PRINT_S,
	FT_PRINT_D,
	FT_PRINT_I,
	FT_PRINT_U,
	FT_PRINT_x,
	FT_PRINT_X,
	FT_PRINT_P
};
typedef struct s_print
{
	char				symb;
	enum e_print_type	type;
}		t_print;
typedef struct s_flags
{
	int	percent;
	int	plus;
	int	sharp;
	int	space;
	int	zero;
	int	minus;
	int	width;
	int	presicion;
	int	point;
}		t_flags;

typedef void	(*t_arr_f[10])(va_list ap, int *i, t_flags flags);

int		ft_printf(const char *str, ...);
void	ft_print_percent(t_flags flags, int *i);
void	ft_print_space_s(t_flags flags, int *i);
void	ft_print_c(va_list argptr, int *i, t_flags flags);
void	ft_print_s(va_list argptr, int *i, t_flags flags);
void	ft_print_i(va_list argptr, int *i, t_flags flags);
void	ft_print_u(va_list argptr, int *i, t_flags flags);
void	ft_print_x(va_list argptr, int *i, t_flags flags);
void	ft_print_X(va_list argptr, int *i, t_flags flags);
void	ft_print_p(va_list argptr, int *i, t_flags flags);
void	ft_print_0(unsigned int d, t_flags flags, int *i);
void	ft_print_min_value_d(t_flags flags, int *i);
void	ft_print_zero(t_flags flags, int count, int *i);
void	ft_print_negative_d(t_flags flags, int d, int *i, char *str);
void	ft_print_positive_d(t_flags flags, unsigned int d, int *i, char *str);
void	ft_print_d_without_minus(char *str, int *i);
void	ft_nbr_x(unsigned long long int x, int *i, char type);
void	ft_print_0_x(unsigned long long int d, t_flags flags, int *i);
void	ft_init_f(t_print	*print);
void	ft_init_arr(t_arr_f	print_arr_f);
void	ft_init_flags(t_flags *flags);
int		ft_init_count(unsigned long int d);
int		ft_init_count_16(unsigned long long int x);
char	*ft_inti_null_str(char *dest);
char	*ft_init_str_min_value_d(char *dest);
void	ft_putchar(char c, int *i);
void	ft_check_percent(char *string, t_flags *flags);
void	ft_check_space_plus(unsigned int d, t_flags flags, int *i);
void	ft_check_minus_0(t_flags flags, int d, int *i);
void	ft_check_minus_x(t_flags flags, int *i, char type, \
		unsigned long long x);
char	*ft_itoa_p(unsigned long long int n);
#endif