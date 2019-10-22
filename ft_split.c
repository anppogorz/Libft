/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpogorz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 07:10:45 by anpogorz          #+#    #+#             */
/*   Updated: 2019/10/22 11:20:52 by anpogorz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_skip(char str, char *charset)
{
	int j;

	j = 0;
	while (charset[j] != '\0')
	{
		if (str == charset[j])
			return (1);
		j++;
	}
	return (0);
}

char	**ft_malloc(char *str, char *charset, char **tab, int nb)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i] != '\0' && j < nb)
	{
		while (ft_skip(str[i], charset) == 1 && str[i] != '\0')
			i++;
		while (ft_skip(str[i], charset) == 0 && str[i] != '\0')
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

int		ft_words(char *str, char *charset)
{
	int i;
	int l;

	i = 0;
	l = 1;
	while (ft_skip(str[i], charset) == 1)
	{
		i++;
		if (str[i] == '\0')
			l = 0;
	}
	while (str[i] != '\0')
	{
		if ((ft_skip(str[i], charset) == 1 && ft_skip(str[i + 1], charset) == 0
					&& str[i + 1] != '\0'))
			l++;
		i++;
	}
	return (l);
}

char	**ft_strcpy(char *str, char *charset, char **tab, int nb)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (j < nb && str[i] != '\0')
	{
		while (ft_skip(str[i], charset) == 1 && str[i] != '\0')
			i++;
		while (ft_skip(str[i], charset) == 0 && str[i] != '\0')
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

char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int		nb;

	nb = 0;
	nb = ft_words(str, charset);
	tab = malloc(sizeof(char **) * (nb + 1));
	if (tab == NULL)
		return (0);
	tab = ft_malloc(str, charset, tab, nb);
	tab = ft_strcpy(str, charset, tab, nb);
	return (tab);
}
