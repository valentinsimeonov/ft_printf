/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_pointer_unsigned_percent.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 20:41:19 by vsimeono          #+#    #+#             */
/*   Updated: 2021/11/25 20:47:05 by vsimeono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		for_pointer(va_list list)
{
	void		*pointer;
	int			len_pointer;

	pointer = va_arg(list, void *);
	if (!pointer)
	{
		write(1, "0x0", 1);
		len_pointer = 3;
		return (len_pointer);
	}
	else
	{
		len_pointer = get_len_hexa((int)pointer) + 2;
		write(1, "0x", 2);
		ft_put_hexa((int)pointer, 16, "123456789abcdef");
		return(len_pointer);
	}
}

int		for_percent(va_list list)
{
	int		len_percent;
	char	percent;

	// percent = va_arg(list, int);
	percent = '%';
	len_percent = 1;
	write(1, &percent, 1);
	return(len_percent);
}

int		for_unsigned(va_list list)
{
	int		len_unsigned;
	int		unsigned_int;

	unsigned_int = va_arg(list, unsigned int);
	len_unsigned = get_len_int(unsigned_int);
	ft_put_hexa(unsigned_int, 10, "0123456789");
	return(len_unsigned);
}
