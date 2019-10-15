/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpogorz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 07:50:47 by anpogorz          #+#    #+#             */
/*   Updated: 2019/10/15 14:33:45 by anpogorz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long long nbr;
	int sign;

	sign = 1;
	if (n < 0)
		sign = -1;
	nbr = sign * n;
	if (sign == -1)
		ft_putchar_fd('-', fd);
	if (nbr == 0)
		ft_putchar_fd('0', fd);
	while (nbr > 0)
	{
		ft_putchar_fd((nbr % 10), fd);
		nbr = nbr / 10;
	}
}
