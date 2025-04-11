
#include "so_long.h"

/*
 * Handle key press event
 */
int	key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		return (close_game(game));
	else if (keycode == KEY_W)
		move_player(game, game->player_x, game->player_y - 1);
	else if (keycode == KEY_A)
		move_player(game, game->player_x - 1, game->player_y);
	else if (keycode == KEY_S)
		move_player(game, game->player_x, game->player_y + 1);
	else if (keycode == KEY_D)
		move_player(game, game->player_x + 1, game->player_y);
	return (0);
}

/*
 * Handle window close event
 */
int	close_game(t_game *game)
{
	cleanup(game);
	exit(0);
	return (0);
}

/*
 * Update game state based on player position
 */
void	update_game_state(t_game *game)
{
	char	current_pos;

	current_pos = game->map[game->player_y][game->player_x];
	if (current_pos == COLLECTIBLE)
	{
		game->collected++;
		game->map[game->player_y][game->player_x] = EMPTY;
	}
	else if (current_pos == EXIT && game->collected == game->collectibles)
	{
		ft_printf("\nYou won in %d moves!\n", game->moves);
		close_game(game);
	}
	render_map(game);
	ft_printf("Moves: %d\n", game->moves);
}

/*
 * Set up and start the game loop
 */
int	game_loop(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, key_hook, game);
	mlx_hook(game->win, 17, 0, close_game, game);
	mlx_loop(game->mlx);
	return (1);
}