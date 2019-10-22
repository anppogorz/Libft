/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpogorz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:12:11 by anpogorz          #+#    #+#             */
/*   Updated: 2019/10/22 15:01:05 by anpogorz         ###   ########.fr       */
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
	if (ssrc > ddst)
	{
		while (len > i)
		{
			ddst[i] = ssrc[i];
			i++;
		}
	}
	else
	{
		while (i <= len)
		{
			ddst[len - i] = ssrc[len - i];
			i++;
		}
	}
	return (dst);
}
