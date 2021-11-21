/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:32:55 by vsimeono          #+#    #+#             */
/*   Updated: 2021/11/21 20:40:13 by vsimeono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
	int		i;
	
	i = 0;
	while (format[i] != '\0')
	{
		ft_putchar_fd(format[i], 1);
		format++;
	}
	return (0);
}

int		main()
{
	int		i;
	char	c;

	i = 71;
	c = 'A';
	ft_printf("Ars longa, vita brevis%d", i);

	return (0);
	
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
