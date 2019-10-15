/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpogorz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 08:50:28 by anpogorz          #+#    #+#             */
/*   Updated: 2019/10/15 09:43:53 by anpogorz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void *ptr;
	size_t i;

	i = 0;
	ptr = malloc(count * size);
	if (ptr == 0)
		return (NULL);
	while (i < (count * size))
	{
		ptr = 0;
		i++;
	}
	return (ptr);
}
