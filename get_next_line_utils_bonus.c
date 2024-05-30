/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:16:59 by cda-fons          #+#    #+#             */
/*   Updated: 2024/05/30 17:03:01 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ftstrlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i] != 0)
		i++;
	return (i);
}

char	*ftstrchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str && str[i] != (char)c)
	{
		if (!str[i])
			return (NULL);
		i++;
	}
	return ((char *)&str[i]);
}

void	*ftcalloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	i;

	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < (nmemb * size))
	{
		((char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}

char	*ftstrjoin(char *s1, char *s2)
{
	char	*cat;
	size_t	i;
	size_t	h;

	cat = ftcalloc(((ftstrlen((char *)s1) + ftstrlen((char *)s2))
				+ 1), sizeof(char));
	if (cat == 0)
		return (NULL);
	i = 0;
	while (s1 && s1[i] != 0)
	{
		cat[i] = s1[i];
		i++;
	}
	h = 0;
	while (s2 && s2[h] != 0)
	{
		cat[i] = s2[h];
		h++;
		i++;
	}
	cat[i] = '\0';
	free((void *)s1);
	return (cat);
}

char	*ftstrdup(char *s)
{
	char	*str;
	size_t	i;

	str = (char *)malloc(sizeof(char) * (ftstrlen((char *)s) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] != 0)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
