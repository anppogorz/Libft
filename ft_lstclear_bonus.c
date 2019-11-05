/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpogorz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 09:56:16 by anpogorz          #+#    #+#             */
/*   Updated: 2019/10/31 08:37:45 by anpogorz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *tmp;

	tmp = *lst;
	if (lst && del)
	{
		while (tmp != NULL)
		{
			(*del)(tmp->content);
			free(tmp);
			tmp = tmp->next;
		}
		free(tmp);
		*lst = NULL;
	}
	return ;
}
