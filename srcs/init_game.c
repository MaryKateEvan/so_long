/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 02:20:39 by mevangel          #+#    #+#             */
/*   Updated: 2023/11/27 00:14:29 by mevangel         ###   ########.fr       */
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
			mlx_image_to_window(game->mlx, game->img_snow, x * SIZE, y * SIZE);
			if (map[y][x] == '1')
				mlx_image_to_window(game->mlx, game->img_tree, x * SIZE, y * SIZE);
			else if (map[y][x] == 'P')
				mlx_image_to_window(game->mlx, game->img_santa, x * SIZE, y * SIZE);
			else if (map[y][x] == 'C')
				mlx_image_to_window(game->mlx, game->img_gifts, x * SIZE, y * SIZE);
			else if (map[y][x] == 'E')
				mlx_image_to_window(game->mlx, game->img_slay, x * SIZE, y * SIZE);
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
	game->slay = mlx_load_png("images/slay.png");
	game->gifts = mlx_load_png("images/gifts.png");
	game->tree = mlx_load_png("images/tree.png");
	game->snow = mlx_load_png("images/snow.png");
	//then i turn the textures to images:
	game->img_tree = mlx_texture_to_image(game->mlx, game->tree);
	game->img_snow = mlx_texture_to_image(game->mlx, game->snow);
	game->img_santa = mlx_texture_to_image(game->mlx, game->santa);
	game->img_gifts = mlx_texture_to_image(game->mlx, game->gifts);
	game->img_slay = mlx_texture_to_image(game->mlx, game->slay);
	
	map = ft_split(game->map, '\n');
	if (!map)
		ft_error_exit("malloc for split failed.", 1);

	ft_fill_window(game, map);
	ft_free_2darr(map);
}

