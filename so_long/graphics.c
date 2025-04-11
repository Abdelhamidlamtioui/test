
#include "../includes/so_long.h"

/*
 * Put an image to the window at a specified position
 */
void	put_image(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img,
		x * TILE_SIZE, y * TILE_SIZE);
}

/*
 * Render the map with all its elements
 */
void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			put_image(game, game->img_empty, x, y);
			if (game->map[y][x] == WALL)
				put_image(game, game->img_wall, x, y);
			else if (game->map[y][x] == COLLECTIBLE)
				put_image(game, game->img_collectible, x, y);
			else if (game->map[y][x] == EXIT)
				put_image(game, game->img_exit, x, y);
			x++;
		}
		y++;
	}
	// Always place player on top of other elements
	put_image(game, game->img_player, game->player_x, game->player_y);
}