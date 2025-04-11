#include "so_long.h"

int	ft_collect(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == COLLECT)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	move_player_up(t_data *data, char **map, int *i)
{
	int	y;
	int	x;

	y = data->y_player - 1;
	x = data->x_player;
	if (map[y][x] == WALLS)
		return ;
	if (map[y][x] == EXIT && !ft_collect(map))
		exit_game(data);
	if (map[data->y_player][data->x_player] == map[data->y_exit][data->x_exit])
	{
		map[data->y_player][data->x_player] = EXIT;
		map[y][x] = PLAYER;
	}
	else
	{
		map[data->y_player][data->x_player] = FREESPACE;
		map[y][x] = PLAYER;
	}
	ft_printf("Moves : %d\n", ++(*i));
	data->y_player = y;
	data->x_player = x;
}

void	move_player_down(t_data *data, char **map, int *i)
{
	int	y;
	int	x;

	y = data->y_player + 1;
	x = data->x_player;
	if (map[y][x] == WALLS)
		return ;
	if (map[y][x] == EXIT && !ft_collect(map))
		exit_game(data);
	if (map[data->y_player][data->x_player] == map[data->y_exit][data->x_exit])
	{
		map[data->y_player][data->x_player] = EXIT;
		map[y][x] = PLAYER;
	}
	else
	{
		map[data->y_player][data->x_player] = FREESPACE;
		map[y][x] = PLAYER;
	}
	ft_printf("Moves : %d\n", ++(*i));
	data->y_player = y;
	data->x_player = x;
}

void	move_player_left(t_data *data, char **map, int *i)
{
	int	y;
	int	x;

	y = data->y_player;
	x = data->x_player - 1;
	if (map[y][x] == WALLS)
		return ;
	if (map[y][x] == EXIT && !ft_collect(data->map))
		exit_game(data);
	if (map[data->y_player][data->x_player] == map[data->y_exit][data->x_exit])
	{
		map[data->y_player][data->x_player] = EXIT;
		map[y][x] = PLAYER;
	}
	else
	{
		map[data->y_player][data->x_player] = FREESPACE;
		map[y][x] = PLAYER;
	}
	ft_printf("Moves : %d\n", ++(*i));
	data->y_player = y;
	data->x_player = x;
}

void	move_player_right(t_data *data, char **map, int *i)
{
	int	y;
	int	x;

	y = data->y_player;
	x = data->x_player + 1;
	if (map[y][x] == WALLS)
		return ;
	if (map[y][x] == EXIT && !ft_collect(data->map))
		exit_game(data);
	if (map[data->y_player][data->x_player] == map[data->y_exit][data->x_exit])
	{
		map[data->y_player][data->x_player] = EXIT;
		map[y][x] = PLAYER;
	}
	else
	{
		map[data->y_player][data->x_player] = FREESPACE;
		map[y][x] = PLAYER;
	}
	ft_printf("Moves : %d\n", ++(*i));
	data->y_player = y;
	data->x_player = x;
}
