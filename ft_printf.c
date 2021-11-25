/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:32:55 by vsimeono          #+#    #+#             */
/*   Updated: 2021/11/25 20:45:35 by vsimeono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list list;
	
	i = 0;
	va_start(list, format);
	while (format[i] != '\0')
	{

		if (format[i] != '%')
		{
			ft_putchar_fd(format[i], 1);
			i++;
		}
		if (format[i] == '%')
		{
			check_placeholder(list, format[i + 1]);
			i += 2;
		}
	}
	va_end(list);
	return (0);
}

int		check_placeholder(va_list list, char c)
{
	char	temp;
	int		type;

	if (c == 'd' || c == 'i')
		for_integer(list);
	if (c == 'c')
		type = for_char(list);
	if (c == 's')
		for_string(list);
	if (c == 'p')
		for_pointer(list);
	if (c == 'u')
		for_unsigned(list);
	if (c == 'x')
		for_hexadecimal_lower(list);
	if (c == 'X')
		for_hexadecimal_upper(list);
	if (c == '%')
		for_percent(list);
	return (0);
}

int		main()
{
	int		i;
	char	c;
	char	str[] = "Ars Longa";


	i = 71;
	c = 'A';
	
	int		hexa_lower;
	int		hexa_upper;
	hexa_lower = 31;
	hexa_upper = 31;
	char	*pointer;

	pointer = &c;
	
	ft_printf("%%%x%X%p",hexa_lower, hexa_upper, pointer);
	return (0);
}
