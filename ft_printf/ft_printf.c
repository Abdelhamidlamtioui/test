/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamtiou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 17:10:24 by alamtiou          #+#    #+#             */
/*   Updated: 2024/12/15 17:10:37 by alamtiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list args, char format)
{
	if (format == 'c')
		return (ft_print_char(va_arg(args, int)));
	if (format == 's')
		return (ft_print_string(va_arg(args, char *)));
	if (format == 'p')
		return (ft_print_pointer(va_arg(args, void *)));
	if (format == 'd' || format == 'i')
		return (ft_print_number(va_arg(args, int)));
	if (format == 'u')
		return (ft_print_unsigned(va_arg(args, unsigned int)));
	if (format == 'x')
		return (ft_print_hex(va_arg(args, unsigned int), 'x'));
	if (format == 'X')
		return (ft_print_hex(va_arg(args, unsigned int), 'X'));
	if (format == '%')
		return (ft_print_char('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		cnt;

	cnt = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			cnt += ft_format(args, *format);
		}
		else
			cnt += ft_print_char(*format);
		format++;
	}
	va_end(args);
	return (cnt);
}
