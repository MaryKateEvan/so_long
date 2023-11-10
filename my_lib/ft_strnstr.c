/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 23:32:30 by mevangel          #+#    #+#             */
/*   Updated: 2023/04/12 17:54:07 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack && len)
	{
		i = 0;
		if (*haystack == *needle)
		{
			while (needle[i] && (haystack[i] == needle[i]) && (len - i > 0))
				i++;
			if (needle[i] == '\0')
				return ((char *)haystack);
		}
		haystack++;
		len--;
	}
	return (NULL);
}
