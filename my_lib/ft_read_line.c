/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:47:03 by mevangel          #+#    #+#             */
/*   Updated: 2023/12/25 23:31:58 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"

int	ft_read_line(char **line, int fd)
{
	char	*buffer;
	char	ret;
	int		i;
	char	c;

	i = 0;
	buffer = (char *)malloc(4200);
	if (!buffer)
	{
		ft_putstr_fd("malloc failed", 2);
		return (0);
	}
	ret = read(fd, &c, 1);
	while (ret > 0 && c != '\n' && c != '\0')
	{
		buffer[i++] = c;
		ret = read(fd, &c, 1);
	}
	buffer[i] = '\n';
	buffer[i + 1] = '\0';
	*line = ft_strdup(buffer);
	free(buffer);
	return (i);
}
