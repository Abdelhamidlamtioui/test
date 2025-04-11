/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:00:00 by student           #+#    #+#             */
/*   Updated: 2025/04/07 10:00:00 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*
 * Check if move is valid
 */
static int	is_valid_move(t_game *game, int x, int y)
{
	if (x < 0 || y < 0 || x >= game->width || y >= game->height)
		return (0);
	if (game->map[y][x] == WALL)
		return (0);
	if (game->map[y][x] == EXIT && game->collected != game->collectibles)
		return (0);
	return (1);
}

/*
 * Move player to new position if valid
 */
int	move_player(t_game *game, int new_x, int new_y)
{
	if (!is_valid_move(game, new_x, new_y))
		return (0);
	
	game->player_x = new_x;
	game->player_y = new_y;
	game->moves++;
	update_game_state(game);
	return (1);
}