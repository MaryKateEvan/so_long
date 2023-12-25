/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 01:32:42 by mevangel          #+#    #+#             */
/*   Updated: 2023/12/25 23:32:09 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"

char	*ft_strdup(const char *s1)
{
	char	*cp;
	size_t	len;

	len = ft_strlen(s1) + 1;
	cp = (char *)malloc(len);
	if (cp == NULL)
		return (NULL);
	ft_strlcpy(cp, s1, len);
	return (cp);
}
