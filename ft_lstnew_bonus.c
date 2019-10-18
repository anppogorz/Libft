/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpogorz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 06:59:38 by anpogorz          #+#    #+#             */
/*   Updated: 2019/10/18 11:57:36 by anpogorz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list *ft_lstnew(void *content)
{
	t_list	*new;
	int i;

	i = 0;
	while (content[i] != '\0')
		i++;
	new = (t_list*)malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	if (content == NULL)
		new->content = NULL;
	new->content = malloc(sizeof(t_list) * i);
	if (new->content == NULL)
		return (NULL)
	new->next = NULL;
	return (new);
}
