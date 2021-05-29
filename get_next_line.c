/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 18:19:42 by rcollas           #+#    #+#             */
/*   Updated: 2021/05/29 16:51:38 by rcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

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
		//printf("is_reading -----> %d\n", is_reading);
		buff[is_reading] = 0;
		if (is_reading == 0)
			break ;
		if (is_reading == -1)
			return (-1);
		//printf("buff is -----> %s\n", buff);
		*line = ft_strjoin(*line, buff);
		//printf("line is -----> %s\n", *line);
	}
	//printf("line after substr -----> %s\n", *line);
	if (ft_end_of_line(*line))
		*line = ft_substr(*line, 0);
	ft_after_newline(buff, ft_end_of_line(buff));
	if (is_reading == 0)
	{
		ft_bzero(buff);
		return (0);
	}
	return (1);
}
