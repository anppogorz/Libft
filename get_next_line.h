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
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 100

#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void	*ft_calloc(size_t count, size_t size);
char	*ft_bzero(char *s, size_t n);
int		ft_strcmp(char *s1, char *s2);
char	*ft_find_sentence(char *s, char **line, char c);
char	*ft_strjoin(char *s1, char *s2);
int		check_sentence(char *rest, char c);
int		check_errors(int fd);

#endif