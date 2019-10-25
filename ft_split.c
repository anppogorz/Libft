/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpogorz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 07:10:45 by anpogorz          #+#    #+#             */
/*   Updated: 2019/10/24 14:54:22 by anpogorz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_free(char **tab, int nb)
{
	while (nb > 0)
	{
		free(tab[nb]);
		nb--;
	}
	free(tab);
	return (tab);
}

char	**ft_malloc(char *str, char c, char **tab, int nb)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i] != '\0' && j < nb)
	{
		while (str[i] == c && (str[i] != '\0'))
			i++;
		while (str[i] != c && (str[i] != '\0'))
		{
			i++;
			k++;
		}
		if (!(tab[j] = malloc(sizeof(char) * (k + 1))))
			return (ft_free(tab, (j - 1)));
		k = 0;
		j++;
	}
	return (tab);
}

int		ft_words(char *str, char c)
{
	int i;
	int l;

	i = 0;
	l = 1;
	while (str[i] == c)
	{
		i++;
		if (str[i] == '\0')
			l = 0;
	}
	while (str[i] != '\0')
	{
		if ((str[i] == c) && (str[i + 1] != c) && (str[i + 1] != '\0'))
			l++;
		i++;
	}
	return (l);
}

char	**ft_strcpy(char *str, char c, char **tab, int nb)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (j < nb && str[i] != '\0')
	{
		while (str[i] == c && (str[i] != '\0'))
			i++;
		while (str[i] != c && (str[i] != '\0'))
		{
			tab[j][k] = str[i];
			k++;
			i++;
		}
		tab[j][k] = '\0';
		j++;
		k = 0;
	}
	tab[j] = 0;
	return (tab);
}

char	**ft_split(char *str, char c)
{
	char	**tab;
	int		nb;

	if (!str)
		return (NULL);
	nb = 0;
	nb = ft_words(str, c);
	tab = malloc(sizeof(char **) * (nb + 1));
	if (tab == NULL)
		return (0);
	tab = ft_malloc(str, c, tab, nb);
	if (tab == NULL)
		return (tab);
	tab = ft_strcpy(str, c, tab, nb);
	return (tab);
}
