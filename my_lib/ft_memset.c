/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:31:25 by mevangel          #+#    #+#             */
/*   Updated: 2023/04/12 17:22:55 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*cp;
	size_t			i;

	cp = b;
	i = 0;
	while (i < len)
	{
		cp[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
