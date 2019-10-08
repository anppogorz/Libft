/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpogorz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:39:13 by anpogorz          #+#    #+#             */
/*   Updated: 2019/10/08 15:45:52 by anpogorz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi(const char *str)
{
	int stock;
	int multipl;
	int i;
	int sign;

	multipl = 1;
	stock = 0;
	i = 0;
	sign = 1;
	if (str[i] == 45)
		sign = -1;
	while (str[i] != '\0')
		i++;
	i--;
	while (i > 0)
	{
		stock = stock + (str[i] * multipl);
		multipl = 10 * multipl;
		i--;
	}
	return (stock * sign);
}
