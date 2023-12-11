/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_exit_fr1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:54:08 by mevangel          #+#    #+#             */
/*   Updated: 2023/12/10 19:15:09 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_err_exit_fr1_clsfd(char *msg, int exit_val, void *to_free, int fd)
{
	ft_putstr_fd("\033[31mError:\033[37m ", 2);
	ft_putendl_fd(msg, 2);
	free(to_free);
	close(fd);
	if (exit_val == 1)
		exit(EXIT_FAILURE);
	else
		exit(EXIT_SUCCESS);
}
