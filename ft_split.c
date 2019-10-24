/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpogorz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 07:10:45 by anpogorz          #+#    #+#             */
/*   Updated: 2019/10/24 08:36:45 by anpogorz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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
		tab[j] = malloc(sizeof(char) * (k + 1));
		if (tab[j] == NULL)
			return (NULL);
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

char	**ft_free(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != 0)
	{
		free(tab[i]);
		i++;
	}
	free(tab[i]);
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
	tab = ft_strcpy(str, c, tab, nb);
	tab = ft_free(tab);
	return (tab);
}
