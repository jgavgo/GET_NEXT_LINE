/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgavilan <jgavilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 22:18:33 by jgavilan          #+#    #+#             */
/*   Updated: 2023/08/08 18:30:20 by jgavilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchar(const char *data, char c)
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

char *ft_substr()
size_t ft_strlen()