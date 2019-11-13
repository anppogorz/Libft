/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpogorz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 08:18:29 by anpogorz          #+#    #+#             */
/*   Updated: 2019/11/05 09:53:54 by anpogorz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_LINE_H

#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char	*ft_calloc(char *str, size_t size);
char	*ft_bzero(char *s);
int		ft_strcmp(char *s1, char *s2);
char	*ft_find_sentence(char *s, char **line, char c);
