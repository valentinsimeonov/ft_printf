/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:32:55 by vsimeono          #+#    #+#             */
/*   Updated: 2021/11/27 23:54:37 by vsimeono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	list;
	int		len;

	i = 0;
	len = 0;
	va_start(list, format);
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			ft_putchar_fd(format[i], 1);
			len++;
			i++;
		}
		if (format[i] == '%')
		{
			len += check_placeholder(list, format[i + 1]);
			i += 2;
		}
	}
	va_end(list);
	return (len);
}

int	check_placeholder(va_list list, char c)
{
	int		len;

	if (c == 'd' || c == 'i')
		len = for_integer(list);
	if (c == 'c')
		len = for_char(list);
	if (c == 's')
		len = for_string(list);
	if (c == 'p')
		len = for_pointer(list);
	if (c == 'u')
		len = for_unsigned(list);
	if (c == 'x')
		len = for_hexadecimal_lower(list);
	if (c == 'X')
		len = for_hexadecimal_upper(list);
	if (c == '%')
		len = for_percent();
	return (len);
}


