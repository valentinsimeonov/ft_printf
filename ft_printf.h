/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:25:14 by vsimeono          #+#    #+#             */
/*   Updated: 2021/11/25 20:45:08 by vsimeono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
#define PRINTF_H

#include <unistd.h>
#include <stdarg.h>

int ft_printf(const char *format, ...);
int		check_placeholder(va_list list, char c);
int		for_integer(va_list list);
int		get_len_int(int number);
int		for_char(va_list list);
int		for_string(va_list list);
int		for_hexadecimal_lower(va_list list);
int		for_hexadecimal_upper(va_list list);
int		ft_put_hexa(int number, int base_type, char *base);
int		get_len_hexa(int number);
int		for_pointer(va_list list);
int		for_percent(va_list list);
int		for_unsigned(va_list list);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *s);

#endif
