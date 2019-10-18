/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpogorz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 11:43:49 by anpogorz          #+#    #+#             */
/*   Updated: 2019/10/18 11:45:05 by anpogorz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*new;

	i = 0;
	new = malloc(sizeof(s) * (len + 1));
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
