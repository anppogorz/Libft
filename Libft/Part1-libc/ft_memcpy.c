/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpogorz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:52:06 by anpogorz          #+#    #+#             */
/*   Updated: 2019/10/08 18:11:02 by anpogorz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void	*dst, const void *src, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		(unsigned char)dst[i] = (unsigned char)src[i];
		i++;
	}
	return (dst);
}
