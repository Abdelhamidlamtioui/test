/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamtiou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 22:02:18 by alamtiou          #+#    #+#             */
/*   Updated: 2024/11/10 22:02:21 by alamtiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}

// int main() {
//     int fd = 1;
//     printf("ft_putstr_fd kat-kteb string 'Hello, world!': ");
//     ft_putstr_fd("Hello, world!", fd);
//     printf("\n");
//     return (0);
// }
