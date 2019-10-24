/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpogorz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 08:08:29 by anpogorz          #+#    #+#             */
/*   Updated: 2019/10/24 13:28:07 by anpogorz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *tmp;
	size_t size;

	tmp = (t_list *)malloc(sizeof(t_list));
	if (tmp == NULL)
		return (NULL);
	tmp = NULL;
	while (lst)
	{
		lst->content = (*f)(lst->content);
		size = ft_strlen((char)lst->content);
		tmp->content = malloc(sizeof(t_list) * size);
		if (tmp->content == NULL)
			return (NULL);
		tmp->content = ft_memccpy(tmp->content, lst->content, size);
		lst = lst->next;
	}
	return (tmp)
}
