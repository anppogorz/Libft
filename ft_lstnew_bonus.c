/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpogorz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 06:59:38 by anpogorz          #+#    #+#             */
/*   Updated: 2019/10/24 13:34:57 by anpogorz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list*)malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->content = malloc(sizeof(t_list) * ft_strlen(content));
	if (new->content == NULL)
		return (NULL);
	new->content = ft_memcpy(new->content, content, ft_strlen(content));
	new->next = NULL;
	return (new);
}
