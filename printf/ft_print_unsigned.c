/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamtiou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 17:11:49 by alamtiou          #+#    #+#             */
/*   Updated: 2024/12/15 17:11:52 by alamtiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_unsigned(unsigned int n)
{
	int		cnt;
	char	c;

	cnt = 0;
	if (n >= 10)
		cnt += ft_put_unsigned(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
	return (cnt + 1);
}

int	ft_print_unsigned(unsigned int n)
{
	return (ft_put_unsigned(n));
}
