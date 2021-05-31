/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 18:19:42 by rcollas           #+#    #+#             */
/*   Updated: 2021/05/31 12:23:42 by rcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	ft_end_of_line(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		if (str[i++] == '\n')
			return (i);
	return (0);
}

void	ft_after_newline(char *str, unsigned int start)
{
	char			*tmp;
	unsigned int	i;

	tmp = str;
	i = 0;
	while (tmp[start])
		str[i++] = tmp[start++];
	str[i] = 0;
}

int	get_next_line(int fd, char **line)
{
	char static	buff[BUFFER_SIZE + 1];
	int			is_reading;

	if (fd < 0 || fd > 900 || BUFFER_SIZE <= 0)
		return (-1);
	is_reading = 1;
	*line = ft_strdup("");
	ft_bzero(*line);
	*line = ft_strjoin(*line, buff);
	while (is_reading > 0 && !ft_end_of_line(*line))
	{
		is_reading = read(fd, buff, BUFFER_SIZE);
		buff[is_reading] = 0;
		if (is_reading == 0)
			break ;
		if (is_reading == -1)
			return (-1);
		*line = ft_strjoin(*line, buff);
	}
	if (ft_end_of_line(*line))
		*line = ft_substr(*line, 0);
	ft_after_newline(buff, ft_end_of_line(buff));
	if (is_reading == 0)
		return (ft_bzero(buff));
	return (1);
}
