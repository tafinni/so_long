/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfinni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:30:53 by tfinni            #+#    #+#             */
/*   Updated: 2022/11/28 19:10:09 by tfinni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_copy(unsigned int start, char const *s, char *res, size_t len)
{
	unsigned int	x;
	unsigned int	i;

	x = 0;
	i = 0;
	while (start != i)
		i++;
	while (len > 0)
	{
		if (start >= ft_strlen(s))
			res[x] = '\0';
		else
			res[x] = s[i];
		len--;
		x++;
		i++;
	}
	res[x] = '\0';
	return (res);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	res = (char *)malloc(sizeof(char) * len + 1);
	if (!res || !s)
		return (NULL);
	res = ft_copy(start, s, res, len);
	return (&res[0]);
}
