/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpogorz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:12:11 by anpogorz          #+#    #+#             */
/*   Updated: 2019/10/08 18:10:40 by anpogorz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t i;

	i = 0;
	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	if (s < d)
	{
		while (len >= i)
		{
			d[len] = s[len];
			len--;
		}
	}
	if (s > d)
	{
		while (i <= len)
		{
			d[i] = s[i]
			i++;
		}
	}
	return (dst)
}
