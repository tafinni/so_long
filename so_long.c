/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfinni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:59:17 by tfinni            #+#    #+#             */
/*   Updated: 2023/06/08 12:59:20 by tfinni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_data	*ft_if_p_e_c(t_data *data, int i, int x)
{
	if (data->map.map[i][x] == 'C')
		data->map.collectibles++;
	else if (data->map.map[i][x] == 'P')
		data = save_values(data, 1, i, x);
	else if (data->map.map[i][x] == 'E')
		data = save_values(data, 2, i, x);
	return (data);
}

static void	ft_get_map(char **argv, t_data *data, int lines, int i)
{
	int			fd;
	int			x;

	data->map.collectibles = 0;
	fd = (char)open(argv[1], O_RDONLY);
	if (data->map.map != NULL)
		ft_free_map(data);
	data->map.map = ft_calloc(lines, sizeof(char **));
	if (!data->map.map)
		ft_error("Failed to malloc() data->map.map\n");
	while (--lines > 0)
	{
		data->map.map[++i] = get_next_line(fd);
		if (data->map.map[i] == NULL)
		{
			ft_free_map(data);
			ft_error("Failed to get_next_line() data->map.map[i]");
		}
		x = -1;
		while (data->map.map[i][++x] != '\0')
			data = ft_if_p_e_c(data, i, x);
	}
	close(fd);
}

static void	ft_ber_check(char *str)
{
	char	*res;

	res = ft_strnstr(str, ".ber\0", ft_strlen(str));
	if (res == NULL)
		ft_error("Wrong file format\n");
	res = res + 4;
	if (*res != '\0')
		ft_error("Wrong file format\n");
}

static int	ft_path_check(t_data *data, char **map, int y, int x)
{
	static int	col;
	static int	end;

	if (y < 0 || x < 0 || y >= data->map.lines || x >= data->map.line_len)
		return (0);
	else if (map[y][x] == 'X' || map[y][x] == '1')
		return (0);
	else if (map[y][x] == 'C')
		col++;
	else if (map[y][x] == 'E')
		end++;
	map[y][x] = 'X';
	ft_path_check(data, map, y + 1, x);
	ft_path_check(data, map, y - 1, x);
	ft_path_check(data, map, y, x + 1);
	ft_path_check(data, map, y, x - 1);
	if (col != data->map.collectibles || end != 1)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data		data;

	if (argc != 2)
		ft_error("Wrong amount of arguments");
	if (argv[1] == NULL)
		ft_error("No map file\n");
	ft_ber_check(argv[1]);
	save_values(&data, 3, 0, 0);
	ft_map_valid(argv, &data);
	save_values(&data, 3, 0, 0);
	ft_get_map(argv, &data, (data.map.lines + 1), -1);
	if (!ft_path_check(&data, data.map.map, data.player.y, data.player.x))
	{
		ft_free_map(&data);
		ft_error("No valid path\n");
	}
	ft_get_map(argv, &data, (data.map.lines + 1), -1);
	data.mlx = mlx_init();
	if (!data.mlx)
		ft_error("mlx_init fail\n");
	data.window = mlx_new_window(data.mlx, \
	(data.map.line_len * IMG_SIZE), (data.map.lines * IMG_SIZE), "./so_long");
	ft_render_images_to_position(&data);
	mlx_loop(data.mlx);
	return (0);
}
