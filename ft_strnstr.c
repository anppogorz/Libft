/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpogorz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:59:14 by anpogorz          #+#    #+#             */
/*   Updated: 2019/10/16 15:15:52 by anpogorz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t loc)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && (i < loc))
	{
		while (haystack[i] == needle[j])
		{
			i++;
			j++;
			if (needle[j] == '\0' && (i < loc))
				return ((char *)haystack + (i - j));
		}
		j = 0;
		i++;
	}
	return (NULL);
}
