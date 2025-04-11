/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamtiou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 22:26:38 by alamtiou          #+#    #+#             */
/*   Updated: 2024/11/10 22:41:00 by alamtiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	i;
	char	*substr;

	s_len = ft_strlen(s);
	i = 0;
	if (!s || start >= s_len)
		return ((char *)ft_calloc(1, 1));
	if (len > s_len - start)
		len = s_len - start;
	substr = (char *)malloc(len + 1);
	if (!substr)
		return (NULL);
	while (i < len && s[start + i])
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

// int main() {
//     char str[] = "Hello, world!";
//     char *sub = ft_substr(str, 7, 5);

//     if (sub) {
//         printf("ft_substr dyal str mn 7 l 5 chars: %s\n", sub);
//         free(sub);
//     }
//     return (0);
// }
