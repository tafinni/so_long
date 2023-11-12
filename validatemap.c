/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validatemap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfinni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:59:52 by tfinni            #+#    #+#             */
/*   Updated: 2023/06/08 12:59:54 by tfinni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_count_amount_of_chars(char c, int flag, t_data **data)
{
	static size_t	collectibles;
	static size_t	exits;
	static size_t	players;

	if (flag == 0)
	{
		if (c == 'E')
			exits++;
		if (c == 'C')
			(*data)->map.collectibles++;
		if (c == 'P')
			players++;
	}
	else
	{
		if ((*data)->map.collectibles == 0)
			ft_error("Not enough collectibles\n");
		if (exits != 1)
			ft_error("Wrong amount of exits in map\n");
		if (players != 1)
			ft_error("Wrong amount of players in map\n");
	}
}

static void	ft_check_amount_of_map_chars(char **argv, int flag, t_data **data)
{
	int		fd;
	int		i;
	char	*str;

	fd = (char)open(argv[1], O_RDONLY);
	while (flag == 0)
	{
		str = get_next_line(fd);
		if (str == NULL)
			flag = 1;
		else
		{
			i = 0;
			while (str[i] != '\0')
			{
				ft_count_amount_of_chars(str[i], 0, data);
				i++;
			}
		}
		if (str != NULL)
			free(str);
		str = NULL;
	}
	close(fd);
	ft_count_amount_of_chars('x', 1, data);
}

static void	ft_check_top_and_bottom_walls(char *str, t_data *data)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1' && i < data->map.line_len - 1)
			ft_error("Edges not blocked\n");
		i++;
	}
}

static void	ft_check_walls(char **argv, t_data *data, int flag, size_t lines)
{
	int		fd;
	char	*str;

	fd = (char)open(argv[1], O_RDONLY);
	while (flag == 0)
	{
		str = get_next_line(fd);
		if (str == NULL)
			flag = 1;
		else
		{
			if (lines == data->map.lines || lines == 1)
				ft_check_top_and_bottom_walls(str, data);
			else
			{
				if (str[0] != '1' || str[data->map.line_len - 1] != '1')
					ft_error("Edges not blocked\n");
			}
			lines--;
		}
		if (str != NULL)
			free(str);
		str = NULL;
	}
	close(fd);
}

int	ft_map_valid(char **argv, t_data *data)
{
	int		fd;
	size_t	lines;

	data->map.lines = ft_map_lines(argv, 0);
	data->map.line_len = ft_map_line_len(argv, 0, 0, 0);
	ft_check_amount_of_map_chars(argv, 0, &data);
	lines = data->map.lines;
	ft_check_walls(argv, data, 0, lines);
	return (0);
}
