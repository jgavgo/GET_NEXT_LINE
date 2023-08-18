/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgavilan <jgavilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 21:09:30 by jgavilan          #+#    #+#             */
/*   Updated: 2023/08/18 14:42:25 by jgavilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char **buffer)
{
	free(*buffer);
	*buffer = NULL;
	return (NULL);
}

char	*cleandata(char *data)
{
	char	*newdata;
	char	*str;
	int		charsize;

	str = ft_strchar(data, '\n');
	if (!str)
	{
		newdata = NULL;
		return (ft_free(&data));
	}
	else
		charsize = (str - data) + 1;
	if (!data[charsize])
		return (ft_free(&data));
	newdata = ft_substr(data, charsize, ft_strlen(data) - charsize);
	ft_free(&data);
	if (!newdata)
		return (NULL);
	return (newdata);
}

char	*ft_newline(char *data)
{
	char	*line;

	if (ft_strchar(data, '\n'))
		line = ft_substr(data, 0, (size_t)ft_strchar(data, '\n'));
	else
	{
		line = data;
		data = NULL;
	}
	return (line);
}

char	*ft_fill_data(char *data, int fd, int bytes)
{
	char	*buff;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (ft_free(&data));
	while (bytes > 0 && !ft_strchar(data, '\n'))
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1)
		{
			free (buff);
			return (ft_free(&data));
		}
		buff[bytes] = '\0';
		if (bytes > 0)
		{
			data = ft_strjoin(data, buff);
			if (!data)
				return (ft_free(&data));
		}
	}
	free (buff);
	if (ft_strlen(data) == 0 && bytes == 0)
		return (NULL);
	return (data);
}

char	*get_next_line(int fd)
{
	static char	*data;
	char		*line;

	if (!fd)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!data)
	{
		data = (char *)malloc(sizeof(char) * 1);
		if (!data)
			return (NULL);
		data[0] = '\0';
	}
	data = ft_fill_data(data, fd, 1);
	if (!data)
		return (ft_free(&data));
	line = ft_newline(data);
	if (!line)
		return (ft_free(&data));
	data = cleandata(data);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*str;

	fd = open("hola.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	close(fd);
	return (0);
}
