/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:31:38 by cda-fons          #+#    #+#             */
/*   Updated: 2024/05/26 15:21:00 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ftstrchr(const char *str, int c);
void	*ftcalloc(size_t nmemb, size_t size);
char	*ftstrjoin(char const *s1, char const *s2);
char	*newcluster(char *cluster);
char	*get_line(char *cluster);
char	*readfile(int fd, char *cluster);
size_t	ftstrlen(const char *str);

#endif