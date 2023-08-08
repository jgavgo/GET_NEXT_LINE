/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgavilan <jgavilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 21:09:30 by jgavilan          #+#    #+#             */
/*   Updated: 2023/08/08 20:17:22 by jgavilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char **buffer)
{
	free(*buffer);
	*buffer = NULL;
	return (NULL);
}

char	*ft_readline(char *data, int fd, int flag)
{
	char	*buff;

	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	flag = read(fd, buff, BUFFER_SIZE);
	if (flag < 0)
		return (NULL);
	if (flag == 0)
		return ()
}

char	*get_next_line(int fd)
{
	static char	*data;
	char		*line;

	if (fd < 0)
		return (NULL);
	if (!data)
	{
		data = (char *)malloc(1);
		if (!data)
			return (NULL);
		data[0] = '\0';
	}
	data = ft_readline(data, fd, 1);
}