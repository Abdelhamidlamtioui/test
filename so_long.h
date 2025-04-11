#ifndef SO_LONG_H
# define SO_LONG_H

# include "/usr/include/minilibx-linux/mlx.h"
# include "/usr/include/minilibx-linux/mlx_int.h"
# include "printf/ft_printf.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <unistd.h>

# ifndef PACK
#  define EXTENSION ".ber"
#  define PLAYER 'P'
#  define WALLS '1'
#  define COLLECT 'C'
#  define FREESPACE '0'
#  define EXIT 'E'
#  define GAME_NAME "I AM LIER"
# endif

# ifndef PACK_ERROR
/* Program Usage Errors */
#define FILE_ERROR        "Error: Invalid map filename\n"
#define EXTENSION_ERROR   "Error: File must have .ber extension\n"
#define OPEN_ERROR        "Error: Could not open file (file not found or permission denied)\n"
#define READ_ERROR        "Error: Failed to read map file (empty or read error)\n"
#define NEWLINE_ERROR     "Error: Map contains empty lines\n"
#define MALLOC_ERROR      "Error: Memory allocation failed\n"
#define INPUT_ERROR       "Error: Invalid usage. Correct syntax: ./so_long <map.ber>\n"
#define SHAPE_ERROR       "Error: Map must be rectangular\n"
#define WALLS_ERROR       "Error: Map must be surrounded by walls\n"
#define COMPONENET_ERROR  "Error: Map must contain exactly 1 player (P), 1 exit (E), and at least 1 collectible (C)\n"
#define MAP_ERROR         "Error: Map is not valid (player cannot reach all collectibles and exit)\n"
#define INIT_ERROR        "Error: Failed to initialize graphics\n"
#define WINDOW_ERROR      "Error: Failed to create game window\n"
#define IMAGE_ERROR       "Error: Failed to load game textures\n"

# endif

# ifndef SIZE_MAP
#  define WIDTH 64
#  define HIGHT 64
# endif

typedef struct s_data
{
	char	**map;
	int		hight;
	int		lenght;
	int		x_player;
	int		y_player;
	int		c_count;
	int		x_exit;
	int		y_exit;
	int		i;
	int		j;
	void	*y_init;
	void	*y_wind;
	void	*y_p;
	void	*y_w;
	void	*y_c;
	void	*y_s;
	void	*y_e;
}			t_data;

void		ft_free_all(char *str, char *str2, char *mess, int fd);
void		ft_error_0(char *str);
void		ft_error_close(char *str, char *mess, int fd);
void		ft_check(char *filename, t_data *data);
char		*ft_free_map(char **str);
int			get_array_size(const char **s);
int			map_surrounded_walls(char **map, int len);
int			validate_map_components(t_data *data);
int			map_rectangular(char **str);
int			flood_fill(t_data *data);
void		move_player_up(t_data *data, char **map, int *i);
void		move_player_down(t_data *data, char **map, int *i);
void		move_player_right(t_data *data, char **map, int *i);
void		move_player_left(t_data *data, char **map, int *i);
void		exit_game(t_data *data);
void		initialize_game(t_data *data);
void		render_game_map(t_data *data);
void		cleanup_and_exit(void *y_init, void *y_wind, int status_exit);
int			window_close(void *ptr);
int			handle_key_press(int key, void *ptr);
void		load_game_textures(t_data *data);

#endif
