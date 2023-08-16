/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgavilan <jgavilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 21:09:30 by jgavilan          #+#    #+#             */
/*   Updated: 2023/08/16 19:48:17 by jgavilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char **buffer)
{
	free(*buffer);
	*buffer = NULL;
	return (NULL);
}

char	*ft_newline(char *data)
{
	char	*line;

	if (!data)
		return (NULL);
	else
		line = ft_substr(data, 0, (size_t)ft_strchar(data, '\n'));
	return (line);
}

char	*ft_fill_data(char *data, int fd)
{
	char	*buff;
	int		bytes;

	bytes = 1;
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	bytes = read(fd, buff, BUFFER_SIZE);
	// return (buff);
	while (bytes > 0 || !ft_strchar(data, '\n'))
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		write(1, "hola", 4);
		if (bytes > 0)
		{
			buff[bytes] = '\0';
			data = ft_strjoin(data, buff);
		}
	}
	free (buff);
	return (data);
}

char	*get_next_line(int fd)
{
	static char	*data = NULL;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	data = ft_fill_data(data, fd);
	if (!data)
		return (NULL);
	// return (ft_newline(data));
	return (data);
}

int	main(void)
{
	int		fd;
	char	*str;
	ssize_t	num_bytes;

	fd = open("hola.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	close(fd);
	return (0);
}
