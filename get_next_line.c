/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:30:07 by cda-fons          #+#    #+#             */
/*   Updated: 2024/05/26 19:24:40 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*newcluster(char *cluster)
{
	char	*word;
	int		i;
	int		j;

	i = 0;
	while (cluster[i] && cluster[i] != '\n')
		i++;
	if (!cluster[i])
		return (free(cluster), NULL);
	word = (char *)ftcalloc((ftstrlen(cluster) - i + 1), sizeof(char));
	if (!word)
		return (NULL);
	i++;
	j = 0;
	while (cluster[i])
	{
		word[j] = cluster[i];
		j++;
		i++;
	}
	word[j] = '\0';
	free(cluster);
	return (word);
}

char	*readfile(int fd, char *cluster)
{
	char	*buffer;
	int		counter;

	buffer = ftcalloc((BUFFER_SIZE + 1), sizeof(char));
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
	char			*reader;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (0);
	cluster = readfile(fd, cluster);
	if (!cluster)
		return (0);
	reader = get_line(cluster);
	cluster = newcluster(cluster);
	return (reader);
}

/* #include <stdio.h>
int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	fd1 = open("test.txt", O_RDONLY);
	i = 1;
	while (i < 11)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd1);
	return (0);
} */