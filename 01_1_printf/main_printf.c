/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 13:21:56 by mlarra            #+#    #+#             */
/*   Updated: 2021/11/08 16:36:00 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
// #include "ft_printf.c"

int main()
{
    char c = 'a';
	char *str = "Xo-Xo-Xoy";
    int i = 21;
    int d = 10;
	unsigned int u = 4294967295;
	unsigned int x = 2147483647;
	unsigned int X = 2147483647;
	int *ptr = &i;
	ft_printf("|ft_printf_c: %c|\n", c);
	   printf("|   printf_c: %c|\n", c);
	printf("----------------------\n");
	ft_printf("|ft_printf_c: %5c|\n", c);
	   printf("|   printf_c: %5c|\n", c);
	printf("----------------------\n");
	ft_printf("|ft_printf_c: %-5c|\n", c);
	   printf("|   printf_c: %-5c|\n", c);
	printf("----------------------\n");

	printf("| char :%5c|\n", c);
	printf("|char -:%-5c|\n", c);
	printf("---------------\n");
	   printf("|  str .:%.4s|\n", str);
	ft_printf("|ftstr .:%.4s|\n", str);
	printf("---------------\n");
	   printf("| str -.:%-.4s|\n", str);
	ft_printf("|fstr -.:%-.4s|\n", str);
	printf("---------------\n");
	   printf("| str w.:%7.4s|\n", str);
	ft_printf("|fstr w.:%7.4s|\n", str);
	printf("---------------\n");
	   printf("|   str -w.:%-7.4s|\n", str);
	ft_printf("|ft_str -w.:%-7.4s|\n", str);
	printf("---------------\n");
	   printf("| str w.:%2.8s|\n", str);
	ft_printf("|fstr w.:%2.8s|\n", str);
	printf("---------------\n");
	   printf("|   str -w.:%-2.8s|\n", str);
	ft_printf("|ft_str -w.:%-2.8s|\n", str);
	printf("---------------\n");
	   printf("| str w.:%20.10s|\n", str);
	ft_printf("|fstr w.:%20.10s|\n", str);
	printf("---------------\n");
	   printf("|   str -w.:%-20.10s|\n", str);
	ft_printf("|ft_str -w.:%-20.10s|\n", str);
	printf("---------------\n");
	   printf("|  str w:%7s|\n", str);
	ft_printf("|ftstr w:%7s|\n", str);
	printf("---------------\n");
	   printf("| str -w:%-7s|\n", str);
	ft_printf("|fstr -w:%-7s|\n", str);
	printf("---------------\n");
	   printf("|  str w:%20s|\n", str);
	ft_printf("|ftstr w:%20s|\n", str);
	printf("---------------\n");
	   printf("| str -w:%-20s|\n", str);
	ft_printf("|fstr -w:%-20s|\n", str);
	printf("---------------\n");
	   printf("| NULL .:%.4s|\n", NULL);
	ft_printf("|fNULL .:%.4s|\n", NULL);
	printf("---------------\n");
	   printf("|   NULL -.:%-.4s|\n", NULL);
	ft_printf("|ft_NULL -.:%-.4s|\n", NULL);
	printf("---------------\n");
	   printf("| NULL .:%20.4s|\n", NULL);
	ft_printf("|fNULL .:%20.4s|\n", NULL);
	printf("---------------\n");
	   printf("|   NULL -.:%-20.4s|\n", NULL);
	ft_printf("|ft_NULL -.:%-20.4s|\n", NULL);
	printf("---------------\n");

	ft_printf("|ft_printf_s:%s everywhere|\n", NULL);
	   printf("|   printf_s:%s everywhere|\n", NULL);
	printf("----------------------\n");
	ft_printf("|ft_printf_i: %+10.5i|\n", 0);
	   printf("|   printf_i: %+10.5i|\n", 0);
	printf("----------------------\n");

	ft_printf("|ft_printf_i:%+20.15i|\n", 2147483647);
	   printf("|   printf_i:%+20.15i|\n", 2147483647);
	printf("----------------------\n");

	ft_printf("ft_printf_i: % i\n", i);
	   printf("   printf_i: % i\n", i);
	printf("----------------------\n");
	ft_printf("ft_printf_d: %+d\n", d);
	   printf("   printf_d: %+d\n", d);
	printf("----------------------\n");
	ft_printf("ft_printf_d: %d\n", d);
	   printf("   printf_d: %d\n", d);
	printf("----------------------\n");

	ft_printf("|ft -10.:%-10.d|\n", 0);
	   printf("|   -10.:%-10.d|\n", 0);
	printf("----------------------\n");
	ft_printf("ft 42 - 84 is %d\n", -42);
	   printf("   42 - 84 is %d\n", -42);
	printf("----------------------\n");

	ft_printf("|ft_printf_u:%20.15u|\n", u);
	   printf("|   printf_u:%20.15u|\n", u);
	printf("----------------------\n");

	ft_printf("|ft_printf_x: %x|\n", x);
	   printf("|   printf_x: %x|\n", x);
	printf("----------------------\n");
	ft_printf("|ft_printf_x:%-#20.10x|\n", x);
	   printf("|   printf_x:%-#20.10x|\n", x);
	printf("----------------------\n");


	ft_printf("|ft_printf_X:%#20.10X|\n", X);
	   printf("|   printf_X:%#20.10X|\n", X);
	printf("----------------------\n");
	ft_printf("|ft_printf_p: %30p\n", ptr);
	   printf("|   printf_p: %30p\n", ptr);
	printf("----------------------\n");
	ft_printf("|ft_printf_p: %p\n", (void *)0);
	   printf("|   printf_p: %p\n", (void *)0);
	printf("----------------------\n");

	ft_printf("|ft_printf_proc:%%|\n");
	   printf("|   printf_proc:%%|\n");
	printf("----------------------\n");
	ft_printf("|ft_printf_proc:%010.5%|\n");
	   printf("|   printf_proc:%010.5%|\n");
	printf("----------------------\n");
	ft_printf("|ft_printf_proc:%-10%|\n");
	   printf("|   printf_proc:%-10%|\n");
	printf("----------------------\n");
	ft_printf("|ft_printf_proc:%3.3%|\n");
	   printf("|   printf_proc:%3.3%|\n");
	printf("----------------------\n");
	ft_printf("|ft_printf_proc: %%%%|\n");
	   printf("|   printf_proc: %%%%|\n");
	printf("----------------------\n");
	ft_printf("ft_printf_NULL: %s\n", NULL);
	printf("printf_NULL: %s\n", NULL);
	ft_printf("ft_plus: %#x\n", x);
	   printf("   plus: %#x\n", x);
}