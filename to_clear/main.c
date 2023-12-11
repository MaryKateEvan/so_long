/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 22:38:25 by mevangel          #+#    #+#             */
/*   Updated: 2023/12/11 21:38:09 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_read_map(int map_fd, t_game *game);

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
		ft_error_exit("no such file to open or open function failed", 1);
	ft_read_map(map_fd, &game);
	ft_parse_map(&game);
	game.mlx = mlx_init(game.width * 84, game.height * 84, \
		"Help Santa collect all the gifts!!", false);
	if (!game.mlx)
		ft_error_exit("mlx_init failed", 1);
	ft_window_images(&game);
	mlx_key_hook(game.mlx, &ft_keyhook, &game);
	mlx_loop_hook(game.mlx, &ft_animation, &game);
	mlx_loop(game.mlx);
	ft_exit_game(&game, 0);
}

static void	ft_read_map(int map_fd, t_game *game)
{
	char	*line;

	line = get_next_line(map_fd);
	if (!line || !line[0])
		ft_err_exit_fr1_clsfd("empty .ber map file", 0, line, map_fd);
	if (ft_strlen(line) > 400)
		ft_err_exit_fr1_clsfd("invalid map.", 0, line, map_fd);
	ft_strlcpy(game->map, line, ft_strlen(line) + 1);
	game->width = ft_linelen(line);
	game->height = 0;
	while (line != NULL)
	{
		if (++game->height > 12 || game->width > 25)
			ft_err_exit_fr1_clsfd("map can be up to 25x12.", 0, line, map_fd);
		free(line);
		line = get_next_line(map_fd);
		if (line == NULL)
			break ;
		if (ft_linelen(line) != game->width)
			ft_err_exit_fr1_clsfd("map is not rectangular.", 0, line, map_fd);
		ft_strlcat(game->map, line, 500);
	}
	close(map_fd);
}

void	ft_exit_game(t_game *game, int exit_code)
{
	ft_free_2darr(game->twod);
	mlx_close_window(game->mlx);
	mlx_terminate(game->mlx);
	if (exit_code == 1)
		exit(EXIT_FAILURE);
	else
		exit(EXIT_SUCCESS);
}
