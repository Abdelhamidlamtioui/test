/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamtiou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 17:11:33 by alamtiou          #+#    #+#             */
/*   Updated: 2024/12/15 17:11:37 by alamtiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_ptr(unsigned long n)
{
	int		cnt;
	char	c;
	char	*bs;

	cnt = 0;
	bs = "0123456789abcdef";
	if (n >= 16)
		cnt += ft_put_ptr(n / 16);
	c = bs[n % 16];
	write(1, &c, 1);
	return (cnt + 1);
}

int	ft_print_pointer(void *ptr)
{
	int				cnt;
	unsigned long	address;

	cnt = 2;
	if (ptr == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	address = (unsigned long)ptr;
	cnt += ft_put_ptr(address);
	return (cnt);
}
