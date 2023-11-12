/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfinni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:58:23 by tfinni            #+#    #+#             */
/*   Updated: 2023/06/08 12:58:24 by tfinni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_data	*move_up(t_data *data, int y, int x, char **map)
{
	if (map[y - 1][x] && map[y - 1][x] == '0')
	{
		data = move(data, 1, y, x);
		ft_render_player(data, data->player, 1);
	}
	else if (map[y - 1][x] && map[y - 1][x] == 'C')
	{
		data->player.collected++;
		data = move(data, 1, y, x);
		ft_render_player(data, data->player, 1);
	}
	else if (map[y - 1][x] && map[y - 1][x] == 'E' \
	&& data->player.collected == data->map.collectibles)
	{
		data = count_moves(data);
		ft_exit_game(data);
	}
	else if (map[y - 1][x] && map[y - 1][x] == 'E')
	{
		data = move(data, 1, y, x);
		data->player.was_exit = 1;
		ft_render_player(data, data->player, 1);
	}
	return (data);
}

static t_data	*move_right(t_data *data, int y, int x, char **map)
{
	if (map[y][x + 1] && map[y][x + 1] == '0')
	{
		data = move(data, 2, y, x);
		ft_render_player(data, data->player, 2);
	}
	else if (map[y][x + 1] && map[y][x + 1] == 'C')
	{
		data->player.collected++;
		data = move(data, 2, y, x);
		ft_render_player(data, data->player, 2);
	}
	else if (map[y][x + 1] && map[y][x + 1] == 'E' \
	&& data->player.collected == data->map.collectibles)
	{
		data = count_moves(data);
		ft_exit_game(data);
	}
	else if (map[y][x + 1] && map[y][x + 1] == 'E')
	{
		data = move(data, 2, y, x);
		data->player.was_exit = 1;
		ft_render_player(data, data->player, 2);
	}
	return (data);
}

static t_data	*move_down(t_data *data, int y, int x, char **map)
{
	if (map[y + 1][x] && map[y + 1][x] == '0')
	{
		data = move(data, 3, y, x);
		ft_render_player(data, data->player, 3);
	}
	else if (map[y + 1][x] && map[y + 1][x] == 'C')
	{
		data->player.collected++;
		data = move(data, 3, y, x);
		ft_render_player(data, data->player, 3);
	}
	else if (map[y + 1][x] && map[y + 1][x] == 'E' \
	&& data->player.collected == data->map.collectibles)
	{
		data = count_moves(data);
		ft_exit_game(data);
	}
	else if (map[y + 1][x] && map[y + 1][x] == 'E')
	{
		data = move(data, 3, y, x);
		data->player.was_exit = 1;
		ft_render_player(data, data->player, 3);
	}
	return (data);
}

static t_data	*move_left(t_data *data, int y, int x, char **map)
{
	if (map[y][x - 1] && map[y][x - 1] == '0')
	{
		data = move(data, 4, y, x);
		ft_render_player(data, data->player, 4);
	}
	else if (map[y][x - 1] && map[y][x - 1] == 'C')
	{
		data->player.collected++;
		data = move(data, 4, y, x);
		ft_render_player(data, data->player, 4);
	}
	else if (map[y][x - 1] && map[y][x - 1] == 'E' \
	&& data->player.collected == data->map.collectibles)
	{
		data = count_moves(data);
		ft_exit_game(data);
	}
	else if (map[y][x - 1] && map[y][x - 1] == 'E')
	{
		data = move(data, 4, y, x);
		data->player.was_exit = 1;
		ft_render_player(data, data->player, 4);
	}
	return (data);
}

t_data	*movement(t_data *data, int key)
{
	int		y;
	int		x;
	char	**map;

	data = player_lr(data, key);
	y = data->player.y;
	x = data->player.x;
	map = data->map.map;
	if (key == 13)
		data = move_up(data, y, x, map);
	if (key == 2)
		data = move_right(data, y, x, map);
	if (key == 1)
		data = move_down(data, y, x, map);
	if (key == 0)
		data = move_left(data, y, x, map);
	if (data->player.collected == data->map.collectibles)
		ft_render_exit(data);
	return (data);
}
