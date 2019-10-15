/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpogorz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 07:25:28 by anpogorz          #+#    #+#             */
/*   Updated: 2019/10/15 11:43:42 by anpogorz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		ft_strllen(char const *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int i;
	char *str;

	i = 0;
	str = malloc(sizeof(char) * (ft_strllen(s) + 1));
	if (str == 0)
		return (NULL);
	while (i < ft_strllen(s))
	{
		
		str[i] = (*f)(i, str[i]);
		i++;
	}
	return (str);
}
