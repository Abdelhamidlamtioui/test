
#include "../includes/so_long.h"

/*
 * Load images from files
 */
int	load_images(t_game *game)
{
	int	img_width;
	int	img_height;

	game->img_empty = mlx_xpm_file_to_image(game->mlx, 
		"./textures/empty.xpm", &img_width, &img_height);
	game->img_wall = mlx_xpm_file_to_image(game->mlx, 
		"./textures/wall.xpm", &img_width, &img_height);
	game->img_collectible = mlx_xpm_file_to_image(game->mlx, 
		"./textures/collectible.xpm", &img_width, &img_height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, 
		"./textures/exit.xpm", &img_width, &img_height);
	game->img_player = mlx_xpm_file_to_image(game->mlx, 
		"./textures/player.xpm", &img_width, &img_height);
	if (!game->img_empty || !game->img_wall || !game->img_collectible
		|| !game->img_exit || !game->img_player)
		return (0);
	return (1);
}

/*
 * Initialize MLX and create window
 */
static int	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	game->win = mlx_new_window(game->mlx, game->width * TILE_SIZE,
			game->height * TILE_SIZE, "So Long");
	if (!game->win)
		return (0);
	return (1);
}

/*
 * Initialize game environment
 */
int	init_game(t_game *game)
{
	if (!init_mlx(game))
		return (0);
	if (!load_images(game))
		return (0);
	render_map(game);
	return (1);
}