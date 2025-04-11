#include "so_long.h"

/*
 * Check if map is surrounded by walls
 */
static int	check_walls(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if ((i == 0 || i == game->height - 1 || j == 0 
				|| j == game->width - 1) && game->map[i][j] != WALL)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/*
 * Count and validate map elements
 */
static int	check_elements(t_game *game)
{
	int	i;
	int	j;
	int	exit_count;
	int	player_count;

	exit_count = 0;
	player_count = 0;
	game->collectibles = 0;
	i = -1;
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
		{
			if (game->map[i][j] == EXIT && exit_count++ == 0)
				game->exit_x = j, game->exit_y = i;
			else if (game->map[i][j] == PLAYER && player_count++ == 0)
				game->player_x = j, game->player_y = i;
			else if (game->map[i][j] == COLLECTIBLE)
				game->collectibles++;
			else if (game->map[i][j] != EMPTY && game->map[i][j] != WALL)
				return (0);
		}
	}
	return (exit_count == 1 && player_count == 1 && game->collectibles > 0);
}

/*
 * Validate map structure (rectangular, surrounded by walls, valid elements)
 */
int	validate_map(t_game *game)
{
	int	i;

	// Check if map is rectangular
	i = 0;
	while (i < game->height)
	{
		if ((int)ft_strlen(game->map[i]) != game->width)
			return (0);
		i++;
	}
	// Check if map is surrounded by walls
	if (!check_walls(game))
		return (0);
	// Check map elements
	if (!check_elements(game))
		return (0);
	return (1);
}

/*
 * Recursive flood fill to check if valid path exists
 */
static void	flood_fill(char **map, int x, int y, int *status)
{
	// Mark current cell as visited
	if (map[y][x] == COLLECTIBLE)
		status[0]++;
	if (map[y][x] == EXIT)
		status[1] = 1;
	map[y][x] = 'V'; // Visited

	// Check adjacent cells
	if (map[y + 1][x] != WALL && map[y + 1][x] != 'V')
		flood_fill(map, x, y + 1, status);
	if (map[y - 1][x] != WALL && map[y - 1][x] != 'V')
		flood_fill(map, x, y - 1, status);
	if (map[y][x + 1] != WALL && map[y][x + 1] != 'V')
		flood_fill(map, x + 1, y, status);
	if (map[y][x - 1] != WALL && map[y][x - 1] != 'V')
		flood_fill(map, x - 1, y, status);
}

/*
 * Check if there's a valid path from player to exit collecting all items
 */
int	check_map_path(t_game *game)
{
	char	**map_copy;
	int		status[2];
	int		i;

	// Create a copy of the map for flood fill
	map_copy = (char **)malloc(sizeof(char *) * (game->height + 1));
	if (!map_copy)
		return (0);
	i = 0;
	while (i < game->height)
	{
		map_copy[i] = ft_strdup(game->map[i]);
		if (!map_copy[i])
		{
			while (--i >= 0)
				free(map_copy[i]);
			free(map_copy);
			return (0);
		}
		i++;
	}
	map_copy[i] = NULL;
	status[0] = 0; // Collectibles found
	status[1] = 0; // Exit found
	flood_fill(map_copy, game->player_x, game->player_y, status);
	i = -1;
	while (++i < game->height)
		free(map_copy[i]);
	free(map_copy);
	return (status[0] == game->collectibles && status[1] == 1);
}