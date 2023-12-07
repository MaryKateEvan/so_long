/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 22:38:25 by mevangel          #+#    #+#             */
/*   Updated: 2023/12/07 18:33:26 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../my_lib/libft.h"

void	ft_error_exit(char *perr_msg, int exit_value)
{
	ft_putstr_fd("\033[31mError:\033[37m ", 2);
	ft_putendl_fd(perr_msg, 2);
	if (exit_value == 1)
		exit(EXIT_FAILURE);
	else
		exit(EXIT_SUCCESS);
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
	if (game.width > 24 || game.height > 12)
		ft_error_exit("map is too big!", 0);
	// i reach here if the map is valid:
	game.mlx = mlx_init(game.width * SIZE, game.height * SIZE, 
		"Help Santa collect all the gifts!!", false); //don't forget to check what the "true" here influences
	if (!game.mlx)
		ft_error_exit("mlx_init failed", 1);
	ft_initialize_game(&game);
	mlx_key_hook(game.mlx, &ft_my_keyhook, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	return (EXIT_SUCCESS);
}
