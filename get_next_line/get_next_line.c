/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamtiou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 22:15:42 by alamtiou          #+#    #+#             */
/*   Updated: 2024/12/25 22:15:52 by alamtiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*find_nl(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == '\n')
			return (s + i);
		i++;
	}
	return (NULL);
}

static char	*extract_line(char *buff)
{
	char	*line;
	int		i;

	if (!buff || !buff[0])
		return (NULL);
	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (buff[i] && buff[i] != '\n')
	{
		line[i] = buff[i];
		i++;
	}
	if (buff[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*clean_buffer(char *buff)
{
	char	*new;
	int		i;
	int		j;

	if (!buff)
		return (NULL);
	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (!buff[i])
	{
		free(buff);
		return (NULL);
	}
	new = malloc(ft_strlen(buff) - i + 1);
	if (!new)
		return (NULL);
	i++;
	j = 0;
	while (buff[i])
		new[j++] = buff[i++];
	new[j] = '\0';
	free(buff);
	return (new);
}

static char	*read_to_buffer(int fd, char *buff)
{
	char	*tmp;
	ssize_t	read_bytes;

	tmp = malloc((size_t)BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	read_bytes = 1;
	while (!find_nl(buff) && read_bytes > 0)
	{
		read_bytes = read(fd, tmp, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(tmp);
			free(buff);
			return (NULL);
		}
		tmp[read_bytes] = '\0';
		buff = ft_strjoin(buff, tmp);
	}
	free(tmp);
	return (buff);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(buff);
		buff = NULL;
		return (NULL);
	}
	buff = read_to_buffer(fd, buff);
	if (!buff)
		return (NULL);
	line = extract_line(buff);
	buff = clean_buffer(buff);
	return (line);
}
