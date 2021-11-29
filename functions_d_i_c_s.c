/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_d_i_c_str.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:33:57 by vsimeono          #+#    #+#             */
/*   Updated: 2021/11/27 21:34:57 by vsimeono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	for_integer(va_list list)
{
	long			number;
	unsigned int	len_int;

	number = va_arg(list, int);
	len_int = get_len_int(number);
	ft_putnbr_fd(number, 1);
	return (len_int);
}

int	for_char(va_list list)
{
	int		len_char;
	char	character;

	len_char = 1;
	character = va_arg(list, int);
	ft_putchar_fd(character, 1);
	return (len_char);
}

int	for_string(va_list list)
{
	int			len_string;
	char		*string;

	string = va_arg(list, char *);
	if (string == NULL)
	{
		write(1, "(null)", 6);
		len_string = 6;
		return (len_string);
	}
	len_string = ft_strlen(string);
	write(1, string, len_string);
	return (len_string);
}

int	get_len_int(long int number)
{
	int		len;

	len = 1;
	if (number < 0)
	{
		number = number * -1;
		len++;
	}
	while (number / 10)
	{
		number = number / 10;
		len++;
	}
	return (len);
}
