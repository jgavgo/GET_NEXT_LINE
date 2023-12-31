/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgavilan <jgavilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 21:12:38 by jgavilan          #+#    #+#             */
/*   Updated: 2023/08/22 17:20:16 by jgavilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoin(char *data, char *buff);
size_t	ft_strlen(char *str);
char	*ft_strchar(char *data, char c);
char	*ft_free(char **buffer);
char	*ft_newline(char **data);
char	*ft_fill_data(char *data, int fd, int bytes);
char	*cleandata(char *data, size_t lenline);
size_t	ft_strchr(char *data, char c);

#endif
