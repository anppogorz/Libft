/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpogorz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:05:18 by anpogorz          #+#    #+#             */
/*   Updated: 2019/10/18 11:37:45 by anpogorz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*ssrc;
	unsigned char	*ddst;

	i = 0;
	ssrc = (unsigned char *)src;
	ddst = (unsigned char *)dst;
	while (i < n)
	{
		ddst[i] = ssrc[i];
		if (ssrc[i] == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
