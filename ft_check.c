/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamtiou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 04:30:34 by alamtiou          #+#    #+#             */
/*   Updated: 2025/04/12 04:30:37 by alamtiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validate_map(t_data *data)
{
	int	len;

	len = get_array_size((const char **)data->map);
	if (!map_rectangular(data->map))
		ft_error_close(ft_free_map(data->map), SHAPE_ERROR, -1);
	if (!map_surrounded_walls(data->map, len))
		ft_error_close(ft_free_map(data->map), WALLS_ERROR, -1);
	if (!validate_map_components(data))
		ft_error_close(ft_free_map(data->map), COMPONENET_ERROR, -1);
	if (!flood_fill(data))
		ft_error_close(ft_free_map(data->map), MAP_ERROR, -1);
}

char	*read_file_content(int fd)
{
	char	*tmp;
	char	*cont;
	int		i;

	cont = ft_strdup("");
	if (!cont)
		ft_error_close(NULL, MALLOC_ERROR, fd);
	tmp = ft_strdup(" ");
	if (!tmp)
		ft_error_close(cont, MALLOC_ERROR, fd);
	i = 1;
	while (i > 0)
	{
		i = read(fd, tmp, 1);
		if (i == 0)
			break ;
		if (i < 0)
			ft_free_all(cont, tmp, READ_ERROR, fd);
		cont = ft_strjoin(cont, tmp);
		if (!cont)
			ft_error_close(tmp, MALLOC_ERROR, fd);
	}
	free(tmp);
	return (cont);
}

int	validate_file_extension(char *filename)
{
	int	i;
	int	fd;

	i = ft_strlen(filename) - ft_strlen(EXTENSION);
	if (i <= 0 || filename[i - 1] == '/')
		ft_error_0(FILE_ERROR);
	if (!ft_strcmp(filename + i, EXTENSION))
		ft_error_0(EXTENSION_ERROR);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error_0(OPEN_ERROR);
	return (fd);
}

void	ft_check(char *filename, t_data *data)
{
	int		fd;
	char	**map;
	char	*cont;

	fd = validate_file_extension(filename);
	cont = read_file_content(fd);
	if (ft_strnstr(cont, "\n\n", ft_strlen(cont)))
		ft_error_close(cont, NEWLINE_ERROR, fd);
	close(fd);
	map = ft_split(cont, '\n');
	free(cont);
	if (!map)
		ft_error_close(ft_free_map(map), MALLOC_ERROR, -1);
	if (!*map)
		ft_error_close(ft_free_map(map), READ_ERROR, -1);
	data->map = map;
	validate_map(data);
}
