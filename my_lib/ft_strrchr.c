/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:46:47 by mevangel          #+#    #+#             */
/*   Updated: 2023/12/25 23:32:39 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;

	ptr = (char *)s + ft_strlen(s);
	if ((char)c == '\0')
		return (ptr);
	while (--ptr >= s)
		if (*ptr == (unsigned char)c)
			return (ptr);
	return (NULL);
}
