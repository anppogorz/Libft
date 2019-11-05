/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpogorz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:52:06 by anpogorz          #+#    #+#             */
/*   Updated: 2019/11/05 10:59:04 by anpogorz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ssrc;
	unsigned char	*ddst;

	i = 0;
	ssrc = (unsigned char *)src;
	ddst = (unsigned char *)dst;
	if (!dst && !src)
		return (0);
	while (i < n)
	{
		ddst[i] = ssrc[i];
		i++;
	}
	return (dst);
}
