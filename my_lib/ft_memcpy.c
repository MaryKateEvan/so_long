/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:31:25 by mevangel          #+#    #+#             */
/*   Updated: 2023/12/25 23:31:29 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*cp_dst;
	char	*cp_src;

	cp_dst = (char *)dst;
	cp_src = (char *)src;
	if (!dst && !src)
		return (dst);
	while (n--)
		*(cp_dst++) = *(cp_src++);
	return (dst);
}
