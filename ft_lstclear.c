/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpogorz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 07:43:02 by anpogorz          #+#    #+#             */
/*   Updated: 2019/10/24 11:24:34 by anpogorz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *tmp;

	*tmp = *lst;
	while (tmp)
	{
		tmp->content = (*del)(tmp->content);
		free(tmp->content);
		tmp = tmp->next;
	}
	*tmp = NULL;
}
