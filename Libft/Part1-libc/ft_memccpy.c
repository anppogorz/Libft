/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpogorz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:05:18 by anpogorz          #+#    #+#             */
/*   Updated: 2019/10/08 17:45:36 by anpogorz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *restrict dst, const void *restrict src, int c, size_t n)
{
	int i;

	i = 0;
	while (i < (int)n)
	{
		if ((char)dst[i] == (char)c)
			return (dst + i + 1)
		(char)dst[i] = (char)src[i];
		i++;
	}
	return (NULL);
}
