/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 13:57:25 by mevangel          #+#    #+#             */
/*   Updated: 2023/12/25 23:32:48 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (start >= ft_strlen(s))
		return ((char *)ft_calloc(1, 1));
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	sub = (char *)malloc(len + 1);
	if (sub == NULL)
		return (NULL);
	ft_strlcpy(sub, (s + start), len + 1);
	return (sub);
}
