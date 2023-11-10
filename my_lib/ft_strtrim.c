/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 21:10:07 by mevangel          #+#    #+#             */
/*   Updated: 2023/04/12 18:40:12 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;

	if (s1 == NULL || set == NULL)
		return (NULL);
	if (*s1 == '\0')
		return (ft_strdup(""));
	len = ft_strlen(s1) - 1;
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (i < len && ft_strchr(set, s1[len]))
		len--;
	return (ft_substr(s1, i, len - i + 1));
}
