/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpogorz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 08:50:28 by anpogorz          #+#    #+#             */
/*   Updated: 2019/11/05 07:56:37 by anpogorz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
//	if (!count || !size)
//		return (NULL);
	if (!(ptr = malloc(sizeof(char) * (size * count))))
		return (NULL);
	ft_bzero(ptr, (count * size));
	return ((void *)ptr);
}
