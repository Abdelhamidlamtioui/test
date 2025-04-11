#include "so_long.h"

void	exit_game(t_data *data)
{
	if (data->y_c)
		mlx_destroy_image(data->y_init, data->y_c);
	if (data->y_w)
		mlx_destroy_image(data->y_init, data->y_w);
	if (data->y_e)
		mlx_destroy_image(data->y_init, data->y_e);
	if (data->y_p)
		mlx_destroy_image(data->y_init, data->y_p);
	if (data->y_s)
		mlx_destroy_image(data->y_init, data->y_s);
	ft_free_map(data->map);
	cleanup_and_exit(data->y_init, data->y_wind, 0);
}

void	cleanup_and_exit(void *y_init, void *y_wind, int status_exit)
{
	if (y_wind != NULL)
		mlx_destroy_window(y_init, y_wind);
	if (y_init != NULL)
	{
		mlx_destroy_display(y_init);
		free(y_init);
	}
	exit(status_exit);
}

int	handle_key_press(int key, void *ptr)
{
	t_data		*data;
	static int	i;

	data = (t_data *)ptr;
	if (key == XK_Escape)
		exit_game(data);
	if (key == XK_w)
		move_player_up(data, data->map, &i);
	if (key == XK_s)
		move_player_down(data, data->map, &i);
	if (key == XK_d)
		move_player_right(data, data->map, &i);
	if (key == XK_a)
		move_player_left(data, data->map, &i);
	render_game_map(data);
	return (0);
}

int	window_close(void *ptr)
{
	t_data	*data;

	data = (t_data *)ptr;
	exit_game(data);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (ft_putstr_fd(INPUT_ERROR, 2), 1);
	ft_memset(&data, 0, sizeof(t_data));
	ft_check(av[1], &data);
	initialize_game(&data);
}
