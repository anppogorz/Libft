/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpogorz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 13:43:04 by anpogorz          #+#    #+#             */
/*   Updated: 2019/10/08 13:58:17 by anpogorz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*strrchr(const char *s, int c)
{
	while (str[i] != '\0')
		i++;
	while ((str[i] != char(c) && i > 0)
		i--;
	return ((char *)(s + i));
}
