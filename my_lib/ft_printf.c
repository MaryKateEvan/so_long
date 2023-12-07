/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:17:43 by mevangel          #+#    #+#             */
/*   Updated: 2023/12/07 15:45:44 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	format_specifiers(char type, va_list args)
{
	if (type == 'c')
		return (ft_print_c(va_arg(args, int)));
	else if (type == 's')
		return (ft_print_s(va_arg(args, char *)));
	else if (type == 'd' || type == 'i')
		return (ft_print_number(va_arg(args, int)));
	else if (type == 'u')
		return (ft_print_number(va_arg(args, unsigned int)));
	else if (type == 'x' || type == 'X')
		return (ft_print_hexa((size_t)va_arg(args, unsigned int), type));
	else if (type == 'p')
		return (ft_print_p(va_arg(args, void *)));
	else
		return (ft_print_c('%'));
}

static int	mainfunction(const char *str, va_list args, int count)
{
	int	i;
	int	writefail;

	i = 0;
	writefail = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			writefail = format_specifiers(str[i + 1], args);
			if (writefail < 0)
				return (-1);
			else
				count += writefail;
			i += 2;
		}
		else
		{
			if (write(1, &str[i], 1) < 0)
				return (-1);
			count++;
			i++;
		}
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		printed_chars;

	printed_chars = 0;
	va_start(args, str);
	printed_chars = mainfunction(str, args, 0);
	va_end(args);
	return (printed_chars);
}
