#include "so_long.h"

static int	ft_maplen(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	initialize_game(t_data *data)
{
	data->y_init = mlx_init();
	if (!data->y_init)
	{
		ft_error_close(ft_free_map(data->map), INIT_ERROR, -1);
	}
	data->y_wind = mlx_new_window(data->y_init, ft_strlen(data->map[0]) * HIGHT,
			ft_maplen(data->map) * WIDTH, GAME_NAME);
	if (!data->y_wind)
	{
		ft_free_map(data->map);
		ft_putstr_fd(WINDOW_ERROR, 2);
		cleanup_and_exit(data->y_init, NULL, 1);
	}
	load_game_textures(data);
	render_game_map(data);
	mlx_hook(data->y_wind, 2, 1L << 0, handle_key_press, data);
	mlx_hook(data->y_wind, 17, 0, handle_key_press, data);
	mlx_loop(data->y_init);
}
