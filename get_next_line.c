/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgavilan <jgavilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 21:09:30 by jgavilan          #+#    #+#             */
/*   Updated: 2023/08/10 20:54:19 by jgavilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_free(char **buffer)
{
	free(*buffer);
	*buffer = NULL;
	return (NULL);
}

char	*ft_readline(char *data, int fd, int flag)
{
	char	*buff;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	while (flag > 0 && strchr)
		flag = read(fd, buff, BUFFER_SIZE);
	if (flag < 0)
		return (NULL);
	if (flag == 0)
		return (data);
	
}

char	*get_next_line(int fd)
{
	static char	*data;
	char		*line;
	int			flag;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	flag = read(fd, data, BUFFER_SIZE)
	if ((data && !ft_strchar(data, '\n')) || !data)
		data = ft_readline(data, fd, 1);

	// hola que tal estas '\n' jaja	
	line = substr(data, 0, posicion de '\n');
	//funcion que devuelva hasta el '\n'

	data = substr(data, pos '\n', longitud total);
	//funcion que elimine de la estatica la linea que acabas de enviar
	//, es decir, substr desde '\n' hasta el final
	return (line);
}

#include <fcntl.h>
#include <stdio.h>
int	main(void)
{
	char	*arr;
	char	res[BUFFER_SIZE];
	int	fd = open("hola.txt", O_RDONLY);

	arr = (char *)malloc(BUFFER_SIZE * sizeof(char));
	arr = get_next_line(fd);
	printf("%s", arr);
	arr = get_next_line(fd);
	printf("%s", arr);
	close(fd);
	return (0);
}