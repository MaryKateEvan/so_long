/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:58:51 by mevangel          #+#    #+#             */
/*   Updated: 2023/04/12 19:08:19 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	char	*cp_s1;
	size_t	join_len;

	cp_s1 = (char *)s1;
	join_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	new = (char *)malloc(join_len);
	if (new == NULL)
		return (NULL);
	ft_strlcpy(new, cp_s1, ft_strlen(cp_s1) + 1);
	ft_strlcat(new, s2, join_len);
	return (new);
}
