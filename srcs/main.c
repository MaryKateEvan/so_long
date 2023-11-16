/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 09:24:33 by mevangel          #+#    #+#             */
/*   Updated: 2023/11/16 11:23:56 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../my_lib/libft.h"

#include <stdio.h>                          //DON'T FORGET IT AFTER

void	ft_error_exit(char *perr_msg, int err_code)
{
	ft_putstr_fd(RED"Error\n", 2);
	ft_putendl_fd(perr_msg)
	if (err_code == 1)
		exit (EXIT_FAILURE);
	else
		exit (EXIT_SUCCESS);
}

// ./so_long maps/map1.ber

void	open_map(char *arg2)
{
	char	*tmp;
	int		map_fd;
	char	*line;

	map_fd = open(arg2, O_RDONLY);
	if (map_fd < 0)
		ft_error_exit()
	tmp = arg2 + (ft_strlen(arg2) - 4);
	if (ft_strncmp(tmp, ".ber", 5) != 0)
		ft_error_exit(0);
	line = get_next_line(map_fd);
	while (line)
	{
		line = get_next_line(map_fd);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		ft_error_exit(0);
	open_map(argv[1]);
	// if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1]) + 1) == NULL)
	// 	ft_error_exit(0);
	// printf("%lu\n", ft_strlen(argv[1]));
	return (EXIT_SUCCESS);
}
