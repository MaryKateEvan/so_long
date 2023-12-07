/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 21:42:51 by mevangel          #+#    #+#             */
/*   Updated: 2023/12/07 15:45:32 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_c(int c)
{
	return (write(1, &c, 1));
}

int	ft_print_s(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[i])
		i++;
	return (write(1, str, i));
}

int	ft_print_number(long int n)
{
	int	count;
	int	writefail;

	count = 0;
	writefail = 0;
	if (n < 0)
	{
		if (write(1, "-", 1) < 0)
			return (-1);
		n = n * (-1);
		count++;
	}
	if (n > 9)
	{
		writefail = ft_print_number(n / 10);
		if (writefail < 0)
			return (-1);
		else
			count += writefail;
	}
	if (write(1, &"0123456789"[n % 10], 1) < 0)
		return (-1);
	count++;
	return (count);
}

int	ft_print_hexa(size_t dec, char type)
{
	char	*hexadigits;
	char	num[16];
	int		i;

	i = 16;
	hexadigits = "0123456789abcdef";
	if (dec == 0)
		return (write(1, "0", 1));
	if (type == 'X')
		hexadigits = "0123456789ABCDEF";
	while (dec > 0)
	{
		num[--i] = hexadigits[dec % 16];
		dec = dec / 16;
	}
	return (write(1, num + i, 16 - i));
}

int	ft_print_p(void *ptr)
{
	if (ptr == NULL)
		return (write(1, "0x0", 3));
	if (write(1, "0x", 2) < 0)
		return (-1);
	return (ft_print_hexa((size_t)ptr, 'x') + 2);
}
