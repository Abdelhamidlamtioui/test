/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamtiou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 22:09:52 by alamtiou          #+#    #+#             */
/*   Updated: 2024/11/11 10:37:55 by alamtiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!little[0])
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] && little[j]
			&& i + j < len && big[i + j] == little[j])
		{
			j++;
		}
		if (!little[j])
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
// int main() {
//     char big[] = "Hello, world!";
//     char little1[] = "world";
//     char little2[] = "planet";
//     printf("ft_strnstr dyal big w little1, 13: %s\n",
// 		ft_strnstr(big, little1, 13));
//     printf("ft_strnstr dyal big w little2, 13: %s\n"
//     // ft_strnstr(big, little2, 13));
//     return (0);
// }
