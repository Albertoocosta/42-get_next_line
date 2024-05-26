/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:37:04 by cda-fons          #+#    #+#             */
/*   Updated: 2024/05/22 19:42:25 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ftstrlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

char	*ftstrchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != (char)c)
	{
		if (!str[i])
			return (0);
		i++;
	}
	return ((char *)&str[i]);
}

char	*ftstrjoin(char const *s1, char const *s2)
{
	char	*cat;
	size_t	i;
	size_t	h;

	cat = malloc(sizeof (char) * ((ft_strlen((char *)s1) + ft_strlen((char *)s2)
					) + 1));
	if (cat == 0)
		return (NULL);
	i = 0;
	while (s1[i] != 0)
	{
		cat[i] = s1[i];
		i++;
	}
	h = 0;
	while (s2[h] != 0)
	{
		cat[i] = s2[h];
		h++;
		i++;
	}
	cat[i] = '\0';
	return (cat);
}