/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamtiou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 21:41:55 by alamtiou          #+#    #+#             */
/*   Updated: 2024/11/10 21:42:00 by alamtiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}

// int main() {
//     int *arr = (int *)ft_calloc(5, sizeof(int));
//     if (arr) {
//         for (int i = 0; i < 5; i++) {
//             printf("arr[%d] = %d\n", i, arr[i]);
//         }
//         free(arr);
//     }
//     return (0);
// }
