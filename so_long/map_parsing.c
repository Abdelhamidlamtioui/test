
#include "so_long.h"

/*
 * Count rows in the map file
 */
static int	count_rows(char *file_path)
{
	int		fd;
	int		rows;
	char	*line;

	rows = 0;
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		rows++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (rows);
}

/*
 * Allocate memory for the map
 */
static int	allocate_map(t_game *game, int rows)
{
	int	i;

	game->height = rows;
	game->map = (char **)malloc(sizeof(char *) * (rows + 1));
	if (!game->map)
		return (0);
	i = 0;
	while (i <= rows)
	{
		game->map[i] = NULL;
		i++;
	}
	return (1);
}

/*
 * Read map content from file
 */
static int	fill_map(t_game *game, char *file_path)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (0);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		game->map[i] = line;
		// Remove newline if present
		if (i > 0 && game->width != (int)ft_strlen(game->map[i]))
		{
			close(fd);
			return (0);
		}
		else if (i == 0)
			game->width = ft_strlen(game->map[i]);
		i++;
		line = get_next_line(fd);
	}
	close(fd);
	return (1);
}

/*
 * Read and parse the map file
 */
int	read_map(t_game *game, char *file_path)
{
	int	rows;

	rows = count_rows(file_path);
	if (rows <= 0)
		return (0);
	if (!allocate_map(game, rows))
		return (0);
	if (!fill_map(game, file_path))
		return (0);
	return (1);
}