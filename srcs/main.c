/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 09:24:33 by mevangel          #+#    #+#             */
/*   Updated: 2023/11/18 17:03:42 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../my_lib/libft.h"

void	ft_free_struct(t_game *game)
{
	ft_free_2darr(game->map);
	free(game->onedmap);
}

void	ft_error_exit(char *perr_msg, int err_code, t_game *game)
{
	ft_putstr_fd("Error: ", 2);
	ft_putendl_fd(perr_msg, 2);
	ft_free_struct(game);
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
	game->map = NULL;
	game->onedmap = NULL;
}




void	open_map(char *arg2, t_game *game)
{
	int		map_fd;
	char	*line;
	// int		count;

	if (ft_strncmp((arg2 + (ft_strlen(arg2) - 4)), ".ber", 5) != 0)
		ft_error_exit("not a .ber map file", 0, game);
	map_fd = open(arg2, O_RDONLY);
	if (map_fd < 0)
		ft_error_exit("failed to open the file", 1, game);
	init_struct_values(game);
	line = get_next_line(map_fd);
	game->onedmap = ft_strdup(line);
	game->width = ft_linelen(line);
	// count = 0;
	while (line != NULL)
	{
		game->height++;
		free(line);
		line = get_next_line(map_fd);
		if (!line)
			break ;
		// count += ft_strlen(line);
		if (ft_linelen(line) != game->width)
		{
			free(line);
			ft_error_exit("Map is not rectangular.", 0, game);
		}
	}
	printf("height i got is: %d\n", game->height);
	printf("width i got is: %d\n", game->width);
	
}



int	main(int argc, char **argv)
{
	t_game	game;
	
	init_struct_values(&game);
	if (argc != 2)
		ft_error_exit("Expected two command line arguments!", 0, &game);
	open_map(argv[1], &game);

	// if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1]) + 1) == NULL)
	// 	ft_error_exit(0);
	// printf("%lu\n", ft_strlen(argv[1]));
	return (EXIT_SUCCESS);
}
