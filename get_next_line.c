/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:30:07 by cda-fons          #+#    #+#             */
/*   Updated: 2024/05/20 21:07:50 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*cluster;
	char		*reader;
	int	i;
	int	j;

	i = 0;
	j = 0;
	cluster = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	reader = (read(fd, cluster, BUFFER_SIZE));
	while (cluster[i] != '\n' && cluster[i])
		i++;
	if (cluster[i] == '\n')
	{
		while (j < i)
			write(1, cluster[j], 1);
	}
	
}
