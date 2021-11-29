/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 20:42:42 by vsimeono          #+#    #+#             */
/*   Updated: 2021/11/27 22:03:50 by vsimeono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	for_hexadecimal_lower(va_list list)
{
	unsigned int		number;
	int					len_hexa;

	number = va_arg(list, int);
	len_hexa = get_len_hexa(number);
	ft_put_hexa((unsigned long)number, 16, "0123456789abcdef");
	return (len_hexa);
}

int	for_hexadecimal_upper(va_list list)
{
	unsigned int		number;
	int					len_hexa_upper;

	number = va_arg(list, int);
	len_hexa_upper = get_len_hexa(number);
	ft_put_hexa((unsigned long)number, 16, "0123456789ABCDEF");
	return (len_hexa_upper);
}

void	ft_put_hexa(unsigned long number, int base_type, char *base)
{
	int		position;

	if (number / base_type != 0)
		ft_put_hexa(number / base_type, base_type, base);
	position = number % base_type;
	write(1, &base[position], 1);
}

int	get_len_hexa(unsigned long number)
{
	int		len_hexa;

	len_hexa = 1;
	while (number / 16)
	{
		number = number / 16;
		len_hexa++;
	}
	return (len_hexa);
}
