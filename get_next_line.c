0/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpogorz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 08:17:19 by anpogorz          #+#    #+#             */
/*   Updated: 2019/11/05 12:41:49 by anpogorz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_errors(int fd)
{
	if (fd < 0)
		return (-1);
	return (0)
}

int get_next_line(int fd, char **line)
{
	static int ret;
	static char *rest;
	char *buffer;
	char *readstr;

	if (check_errors(fd) == -1)
		return (-1);
	buffer = ft_calloc(1, BUFFER_SIZE + 1);
	while ((ret = read(fd, buffer, BUFFER_SIZE)) != 0)
	{
		buffer[ret] = '\0';
		if (!(readstr = ft_strjoin(rest, buffer)))
			return (-1);
		rest = ft_find_sentence(readstring, &line, '\n');
		if (strcmp(rest, readstr) != 0)
			return (1);
	}
	return (0);
}