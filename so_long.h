/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfinni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:59:31 by tfinni            #+#    #+#             */
/*   Updated: 2023/06/08 12:59:33 by tfinni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <fcntl.h>
# include "libft/libft.h"

# define IMG_SIZE 64

typedef struct s_place
{
	int	x;
	int	y;
}	t_place;

typedef struct s_map
{
	char	**map;
	size_t	lines;
	size_t	line_len;
	size_t	collectibles;
	int		exit_y;
	int		exit_x;
}	t_map;

typedef struct s_player
{
	int	y;
	int	x;
	int	collected;
	int	moves;
	int	lr;
	int	was_exit;
}	t_player;

typedef struct s_data
{
	void			*mlx;
	void			*window;
	void			*image;
	t_map			map;
	t_player		player;
}	t_data;

t_data	*count_moves(t_data *data);
t_data	*player_lr(t_data *data, int key);
t_data	*save_values(t_data *data, int flag, int i, int x);
t_data	*move(t_data *data, int flag, int y, int x);
t_data	*movement(t_data *data, int key);
t_data	*img_to_place(char c, int x_size, int y_size, t_data *data);
size_t	ft_map_line_len(char **argv, int flag, size_t len, size_t cmp);
size_t	ft_map_lines(char **argv, int flag);
void	ft_render_images_to_position(t_data *data);
void	ft_render_map(t_data *data);
void	ft_render_exit(t_data *data);
void	ft_render_player(t_data *data, t_player player, int flag);
void	ft_free_map(t_data *data);
void	ft_error(char *str);
int		ft_map_valid(char **argv, t_data *data);
int		ft_exit_game(t_data *data);

#endif
