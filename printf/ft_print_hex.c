/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamtiou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 17:10:53 by alamtiou          #+#    #+#             */
/*   Updated: 2024/12/15 17:15:26 by alamtiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_hex(unsigned int n, char format)
{
	int		cnt;
	char	*bs;
	char	c;

	cnt = 0;
	if (format == 'X')
		bs = "0123456789ABCDEF";
	else
		bs = "0123456789abcdef";
	if (n >= 16)
		cnt += ft_put_hex(n / 16, format);
	c = bs[n % 16];
	write(1, &c, 1);
	return (cnt + 1);
}

int	ft_print_hex(unsigned int n, char format)
{
	return (ft_put_hex(n, format));
}
