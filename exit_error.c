/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfinni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:58:09 by tfinni            #+#    #+#             */
/*   Updated: 2023/06/08 12:58:11 by tfinni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_map(t_data *data)
{
	int	i;

	i = data->map.lines;
	while (i >= 0)
	{
		free(data->map.map[i]);
		i--;
	}
	free(data->map.map);
}

void	ft_error(char *str)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	exit(0);
}

int	ft_exit_game(t_data *data)
{
	int	i;

	i = 0;
	ft_free_map(data);
	mlx_destroy_window(data->mlx, data->window);
	exit(0);
	return (0);
}
