/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:07:43 by mevangel          #+#    #+#             */
/*   Updated: 2023/12/25 23:30:50 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"

static int	get_str_len(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len++;
		n = n * (-1);
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		len;
	int		i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = get_str_len(n);
	ptr = (char *)ft_calloc(len + 1, sizeof(char));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	if (n < 0)
	{
		ptr[0] = '-';
		n = n * (-1);
		i++;
	}
	while (len > i)
	{
		ptr[len - 1] = (n % 10) + '0';
		len--;
		n = n / 10;
	}
	return (ptr);
}
