/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:52:15 by mevangel          #+#    #+#             */
/*   Updated: 2023/12/25 23:32:26 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (!dst || dstsize == 0)
		return (ft_strlen(src));
	i = 0;
	while (i < (dstsize - 1) && (src[i] != '\0'))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
