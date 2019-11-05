/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpogorz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 13:30:14 by anpogorz          #+#    #+#             */
/*   Updated: 2019/11/05 11:05:30 by anpogorz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ss;

	i = 0;
	ss = (char *)s;
	while (ss[i] != (unsigned char)c)
	{
		if (ss[i] == '\0')
			return (NULL);
		i++;
	}
	return ((char *)(s + i));
}
