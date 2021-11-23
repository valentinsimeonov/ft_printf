/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:32:55 by vsimeono          #+#    #+#             */
/*   Updated: 2021/11/23 20:09:32 by vsimeono         ###   ########.fr       */
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

int		main()
{
	int		i;
	char	c;
	char	str[] = "Ars Longa";

	i = 71;
	c = 'A';
	
	ft_printf("Sic Transit, Gloria Mundi%d%c%s", i, c, str);
	return (0);
}

int		for_integer(va_list list, char c)
{
	long		number;
	unsigned int	len;
	
	number = va_arg(list, int);
	len = get_len_int(number);
	ft_putnbr_fd(number, 1);
	return(len);
	// va_end(list);
}

int		get_len_int(int number)
{
	int		i;
	
	i = 1;
	while(number > 9)
	{
		number = number / 10;
		i++;
	}
	// ft_putnbr_fd(i, 1);
	return(i);
}

int		for_char(va_list list, char c)
{
	int		len_char;
	char	character;

	len_char = 1;
	character = va_arg(list, int);
	ft_putchar_fd(character, 1);
	return(len_char);
}

int		for_string(va_list list, char c)
{
	int		len_string;
	char		*string;
	
	string = va_arg(list, char *);
	len_string = ft_strlen(string);
	write(1, string, len_string);
	// ft_putchar_fd(string, 1);
	return(len_string);
}

int		check_placeholder(va_list list, char c)
{
	char	temp;
	int		type;

	if (c == 'd' || c == 'i')
		for_integer(list, c);
	if (c == 'c')
		type = for_char(list, c);
	if (c == 's')
		for_string(list, c);
// 	if (c == 'p')
// TODO	va_arg(list, pointer);

// 	if (c == 'u')
// TODO	va_arg(list, unsigned decimal in base 10);

// 	if (c == 'x')
// TODO	va_arg(list, number in hexadecimal in base 16 with lowercase);

// 	if (c == 'X')
// TODO	va_arg(list, number in hexadecimal in base 16 with uppercase);

// 	if (c == '%')
// TODO	va_arg(list, percent sign;
	return (0);
}



// char	for_char(va_list list)
// {
// 	va_arg(list, char);
// }

