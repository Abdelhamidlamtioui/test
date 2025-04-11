/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamtiou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 21:51:41 by alamtiou          #+#    #+#             */
/*   Updated: 2024/11/10 21:51:44 by alamtiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)b;
	while (len--)
	{
		*ptr++ = (unsigned char)c;
	}
	return (b);
}

// int main() {
//     char str[] = "Hello, world!";
//     ft_memset(str, 'x', 5);
//     int str[] = {1,2,3,4,5};
//     ft_memset(str, 1, 5);
//     printf("Ba3d ft_memset: %d\n", str[1]);
//     return (0);
// }
