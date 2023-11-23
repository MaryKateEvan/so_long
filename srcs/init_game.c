/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 02:20:39 by mevangel          #+#    #+#             */
/*   Updated: 2023/11/23 04:32:07 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../my_lib/libft.h"

void	ft_fill_window(t_game *game, char **map)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			mlx_image_to_window(game->mlx, game->img_floor, x * SIZE, y * SIZE);
			if (map[y][x] == '1')
				mlx_image_to_window(game->mlx, game->img_tree, x * SIZE, y * SIZE);
			else if (map[y][x] == 'P')
				mlx_image_to_window(game->mlx, game->img_santa, x * SIZE, y * SIZE);
			else if (map[y][x] == 'C')
				mlx_image_to_window(game->mlx, game->img_cookie, x * SIZE, y * SIZE);
			else if (map[y][x] == 'E')
				mlx_image_to_window(game->mlx, game->img_chimney, x * SIZE, y * SIZE);
			x++;
		}
		y++;
	}
}

void	ft_initialize_game(t_game *game)
{
	char	**map;

	//first I create the textures:
	game->santa = mlx_load_png("images/santa.png");
	game->chimney = mlx_load_png("images/chimney.png");
	game->cookie = mlx_load_png("images/cookie.png");
	game->tree = mlx_load_png("images/tree.png");
	game->floor = mlx_load_png("images/floor.png");
	//then i turn the textures to images:
	game->img_tree = mlx_texture_to_image(game->mlx, game->tree);
	game->img_floor = mlx_texture_to_image(game->mlx, game->floor);
	game->img_santa = mlx_texture_to_image(game->mlx, game->santa);
	game->img_cookie = mlx_texture_to_image(game->mlx, game->cookie);
	game->img_chimney = mlx_texture_to_image(game->mlx, game->chimney);
	
	map = ft_split(game->map, '\n');
	if (!map)
		ft_error_exit("malloc for split failed.", 1);

	ft_fill_window(game, map);
	ft_free_2darr(map);
}

