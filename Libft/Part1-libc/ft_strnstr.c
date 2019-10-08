/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpogorz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:59:14 by anpogorz          #+#    #+#             */
/*   Updated: 2019/10/08 15:35:12 by anpogorz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t loc)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (needle[i] == '\0')
		return (haystack);
	while (haystack[i] != '\0')
	{
		while ((haystack[i] == needle[j]) && (haystack[i] != '\0'))
		{
			if (j == (int)loc)
				return (haystack + (i - j));
			i++;
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}
