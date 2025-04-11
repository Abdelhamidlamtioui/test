
#include "so_long.h"

/*
 * Free the map memory
 */
void	free_map(t_game *game)
{
	int	i;

	if (game->map)
	{
		i = 0;
		while (i < game->height && game->map[i])
		{
			free(game->map[i]);
			i++;
		}
		free(game->map);
		game->map = NULL;
	}
}

/*
 * Free all image resources
 */
void	free_images(t_game *game)
{
	if (game->mlx)
	{
		if (game->img_empty)
			mlx_destroy_image(game->mlx, game->img_empty);
		if (game->img_wall)
			mlx_destroy_image(game->mlx, game->img_wall);
		if (game->img_collectible)
			mlx_destroy_image(game->mlx, game->img_collectible);
		if (game->img_exit)
			mlx_destroy_image(game->mlx, game->img_exit);
		if (game->img_player)
			mlx_destroy_image(game->mlx, game->img_player);
	}
}

/*
 * Clean up all allocated resources
 */
void	cleanup(t_game *game)
{
	free_images(game);
	free_map(game);
	if (game->win && game->mlx)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*dup;
	size_t	i;

	len = 0;
	while (s[len])
		len++;
	dup = (char *)malloc(len + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}