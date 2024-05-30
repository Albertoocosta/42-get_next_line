/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:14:45 by cda-fons          #+#    #+#             */
/*   Updated: 2024/05/30 17:02:48 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	{
		free(cluster);
		return (NULL);
	}
	word = ftcalloc((ftstrlen(cluster) - i + 1), sizeof(char));
	if (!word)
		return (NULL);
	i++;
	j = 0;
	while (cluster[i])
		word[j++] = cluster[i++];
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
		{
			free(buffer);
			free(cluster);
			return (NULL);
		}
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
	static char		*cluster[4096];
	char			*reader;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	cluster[fd] = readfile(fd, cluster[fd]);
	if (!cluster[fd])
		return (NULL);
	if (cluster[fd][0] == '\0')
	{
		free(cluster[fd]);
		return (NULL);
	}
	reader = ft_get_line(cluster[fd]);
	if (!reader)
		return (NULL);
	cluster[fd] = newcluster(cluster[fd]);
	return (reader);
}

/* #include <stdio.h>
int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	int		fd2;
	int		fd3;

	fd1 = open("test.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	fd3 = open("test3.txt", O_RDONLY);
	i = 1;
	while (i < 7)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd2);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd3);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
} */