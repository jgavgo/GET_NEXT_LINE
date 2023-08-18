/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgavilan <jgavilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 22:18:33 by jgavilan          #+#    #+#             */
/*   Updated: 2023/08/18 14:55:21 by jgavilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchar(char *data, char c)
{
	int	i;

	i = 0;
	while (data[i] != '\0')
	{
		if (data[i] == c)
			return ((char *)&data[i]);
		i++;
	}
	return (NULL);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *data, char *buff)
{
	char	*str;
	int		lens1;
	int		lens2;
	int		i;

	lens1 = ft_strlen((char *)data);
	lens2 = ft_strlen((char *)buff);
	str = malloc((lens1 + lens2 + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = -1;
	while (data[++i] && data[i] != '\0')
		str[i] = data[i];
	i = -1;
	while (buff[++i] && buff[i] != '\0')
	{
		str[lens1] = buff[i];
		lens1++;
	}
	str[lens1] = '\0';
	ft_free(&data);
	return (str);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (ft_strlen(s) <= start)
		len = 0;
	else if (ft_strlen(s + start) < len)
		len = (ft_strlen(s + start));
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = start;
	while (s[i] && j < len)
	{
		str[j] = s[i];
		j++;
		i++;
	}
	str[j] = '\0';
	return (str);
}

/* size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{


	i = 0;
	j = ft_strlen(src);
	if (dstsize != 0)
	{
		while ((src[i] != '\0') && (i < dstsize -1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (j);
} */
/*
int bytes = 1;
char *buffer;
char *line;

buffer = ft_calloc(sizeof(char) * BUFFER_SIZE +1);
(!buffer)
	return (-1);

while(bytes > 0 || ft_strchar(buffer, '\n'))
{
	free(buffer);
	bytes = read(fd, buffer, BUFFER_SIZE);
	line = ft_strjoin(line, buffer);
}

*/