/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpogorz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:12:11 by anpogorz          #+#    #+#             */
/*   Updated: 2019/10/24 14:17:44 by anpogorz         ###   ########.fr       */
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
	if (len == 0 || src == dst)
		return (dst);
	if (ssrc > ddst)
	{
		i--;
		while (len > ++i)
			ddst[i] = ssrc[i];
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
