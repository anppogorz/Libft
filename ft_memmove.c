/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpogorz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:12:11 by anpogorz          #+#    #+#             */
/*   Updated: 2019/10/21 15:08:59 by anpogorz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*ssrc;
	unsigned char	*ddst;

	i = 0;
	ssrc = (unsigned char *)src;
	ddst = (unsigned char *)dst;
	if (src < dst)
	{
		while (len >= i)
		{
			ddst[len] = ssrc[len];
			len--;
		}
	}
	else if (src > dst)
	{
		while (i <= len)
		{
			ddst[i] = ssrc[i];
			i++;
		}
	}
	return (dst);
}
