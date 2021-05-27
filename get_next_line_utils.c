/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:10:33 by rcollas           #+#    #+#             */
/*   Updated: 2021/05/27 14:08:55 by rcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_end_of_line(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		if (str[i++] == '\n')
			return (i);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		s1_len;
	int		s2_len;
	int		i;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = (char *)malloc(sizeof(*str) * (s1_len + s2_len) + 1);
	if (!str)
		return (NULL);
	while (*s1)
		str[i++] = *s1++;
	while (*s2)
		str[i++] = *s2++;
	str[i] = 0;
	return (str);
}

char	*ft_substr(char *str, unsigned int len)
{
	char			*truncate_str;
	unsigned int	j;
	unsigned int	i;

	if (!str)
		return (NULL);
	j = len;
	i = 0;
	while (str[len] != '\n')
		len++;
	truncate_str = (char *)malloc(sizeof(char) * (len - j + 1));
	while (j < len)
	{
		truncate_str[i] = str[j];
		i++;
		j++;
	}
	return (truncate_str);
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

void	ft_bzero(void *s)
{
	while (*(unsigned char *)s)
		*(unsigned char *)(s++) = 0;
}
