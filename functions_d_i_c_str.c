/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_d_i_c_str.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:33:57 by vsimeono          #+#    #+#             */
/*   Updated: 2021/11/25 20:39:38 by vsimeono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		for_integer(va_list list)
{
	long		number;
	unsigned int	len;
	
	number = va_arg(list, int);
	len = get_len_int(number);
	ft_putnbr_fd(number, 1);
	return(len);
}

int		for_char(va_list list)
{
	int		len_char;
	char	character;

	len_char = 1;
	character = va_arg(list, int);
	ft_putchar_fd(character, 1);
	return(len_char);
}

int		for_string(va_list list)
{
	int		len_string;
	char		*string;
	
	string = va_arg(list, char *);
	len_string = ft_strlen(string);
	write(1, string, len_string);
	return(len_string);
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
	return(i);
}