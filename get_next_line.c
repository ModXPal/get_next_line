/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 18:19:42 by rcollas           #+#    #+#             */
/*   Updated: 2021/05/27 14:09:12 by rcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	get_next_line(int fd, char **line)
{
	char static	buff[BUFFER_SIZE];
	int			is_reading;
	int			line_len;

	is_reading = 1;
	line_len = ft_strlen(*line);
	ft_bzero(*line);
	*line = ft_strjoin(*line, buff);
	while (is_reading && !ft_end_of_line(*line))
	{
		is_reading = read(fd, buff, BUFFER_SIZE);
		//printf("buff is -----> %s\n", buff);
		buff[is_reading] = 0;
		*line = ft_strjoin(*line, buff);
		//printf("line is -----> %s\n", *line);
	}
	*line = ft_substr(*line, 0);
	//printf("line after substr -----> %s\n", *line);
	ft_after_newline(buff, ft_end_of_line(buff));
	//printf("buff after new line is -----> %s\n", buff);
	return (0);
}
