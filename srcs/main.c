/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 22:38:25 by mevangel          #+#    #+#             */
/*   Updated: 2023/11/23 04:20:40 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../my_lib/libft.h"

void	ft_error_exit(char *perr_msg, int exit_value)
{
	ft_putstr_fd("\033[31mError:\033[37m ", 2);
	ft_putendl_fd(perr_msg, 2);
	if (exit_value == 1)
		exit (EXIT_FAILURE);
	else
		exit (EXIT_SUCCESS);
}



int	main(int argc, char **argv)
{
	int		map_fd;
	t_game	game;
	
	if (argc != 2)
		ft_error_exit("expected two command line arguments!", 0);
	if (ft_strncmp((argv[1] + (ft_strlen(argv[1]) - 4)), ".ber", 5) != 0)
		ft_error_exit("not a .ber map file", 0);
	map_fd = open(argv[1], O_RDONLY);
	if (map_fd < 0)
		ft_error_exit("no such file to open", 1);
	ft_check_given_map(map_fd, &game);
	close(map_fd);
	// i reach here if the map is valid:
	game.mlx = mlx_init(game.width * SIZE, game.height * SIZE, "Ho ho ho!", false); //don't forget to check what the "true" here influences
	if (!game.mlx)
		ft_error_exit("mlx_init failed", 1);
	//mlx_set_window_limit(game.mlx, game.width * SIZE, game.height * SIZE, game.width * SIZE + 1, game.height * SIZE + 1);
	//  |->this doesn't allow me to change the size of the window if i do it like this. 
	ft_initialize_game(&game);
	// mlx_loop_hook    or    mlx_key_hook();
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	// printf("What I gathered until now is:\n");
	// printf("map height is: %d\n", game.height);
	// printf("map width is: %d\n", game.width);
	// printf("number of coins to gather: %d\n", game.coins);
	// printf("the index of the player is: %d\n", game.player_idx);
	// printf("the index of the exit is: %d\n", game.exit_idx);
	// printf("the map i got is: %s\n", game.map);

	return (EXIT_SUCCESS);
}
