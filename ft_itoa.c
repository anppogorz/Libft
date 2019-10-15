/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpogorz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 06:59:03 by anpogorz          #+#    #+#             */
/*   Updated: 2019/10/15 11:31:23 by anpogorz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_count(long long nbr, int sign)
{
	int i;

	i = 0;	
	if (nbr == 0)
		return (1);
	if (sign == -1)
		i = 1;
	(void)sign;
	while (nbr > 0)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

char	*ft_nbr(char *str, long long nbr, int sign)
{
	int i;

	i = 0;
	if (sign == -1)
	{
		str[i] = '-';
		i++;
	}
	while (nbr > 0)
	{
		str[i] = nbr % 10;
		nbr = nbr / 10;
		i++;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int i;
	int sign;
	long long nbr;
	char *str;
	

	sign = 1;
	if (n < 0)
		sign = -1;
	nbr = sign * n;
	i = ft_count(nbr, sign);
	str = malloc(sizeof(char) * (i + 1));
	if (str == 0)
		return (NULL);
	str = ft_nbr(str, nbr, sign);
	return (str);
}
