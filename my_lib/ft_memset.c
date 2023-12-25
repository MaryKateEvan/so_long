/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:31:25 by mevangel          #+#    #+#             */
/*   Updated: 2023/12/25 23:31:35 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"

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
