/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfinni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:59:04 by tfinni            #+#    #+#             */
/*   Updated: 2023/06/08 12:59:07 by tfinni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_data	*ft_set_img(t_data *data, int x_size, int y_size, char *path)
{
	int	width;
	int	height;

	data->image = mlx_xpm_file_to_image(data->mlx, path, &width, &height);
	mlx_put_image_to_window(data->mlx, data->window, data->image, \
	x_size, y_size);
	return (data);
}

t_data	*img_to_place(char c, int x_size, int y_size, t_data *data)
{
	if (c == '1')
		data = ft_set_img(data, x_size, y_size, "./textures/wall.xpm");
	else if (c == '0')
		data = ft_set_img(data, x_size, y_size, "./textures/background.xpm");
	else if (c == 'P' && data->player.lr == 1)
		data = ft_set_img(data, x_size, y_size, "./textures/player_right.xpm");
	else if (c == 'P' && data->player.lr == 0)
		data = ft_set_img(data, x_size, y_size, "./textures/player_left.xpm");
	else if (c == 'E' && data->player.collected != data->map.collectibles)
		data = ft_set_img(data, x_size, y_size, "./textures/exit_closed.xpm");
	else if (c == 'E' && data->player.collected == data->map.collectibles)
		data = ft_set_img(data, x_size, y_size, "./textures/exit_open.xpm");
	else if (c == 'C')
		data = ft_set_img(data, x_size, y_size, "./textures/collectible.xpm");
	return (data);
}
