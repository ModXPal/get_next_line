/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 18:23:22 by rcollas           #+#    #+#             */
/*   Updated: 2021/05/27 14:08:54 by rcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	LIBFT_H
# define GET_NEXT_LINE

#include <stdlib.h>
#include <unistd.h>

int	get_next_line(int fd, char **line);
char	*ft_strjoin(char *str1, char *str2);
int	ft_end_of_line(char *str);
char	*ft_substr(char *str, unsigned int len);
unsigned int	ft_strlen(char *str);
void	ft_after_newline(char *str, unsigned int start);
void	ft_bzero(void *s);

# define BUFFER_SIZE 10000000 

#endif
