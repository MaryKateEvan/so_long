/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:54:08 by mevangel          #+#    #+#             */
/*   Updated: 2023/12/25 23:30:30 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"

void	ft_error_exit(char *err_msg, int exit_value)
{
	ft_putstr_fd("\033[31mError:\033[37m ", 2);
	ft_putendl_fd(err_msg, 2);
	if (exit_value == 1)
		exit(EXIT_FAILURE);
	else
		exit(EXIT_SUCCESS);
}
