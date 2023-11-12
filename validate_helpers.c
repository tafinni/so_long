/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfinni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:59:44 by tfinni            #+#    #+#             */
/*   Updated: 2023/06/08 12:59:47 by tfinni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_map_lines(char **argv, int flag)
{
	char	*str;
	int		fd;
	size_t	compare;
	size_t	lines;

	str = NULL;
	compare = 0;
	lines = 0;
	fd = (char)open(argv[1], O_RDONLY);
	while (flag == 0)
	{
		str = get_next_line(fd);
		if (str == NULL || str[0] == '\n')
			flag = 1;
		else
			free(str);
		lines++;
	}
	close(fd);
	return (--lines);
}

static int	ft_check_next_line(int fd)
{
	char	*str;

	str = get_next_line(fd);
	if (str != NULL)
	{
		free(str);
		ft_error("Inconsistent map line lenght\n");
	}
	return (1);
}

static void	ft_check_if_correct_map_char(char *str)
{
	int	i;

	if (str == NULL)
		ft_error("Not a map\n");
	i = 0;
	while (str[i] == '1' || str[i] == '0' || str[i] == 'C' \
	|| str[i] == 'E' || str[i] == 'P' || str[i] == '\n')
		i++;
	if (!str[i])
		return ;
	if (str[i] != '1' || str[i] != '0' || str[i] != 'C' \
	|| str[i] != 'E' || str[i] != 'P' || str[i] != '\n' || str[i] != '\0')
		ft_error("Map has atleast one forbidden character\n");
}

static void	ft_fd_check(int fd)
{
	if (fd <= 0)
		ft_error("No file\n");
}

size_t	ft_map_line_len(char **argv, int flag, size_t len, size_t cmp)
{
	char	*str;
	int		fd;

	fd = (char)open(argv[1], O_RDONLY);
	ft_fd_check(fd);
	while (flag == 0)
	{
		str = get_next_line(fd);
		ft_check_if_correct_map_char(str);
		if (str == NULL || str[0] == '\n')
			flag = 1;
		else
		{
			len = ft_strlen(str);
			free(str);
			if (cmp == 0)
				cmp = len;
			if (flag == 0 && len - cmp != 0)
				flag = ft_check_next_line(fd);
		}
		if (flag == 1 && cmp - len != 1)
			ft_error("Inconsistent map line lenght\n");
	}
	close(fd);
	return (len);
}
