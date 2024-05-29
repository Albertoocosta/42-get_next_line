/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:30:07 by cda-fons          #+#    #+#             */
/*   Updated: 2024/05/29 21:13:59 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char *cluster)
{
	char	*word;
	int		i;

	i = 0;
	while (cluster[i] && cluster[i] != '\n')
		i++;
	if (cluster[i] == '\n')
		i++;
	word = (char *)ftcalloc((i + 1), sizeof(char));
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

char	*newcluster(char *cluster)
{
	char	*word;
	int		i;
	int		j;

	i = 0;
	while (cluster && cluster[i] && cluster[i] != '\n')
		i++;
	if (cluster[i] == '\0')
		return (free(cluster), NULL);
	word = ftcalloc((ftstrlen(cluster) - i + 1), sizeof(char));
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
	while (counter != 0)
	{
		counter = read(fd, buffer, BUFFER_SIZE);
		if (counter < 0)
			return (free(buffer), free(cluster), NULL);
		buffer[counter] = '\0';
		if (!cluster)
			cluster = ftstrdup("");
		cluster = ftstrjoin(cluster, buffer);
		if (ftstrchr(cluster, '\n'))
			break ;
	}
	free(buffer);
	return (cluster);
}

char	*get_next_line(int fd)
{
	static char		*cluster;
	char			*reader;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	cluster = readfile(fd, cluster);
	if (!cluster)
		return (NULL);
	if (cluster[0] == '\0')
		return (NULL);
	reader = ft_get_line(cluster);
	if (!reader)
		return (NULL);
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
	printf("Buffer size > %d", BUFFER_SIZE);
	line = get_next_line(fd1);
	while (line != 0)
	{
		printf("line [%02d]:%s", i, line);
		free(line);
		line = get_next_line(fd1);
		i++;
	}
	printf("line [%02d]:%s", i, line);
	close(fd1);
	return (0);
} */