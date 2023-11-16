/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 09:24:33 by mevangel          #+#    #+#             */
/*   Updated: 2023/11/16 23:36:59 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../my_lib/libft.h"

void	ft_error_exit(char *perr_msg, int err_code)
{
	ft_putstr_fd("Error: ", 2);
	ft_putendl_fd(perr_msg, 2);
	if (err_code == 1)
		exit (EXIT_FAILURE);
	else
		exit (EXIT_SUCCESS);
}

// ./so_long maps/map1.ber

void	init_struct_values(t_game *game)
{
	game->height = 0;
	game->width = 0;
}

void	open_map(char *arg2, t_game *game)
{
	int		map_fd;
	char	*line;

	if (ft_strncmp((arg2 + (ft_strlen(arg2) - 4)), ".ber", 5) != 0)
		ft_error_exit("not a .ber map file", 0);
	map_fd = open(arg2, O_RDONLY);
	if (map_fd < 0)
		ft_error_exit("failed to open the file", 1);
	init_struct_values(game);
	line = get_next_line(map_fd);
	game->width = ft_strlen(line) - 1;
	// printf("strlen returns: %lu\n", ft_strlen(line));
	while (line)
	{
		game->height++;
		free(line);
		line = get_next_line(map_fd);
		if (ft_strlen(line) - 1 != game->width)
		{
			free(line);
			ft_error_exit("Map is not rectangular.", 0);
		}
		//malloc for each line to the 2d array
	}
	printf("height i got is: %d\n", game->height);
	printf("width i got is: %d\n", game->width);
	
	// printf("1st line i got is: %s\n", line);
	// printf("the len of first line is: %lu\n", ft_strlen(line));
}



int	main(int argc, char **argv)
{
	t_game	game;
	
	if (argc != 2)
		ft_error_exit("Expected two command line arguments!", 0);
	open_map(argv[1], &game);
	
	game.width = 10;
	game.height = 20;
	// if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1]) + 1) == NULL)
	// 	ft_error_exit(0);
	// printf("%lu\n", ft_strlen(argv[1]));
	return (EXIT_SUCCESS);
}
