/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgavilan <jgavilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 22:18:33 by jgavilan          #+#    #+#             */
/*   Updated: 2023/08/16 19:07:14 by jgavilan         ###   ########.fr       */
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

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		lens1;
	int		lens2;
	int		i;

	if (s1 && s2)
	{
		lens1 = ft_strlen((char *)s1);
		lens2 = ft_strlen((char *)s2);
		str = malloc((lens1 + lens2 + 1) * sizeof(char));
		if (!str)
			return (NULL);
		i = -1;
		while (s1[++i] && s1[i] != '\0')
			str[i] = s1[i];
		i = -1;
		while (s2[++i] && s2[i] != '\0')
		{
			str[lens1] = s2[i];
			lens1++;
		}
		str[lens1] = '\0';
		return (str);
	}
	return (NULL);
}

char	*ft_substr(char *s, int start, size_t len)
{
	char	*ret;

	if (!s)
		return (NULL);
	if (ft_strlen(s) <= start)
		return (NULL);
	if ((ft_strlen(s) - start) < (int)len)
		len = ft_strlen(s) - start;
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, s + start, len + 1);
	return (ret);
}

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

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
}
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