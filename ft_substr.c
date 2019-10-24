/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpogorz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 11:43:49 by anpogorz          #+#    #+#             */
/*   Updated: 2019/10/23 11:11:48 by anpogorz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*new;

	i = 0;
	if (!s)
		return (NULL);
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (new == 0)
		return (NULL);
	while (i < len)
	{
		new[i] = s[(unsigned int)i + start];
		i++;
	}
	new[i] = '\0';
	return (new);
}
