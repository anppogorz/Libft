/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpogorz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:12:11 by anpogorz          #+#    #+#             */
/*   Updated: 2019/11/05 11:22:14 by anpogorz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*ssrc;
	char	*ddst;

	i = 0;
	ssrc = (char *)src;
	ddst = (char *)dst;
	if (!dst && !src)	
		return (0);
	if (ssrc < ddst)
		while (len > i)
		{
			ddst[len - 1] = ssrc[len - 1];
			len --;
		}
	else
		while (i < len)
		{
			ddst[i] = ssrc[i];
			i++;
		}
	return (dst);
}
