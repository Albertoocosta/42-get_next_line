/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:30:07 by cda-fons          #+#    #+#             */
/*   Updated: 2024/05/22 21:05:51 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*cluster;
	int	reader;

	cluster = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!cluster)
		return (0);
	reader = (read(fd, cluster, BUFFER_SIZE));
	if (reader <= 0)
		free(cluster);
		return (0);	
	return (cluster);
}
