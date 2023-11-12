/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfinni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:58:16 by tfinni            #+#    #+#             */
/*   Updated: 2023/06/08 12:58:18 by tfinni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_data	*count_moves(t_data *data)
{
	char	*count;
	char	*str;

	img_to_place('1', 0, 0, data);
	img_to_place('1', IMG_SIZE, 0, data);
	img_to_place('1', IMG_SIZE + IMG_SIZE, 0, data);
	data->player.moves++;
	count = ft_itoa(data->player.moves);
	str = ft_strjoin("MOVES : ", count);
	mlx_string_put(data->mlx, data->window, IMG_SIZE / 2, \
	IMG_SIZE / 3, -255999, str);
	free(str);
	free(count);
	return (data);
}

t_data	*player_lr(t_data *data, int key)
{
	if (key == 2)
		data->player.lr = 1;
	else if (key == 0)
		data->player.lr = 0;
	return (data);
}

t_data	*save_values(t_data *data, int flag, int i, int x)
{
	if (flag == 1)
	{
		data->player.y = i;
		data->player.x = x;
	}
	else if (flag == 2)
	{
		data->map.exit_y = i;
		data->map.exit_x = x;
	}
	else if (flag == 3)
	{
		data->map.collectibles = 0;
		data->map.map = NULL;
		data->player.collected = 0;
		data->player.moves = 0;
		data->player.was_exit = 0;
		data->player.lr = 1;
	}
	return (data);
}

static t_data	*was_previous_exit(t_data *data, int y, int x)
{
	if (data->player.was_exit == 1)
		data->map.map[y][x] = 'E';
	else
		data->map.map[y][x] = '0';
	data->player.was_exit = 0;
	return (data);
}

t_data	*move(t_data *data, int flag, int y, int x)
{
	data = was_previous_exit(data, y, x);
	if (flag == 1)
	{
		data->map.map[y - 1][x] = 'P';
		data->player.y--;
	}
	else if (flag == 2)
	{
		data->map.map[y][x + 1] = 'P';
		data->player.x++;
	}
	else if (flag == 3)
	{
		data->map.map[y + 1][x] = 'P';
		data->player.y++;
	}
	else if (flag == 4)
	{
		data->map.map[y][x - 1] = 'P';
		data->player.x--;
	}
	data = count_moves(data);
	return (data);
}
