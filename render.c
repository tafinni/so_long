/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfinni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:59:11 by tfinni            #+#    #+#             */
/*   Updated: 2023/06/08 12:59:13 by tfinni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_render_map(t_data *data)
{
	int	x;
	int	y;
	int	x_counter;
	int	y_counter;

	y = 0;
	y_counter = data->map.lines;
	while (y_counter > 0)
	{
		x = 0;
		x_counter = data->map.line_len - 1;
		while (x_counter >= 0)
		{
			data = img_to_place(data->map.map[y][x], \
			x * IMG_SIZE, y * IMG_SIZE, data);
			x++;
			x_counter--;
		}
		y++;
		y_counter--;
	}
}

void	ft_render_player(t_data *data, t_player player, int flag)
{
	data = img_to_place(data->map.map[player.y][player.x], \
	(player.x * IMG_SIZE), (player.y * IMG_SIZE), data);
	if (flag == 1)
			data = img_to_place(data->map.map[player.y + 1][player.x], \
			(player.x * IMG_SIZE), ((player.y + 1) * IMG_SIZE), data);
	else if (flag == 2)
			data = img_to_place(data->map.map[player.y][player.x - 1], \
			((player.x - 1) * IMG_SIZE), (player.y * IMG_SIZE), data);
	else if (flag == 3)
			data = img_to_place(data->map.map[player.y - 1][player.x], \
			(player.x * IMG_SIZE), ((player.y - 1) * IMG_SIZE), data);
	else if (flag == 4)
			data = img_to_place(data->map.map[player.y][player.x + 1], \
			((player.x + 1) * IMG_SIZE), (player.y * IMG_SIZE), data);
}

void	ft_render_exit(t_data *data)
{
		data = img_to_place('E', (data->map.exit_x * IMG_SIZE), \
		(data->map.exit_y * IMG_SIZE), data);
}

static int	ft_key_press(int key, t_data *data)
{
	static int	move_count;

	if (key == 13 || key == 2 || key == 1 || key == 0)
		data = movement(data, key);
	if (key == 53)
		exit (0);
	move_count++;
	return (0);
}

void	ft_render_images_to_position(t_data *data)
{
	mlx_hook(data->window, 17, 1L << 2, ft_exit_game, data);
	mlx_key_hook(data->window, ft_key_press, data);
	ft_render_map(data);
	mlx_string_put(data->mlx, data->window, IMG_SIZE / 2, \
	IMG_SIZE / 3, -255999, "MOVES : 0");
}
