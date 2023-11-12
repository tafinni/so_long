/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfinni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:03:34 by tfinni            #+#    #+#             */
/*   Updated: 2022/11/26 20:55:08 by tfinni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while ((*str < 14 && *str > 8) || (*str == 32))
			str++;
	if (*str == '-' || *str == '+')
	{			
		if (str[0] == '-')
			sign = -sign;
		str++;
	}
	if (*str < 48 || *str > 57)
		return (0);
	while (*str != '\0' && ft_isdigit((int)*str) > 0)
	{
		if ((*str >= 48) && (*str <= 57))
			result = result * 10 + *str - 48;
		str++;
	}
	return (result * sign);
}
