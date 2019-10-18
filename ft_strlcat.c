/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpogorz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:41:49 by anpogorz          #+#    #+#             */
/*   Updated: 2019/10/18 11:43:34 by anpogorz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (dst[i] != '\0' && (i < size))
		i++;
	while (src[j] != '\0' && ((j + i) < size))
	{
		dst[i + j] = src[j];
		j++;
	}
	if (size > 0)
		dst[i + j] = '\0';
	return (ft_strlen(dst) + ft_strlen(src));
}
