/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpogorz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 12:04:48 by anpogorz          #+#    #+#             */
/*   Updated: 2019/10/22 09:46:20 by anpogorz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_charset(char c, char const *set)
{
	int i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		ft_count_trim(char const *s1, char const *set)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (ft_charset(s1[i], set) == 1)
		i++;
	while (s1[i + j] != '\0')
		j++;
	while (ft_charset(s1[i + j - 1], set) == 1)
		j--;
	return (j);
}

char	*ft_charset_null(char const *s1, char *str)
{
	int i;

	i = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (str == 0)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
	
char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!set || !s1)
	{
		str = NULL;
		str = ft_charset_null(s1, str);
		return (str);
	}
	str = malloc(sizeof(char) * (ft_count_trim(s1, set) + 1));
	if (str == 0)
		return (NULL);
	while (ft_charset(s1[i], set) == 1)
		i++;
	while (j < ft_count_trim(s1, set))
	{
		str[j] = s1[i + j];
		j++;
	}
	str[j] = '\0';
	return (str);
}
