/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 22:38:25 by mevangel          #+#    #+#             */
/*   Updated: 2023/12/09 01:20:57 by mevangel         ###   ########.fr       */
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

static void	ft_fill_window(t_game *game)
{
	int32_t	x;
	int32_t	y;

	y = -1;
	while (++y < game->height)
	{
		x = -1;
		while (++x < game->width)
		{
			mlx_image_to_window(game->mlx, game->snow, x * SIZE, y * SIZE);
			if (game->twod[y][x] == '1')
				mlx_image_to_window(game->mlx, game->tree, x * SIZE, y * SIZE);
			else if (game->twod[y][x] == 'P')
			{
				mlx_image_to_window(game->mlx, game->santa, x * SIZE, y * SIZE);
				game->p_x = x;
				game->p_y = y;
			}
			else if (game->twod[y][x] == 'C')
			{
				mlx_image_to_window(game->mlx, game->gifts, x * SIZE, y * SIZE);
				mlx_image_to_window(game->mlx, game->sparks, x * SIZE, y * SIZE);
				game->sparks->enabled = false;
			}
			else if (game->twod[y][x] == 'E')
				mlx_image_to_window(game->mlx, game->slay, x * SIZE, y * SIZE);
			else if (game->twod[y][x] == 'G')
			{
				mlx_image_to_window(game->mlx, game->grinch, x * SIZE, y * SIZE);
				mlx_image_to_window(game->mlx, game->grinch2, x * SIZE, y * SIZE);
				game->grinch2->enabled = false;
			}
		}
	}
}

static void	ft_check_given_map(int map_fd, t_game *game)
{
	char	*line;
	int		i;

	line = get_next_line(map_fd);
	i = 0;
	if (ft_strlen(line) > 9000)
	{
		free(line);
		close(map_fd);
		ft_error_exit("map is too big.", 0);
	}
	ft_strlcpy(game->map, line, ft_strlen(line) + 1);
	game->width = ft_linelen(line);
	game->height = 0;
	while (line != NULL && ++i)
	{
		game->height++;
		free(line);
		line = get_next_line(map_fd);
		if (line == NULL)
			break ;
		if (ft_linelen(line) != game->width)
		{
			free(line);
			close(map_fd);
			ft_error_exit("map is not rectangular.", 0);
		}
		ft_strlcat(game->map, line, 10000);
		if (ft_strlen(game->map) > 9000)
		{
			free(line);
			close(map_fd);
			ft_error_exit("map is too big.", 0);
		}
	}
	free(line);
	ft_check_characters(game);
}

void	ft_loop_grinch(void *param)
{
	t_game	*game;
	int32_t	x;
	int32_t	y;
	uint8_t	toggle;
	uint8_t	toggle2;

	game = param;
	toggle = (game->tick / 30) % 2;
	toggle2 = (game->tick / 25) % 2;
	y = -1;
	while (++y < game->height)
	{
		x = -1;
		while (++x < game->width)
		{
			if (game->twod[y][x] == 'G')
			{
				game->grinch2->enabled = toggle;
				game->grinch->enabled = !toggle;
			}
			if (game->twod[y][x] == 'C')
				game->sparks->enabled = toggle2;
		}
	}
	game->tick++;
}

void	ft_loop_gifts(void *param)
{
	t_game	*game;
	int32_t	x;
	int32_t	y;
	uint8_t	toggle;

	game = param;
	toggle = (game->tick / 25) % 2;
	y = -1;
	while (++y < game->height)
	{
		x = -1;
		while (++x < game->width)
		{
			if (game->twod[y][x] == 'C')
			{
				// mlx_image_to_window(game->mlx, game->snow, x * SIZE, y * SIZE);
				// mlx_image_to_window(game->mlx, game->gifts, x * SIZE, y * SIZE);
				// mlx_image_to_window(game->mlx, game->sparks, x * SIZE, y * SIZE);
				// mlx_image_to_window(game->mlx, game->gifts, x * SIZE, y * SIZE);
				game->sparks->enabled = toggle;
				// game->gifts->enabled = !toggle;
			}
		}
	}
	game->tick++;
}


// void	ft_loop_grinch2(void *param)
// {
// 	t_game	*game;
// 	int32_t	x;
// 	int32_t	y;

// 	game = param;

// 	y = -1;
// 	while (++y < game->height)
// 	{
// 		x = -1;
// 		while (++x < game->width)
// 		{
// 			if (game->twod[y][x] == 'G')
// 			{
// 				mlx_image_to_window(game->mlx, game->snow, x * SIZE, y * SIZE);
// 				mlx_image_to_window(game->mlx, game->grinch, x * SIZE, y * SIZE);
// 			}
// 		}
// 	}
// }

void	check_leaks(void)
{
	system("leaks so_long");
}

int	main(int argc, char **argv)
{
	int		map_fd;
	t_game	game;
	
	atexit(check_leaks);
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
	game.step = ft_linelen(game.map) + 1;
	game.mlx = mlx_init(game.width * SIZE, game.height * SIZE, 
		"Help Santa collect all the gifts!!", false);
	if (!game.mlx)
		ft_error_exit("mlx_init failed", 1);
	ft_initialize_game(&game);
	ft_fill_window(&game);
	mlx_key_hook(game.mlx, &ft_my_keyhook, &game);
	mlx_loop_hook(game.mlx, &ft_loop_grinch, &game);
	// mlx_loop_hook(game.mlx, &ft_loop_gifts, &game);
	// mlx_loop_hook(game.mlx, &ft_loop_grinch2, &game);
	
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	return (EXIT_SUCCESS);
}
