/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:37:04 by cda-fons          #+#    #+#             */
/*   Updated: 2024/05/26 18:33:36 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
			return (0);
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
		return (0);
	i = 0;
	while (i < (nmemb * size))
	{
		((char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}

char	*ftstrjoin(char const *s1, char const *s2)
{
	char	*cat;
	size_t	i;
	size_t	h;

	cat = ftcalloc(((ftstrlen((char *)s1) + ftstrlen((char *)s2)) + 1), sizeof(char));
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

char	*get_line(char *cluster)
{
	char	*word;
	int		i;

	i = 0;
	while (cluster[i] && cluster[i] != '\n')
		i++;
	word = (char *)ftcalloc((i + 2), sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (cluster[i] && cluster[i] != '\n')
	{
		word[i] = cluster[i];
		i++;
	}
	if (cluster[i] == '\n')
	{
		word[i] = cluster[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}
