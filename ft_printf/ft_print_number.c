/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamtiou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 17:11:16 by alamtiou          #+#    #+#             */
/*   Updated: 2024/12/15 17:11:20 by alamtiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr(int n)
{
	int		cnt;
	long	num;
	char	c;

	cnt = 0;
	num = n;
	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
		cnt++;
	}
	if (num >= 10)
		cnt += ft_putnbr(num / 10);
	c = (num % 10) + '0';
	write(1, &c, 1);
	return (cnt + 1);
}

int	ft_print_number(int n)
{
	return (ft_putnbr(n));
}
