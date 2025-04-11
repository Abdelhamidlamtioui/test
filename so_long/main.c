/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:00:00 by student           #+#    #+#             */
/*   Updated: 2025/04/07 10:00:00 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*
 * Check if the file extension is .ber
 * Return 1 if valid, 0 otherwise
 */
int	check_file_extension(char *file_path)
{
	int	len;

	len = 0;
	while (file_path[len])
		len++;
	if (len < 5)
		return (0);
	if (file_path[len - 4] != '.' || file_path[len - 3] != 'b'
		|| file_path[len - 2] != 'e' || file_path[len - 1] != 'r')
		return (0);
	return (1);
}

/*
 * Initialize game variables
 */
void	init_vars(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->map = NULL;
	game->width = 0;
	game->height = 0;
	game->collectibles = 0;
	game->collected = 0;
	game->moves = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->exit_x = 0;
	game->exit_y = 0;
	game->img_empty = NULL;
	game->img_wall = NULL;
	game->img_collectible = NULL;
	game->img_exit = NULL;
	game->img_player = NULL;
}

/*
 * Main error handler with cleanup
 */
int	handle_error(t_game *game, char *message)
{
	ft_printf("Error\n%s\n", message);
	cleanup(game);
	return (1);
}

/*
 * Main entry point of the program
 */
int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (ft_printf("Error\nUsage: ./so_long [map.ber]\n"));
	if (!check_file_extension(argv[1]))
		return (ft_printf("Error\nInvalid file extension. Use .ber\n"));
	init_vars(&game);
	if (!read_map(&game, argv[1]))
		return (handle_error(&game, "Failed to read map"));
	if (!validate_map(&game))
		return (handle_error(&game, "Invalid map configuration"));
	if (!check_map_path(&game))
		return (handle_error(&game, "No valid path in map"));
	if (!init_game(&game))
		return (handle_error(&game, "Failed to initialize game"));
	game_loop(&game);
	cleanup(&game);
	return (0);
}