/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgavilan <jgavilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 21:09:30 by jgavilan          #+#    #+#             */
/*   Updated: 2023/08/22 18:01:42 by jgavilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char **buffer)
{
	free(*buffer);
	*buffer = NULL;
	return (NULL);
}

char	*cleandata(char *data, size_t lenline)
{
	char	*newdata;

	if (!data[lenline])
		return (ft_free(&data));
	newdata = ft_substr(data, lenline, ft_strlen(data) - lenline);
	ft_free(&data);
	if (!newdata)
		return (NULL);
	return (newdata);
}

char	*ft_newline(char **data)
{
	char	*line;
	size_t	lenline;

	line = NULL;
	if (ft_strchar(*data, '\n'))
	{
		lenline = ft_strlen(*data) - ft_strlen(ft_strchar(*data, '\n') + 1);
		line = ft_substr(*data, 0, lenline);
		if (!line)
			return (ft_free(data));
		*data = cleandata(*data, lenline);
	}
	else
	{
		line = *data;
		*data = NULL;
	}
	return (line);
}

char	*ft_fill_data(char *data, int fd, int bytes)
{
	char	*buff;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (ft_free(&data));
	buff[0] = '\0';
	while (bytes > 0 && !ft_strchar(data, '\n'))
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes > 0)
		{
			buff[bytes] = '\0';
			data = ft_strjoin(data, buff);
			if (!data)
				return (ft_free(&buff));
		}
	}
	free (buff);
	if (bytes == -1)
		return (ft_free(&data));
	if (ft_strlen(data) == 0 && bytes == 0)
		return (ft_free(&data));
	return (data);
}

char	*get_next_line(int fd)
{
	static char	*data;

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
		return (NULL);
	return (ft_newline(&data));
}

// int	main(void)
// {
// 	int		fd;
// 	char	*str;

// 	fd = open("hola.txt", O_RDONLY);
// 	str = get_next_line(fd);
// 	printf("frase 1:\n");
// 	printf("%s", str);
// 	free(str);
// 	str = get_next_line(fd);
// 	printf("\nfrase 2:\n");
// 	printf("%s", str);
// 	free(str);
// 	str = get_next_line(fd);
// 	printf("\nfrase 3:\n");
// 	printf("%s", str);
// 	free(str);
// 	close(fd);
// 	return (0);
// }
