/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:00:00 by student           #+#    #+#             */
/*   Updated: 2025/04/07 10:00:00 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>

/* Include your ft_printf and get_next_line */
# include "../ft_printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"

/* Define keys for movement */
# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

/* Define map characters */
# define EMPTY '0'
# define WALL '1'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define PLAYER 'P'

/* Tile size in pixels */
# define TILE_SIZE 32

/* Game structure */
typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		width;
	int		height;
	int		collectibles;
	int		collected;
	int		moves;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	void	*img_empty;
	void	*img_wall;
	void	*img_collectible;
	void	*img_exit;
	void	*img_player;
}	t_game;

/* Map parsing and validation */
int		read_map(t_game *game, char *file_path);
int		validate_map(t_game *game);
int		check_map_path(t_game *game);

/* Game initialization */
int		init_game(t_game *game);
int		load_images(t_game *game);

/* Game loop and events */
int		game_loop(t_game *game);
int		key_hook(int keycode, t_game *game);
int		close_game(t_game *game);

/* Player movement */
int		move_player(t_game *game, int new_x, int new_y);
void	update_game_state(t_game *game);

/* Graphics rendering */
void	render_map(t_game *game);
void	put_image(t_game *game, void *img, int x, int y);

/* Memory management */
void	free_map(t_game *game);
void	free_images(t_game *game);
void	cleanup(t_game *game);

/* Utility functions */
void	init_vars(t_game *game);
int		check_file_extension(char *file_path);

#endif