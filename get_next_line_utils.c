/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpogorz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 08:17:58 by anpogorz          #+#    #+#             */
/*   Updated: 2019/11/05 08:18:01 by anpogorz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	if (!(ptr = malloc(sizeof(char) * (size * count))))
		return (NULL);
	ft_bzero(ptr, (count * size));
	return ((void *)ptr);
}

char	*ft_bzero(char *s, size_t n)
{
    size_t			i;
    unsigned char	*str;

    i = 0;
    str = (unsigned char *)s;
    while (i < n)
    {
        str[i] = 0;
        i++;
    }
    return (s);
}

int ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char *str;
	int i;
	int j;

	i = -1;
	j = 0;
	if (!s1)
		return (s2);
    while (s1[++i] != '\0')
		j++;
	i = -1;
	while (s2[++i] != '\0')
		j++;
	if (!(str = (char *)malloc(sizeof(char) * (j + 1))))
		return (NULL);
	while (*s1)
		*str++ = *s1++;
	while (*s2)
		*str++ = *s2++;
	*str = '\0';
	return (str - j);
}

char	*ft_find_sentence(char *readstring, char **line, char c)
{
	int i;
	char *str;

	i = 0;
	while (readstring[i] != '\0')
	{
		if (readstring[i] == c)
		{
			if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
				return (NULL);
			while (i-- > 0)
				str[i] = readstring[i];
			*line = str;
			i++;
			while (str[i] != '\0')
				i++;
			str[i] = '\0';
			if (line == NULL)
				*line = readstring + i + 1;
			return (readstring + i + 1);
		}
		i++;
	}
	return (readstring);
}