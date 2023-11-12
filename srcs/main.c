/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 09:24:33 by mevangel          #+#    #+#             */
/*   Updated: 2023/11/12 17:06:00 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../my_lib/libft.h"

void	ft_error_exit(int err_code)
{
	ft_putstr_fd("Error\n", 2);
	if (err_code == 1)
		exit (EXIT_FAILURE);
	else
		exit (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		ft_error_exit(0);
	(void)argv;
}
