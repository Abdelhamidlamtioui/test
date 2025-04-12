/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamtiou <alamtiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 04:33:37 by alamtiou          #+#    #+#             */
/*   Updated: 2025/04/12 05:02:11 by alamtiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_error(t_data *data)
{
	ft_putstr_fd(IMAGE_ERROR, 2);
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
	cleanup_and_exit(data->y_init, data->y_wind, 1);
}

void	load_game_textures(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	data->y_c = mlx_xpm_file_to_image(data->y_init,
			"textures/collectible.xpm", &i, &j);
	if (!data->y_c)
		ft_error(data);
	data->y_e = mlx_xpm_file_to_image(data->y_init,
			"textures/exit.xpm", &i, &j);
	if (!data->y_e)
		ft_error(data);
	data->y_p = mlx_xpm_file_to_image(data->y_init,
			"textures/player.xpm", &i, &j);
	if (!data->y_p)
		ft_error(data);
	data->y_w = mlx_xpm_file_to_image(data->y_init,
			"textures/walls.xpm", &i, &j);
	if (!data->y_w)
		ft_error(data);
	data->y_s = mlx_xpm_file_to_image(data->y_init,
			"textures/freespace.xpm", &i, &j);
	if (!data->y_s)
		ft_error(data);
}

void	render_game_map(t_data *data)
{
	data->i = 0;
	while (data->map[data->i])
	{
		data->j = 0;
		while (data->map[data->i][data->j])
		{
			if (data->map[data->i][data->j] == PLAYER)
				mlx_put_image_to_window(data->y_init, data->y_wind, data->y_p,
					HIGHT * data->j, WIDTH * data->i);
			else if (data->map[data->i][data->j] == WALLS)
				mlx_put_image_to_window(data->y_init, data->y_wind, data->y_w,
					HIGHT * data->j, WIDTH * data->i);
			else if (data->map[data->i][data->j] == FREESPACE)
				mlx_put_image_to_window(data->y_init, data->y_wind, data->y_s,
					HIGHT * data->j, WIDTH * data->i);
			else if (data->map[data->i][data->j] == COLLECT)
				mlx_put_image_to_window(data->y_init, data->y_wind, data->y_c,
					HIGHT * data->j, WIDTH * data->i);
			else if (data->map[data->i][data->j] == EXIT)
				mlx_put_image_to_window(data->y_init, data->y_wind, data->y_e,
					HIGHT * data->j, WIDTH * data->i);
			data->j++;
		}
		data->i++;
	}
}
