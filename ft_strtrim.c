/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpogorz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 12:04:48 by anpogorz          #+#    #+#             */
/*   Updated: 2019/10/11 13:51:04 by anpogorz         ###   ########.fr       */
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

int		ft_count(char const *s1, char const *set)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (ft_charset(s1[i], set) == 1)
		i++;
	i = 0;
	while (s1[i + j] != '\0')
		j++;
	j--;
	while (ft_charset(s1[i + j], set) == 1)
		j--;
	return (j);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int i;
	int j;
	char *str;

	i = 0;
	j = 0;
	str = malloc(sizeof(char) * (ft_count(s1, set) + 1));
	if (str == 0)
		return (NULL);
	while (ft_charset(s1[i], set) == 1)
		i++;
	while (j < ft_count(s1, set))
	{
		str[j] = s1[i + j];
		j++;
	}
	str[j] = '\0';
	return (str);
}
