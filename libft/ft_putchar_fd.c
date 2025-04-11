/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamtiou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 22:01:05 by alamtiou          #+#    #+#             */
/*   Updated: 2024/11/10 22:01:09 by alamtiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// int main() {
//     int fd = 1;
//     printf("ft_putchar_fd kat-kteb char 'A': ");
//     ft_putchar_fd('A', fd);
//     printf("\n");
//     return (0);
// }
