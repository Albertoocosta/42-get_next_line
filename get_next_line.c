/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:30:07 by cda-fons          #+#    #+#             */
/*   Updated: 2024/05/26 14:38:36 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*readfile(int fd, char *cluster)
{
	char	*buffer;
	int	counter;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	counter = 1;
	while (!ftstrchr(cluster, '\n') && counter != 0)
	{
		counter = read(fd, buffer, BUFFER_SIZE);
		if (counter == -1)
			return (free(buffer), NULL);
		buffer[counter] = '\0';
		cluster = ftstrjoin(cluster, buffer);
	}
	free(buffer);
	return (cluster);
}

char	*get_next_line(int fd)
{
	static char		*cluster;
	char			reader;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	cluster = readfile(fd, cluster);
	if (!cluster)
		return (0);
	reader = get_line(cluster);
	cluster = newcluster(cluster);
	return (reader);
}
