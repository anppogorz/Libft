/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpogorz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 08:17:19 by anpogorz          #+#    #+#             */
/*   Updated: 2019/11/05 12:41:49 by anpogorz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	check_errors(int fd)
{
	if (fd < 0)
		return (-1);
	return (0);
}

int	check_sentence(char *rest, char c)
{
	int i;

	i = 0;
	if (!rest)
	    return (0);
	while (rest[i] != '\0')
	{
		if (rest[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char *ft_malloc(char *str)
{
    char *str_malloc;
    int i;

    i = 0;
    while (str[i] != '\0')
        i++;
    str_malloc = (char *)malloc(sizeof(char) * i);
    i = 0;
    while (str[i] != '\0')
    {
        str_malloc[i] = str[i];
        i++;
    }
    str_malloc[i] = '\0';
    return (str_malloc);
}

int get_next_line(int fd, char **line)
{
	static int ret;
	static char *rest;
	char *buffer;
	char *readstr;

	if (check_errors(fd) == -1)
		return (-1);
	if (check_sentence(rest, '0') == 1)
	{
		rest = ft_find_sentence(rest, line, '0');
		return (1);
	}
	buffer = ft_calloc(1, BUFFER_SIZE + 1);
	while ((ret = read(fd, buffer, BUFFER_SIZE)) != 0)
	{
		buffer[ret] = '\0';
		readstr = ft_malloc(ft_strjoin(rest, buffer));
		printf("rest avant: %s\n", rest);
		rest = ft_find_sentence(readstr, line, '0');
		printf("rest apres: %s\n", rest);
		if (strcmp(rest, readstr) != 0)
			return (1);
		buffer = ft_bzero(buffer, BUFFER_SIZE + 1);
	}
	return (0);
}