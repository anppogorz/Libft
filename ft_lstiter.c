/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpogorz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 08:06:34 by anpogorz          #+#    #+#             */
/*   Updated: 2019/10/24 13:06:07 by anpogorz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list *tmp;

	*tmp = lst;
	while (tmp)
	{
		tmp->content = (*f)(tmp->content);
		tmp = tmp->next;
	}
}
