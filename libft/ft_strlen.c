/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamtiou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 22:08:24 by alamtiou          #+#    #+#             */
/*   Updated: 2024/11/10 22:08:33 by alamtiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

// int main() {
//     printf("Tool dyal 'Hello': %zu\n", ft_strlen("Hello"));
//     printf("Tool dyal '': %zu\n", ft_strlen(""));
//     printf("Tool dyal 'Hello, world!': %zu\n", ft_strlen("Hello, world!"));
//     return (0);
// }
