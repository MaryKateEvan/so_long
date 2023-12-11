/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 02:05:10 by mevangel          #+#    #+#             */
/*   Updated: 2023/12/11 21:36:05 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_rest_images(t_game *game);
static void	ft_fill_window(t_game *game);
static void	ft_fill_window_rest(t_game *game);

void	ft_window_images(t_game *game)
{
	mlx_texture_t	*tmp;

	tmp = mlx_load_png("images/santa.png");
	game->santa = mlx_texture_to_image(game->mlx, tmp);
	mlx_delete_texture(tmp);
	tmp = mlx_load_png("images/santa_left.png");
	game->santa_left = mlx_texture_to_image(game->mlx, tmp);
	mlx_delete_texture(tmp);
	tmp = mlx_load_png("images/santa_right.png");
	game->santa_right = mlx_texture_to_image(game->mlx, tmp);
	mlx_delete_texture(tmp);
	tmp = mlx_load_png("images/santa_back.png");
	game->santa_back = mlx_texture_to_image(game->mlx, tmp);
	mlx_delete_texture(tmp);
	tmp = mlx_load_png("images/slay.png");
	game->slay = mlx_texture_to_image(game->mlx, tmp);
	mlx_delete_texture(tmp);
	tmp = mlx_load_png("images/gifts.png");
	game->gifts = mlx_texture_to_image(game->mlx, tmp);
	mlx_delete_texture(tmp);
	tmp = mlx_load_png("images/tree.png");
	game->tree = mlx_texture_to_image(game->mlx, tmp);
	mlx_delete_texture(tmp);
	ft_rest_images(game);
}

static void	ft_rest_images(t_game *game)
{
	mlx_texture_t	*tmp;

	tmp = mlx_load_png("images/snow.png");
	game->snow = mlx_texture_to_image(game->mlx, tmp);
	mlx_delete_texture(tmp);
	tmp = mlx_load_png("images/box_l.png");
	game->box_l = mlx_texture_to_image(game->mlx, tmp);
	mlx_delete_texture(tmp);
	tmp = mlx_load_png("images/box_r.png");
	game->box_r = mlx_texture_to_image(game->mlx, tmp);
	mlx_delete_texture(tmp);
	tmp = mlx_load_png("images/grinch.png");
	game->grinch = mlx_texture_to_image(game->mlx, tmp);
	mlx_delete_texture(tmp);
	tmp = mlx_load_png("images/grinch2.png");
	game->grinch2 = mlx_texture_to_image(game->mlx, tmp);
	mlx_delete_texture(tmp);
	tmp = mlx_load_png("images/sparks.png");
	game->sparks = mlx_texture_to_image(game->mlx, tmp);
	mlx_delete_texture(tmp);
	game->twod = ft_split(game->map, '\n');
	if (!game->twod)
		ft_error_exit("malloc for split failed.", 1);
	game->tick = 0;
	ft_fill_window(game);
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
			mlx_image_to_window(game->mlx, game->snow, x * PXL, y * PXL);
			if (game->twod[y][x] == '1')
				mlx_image_to_window(game->mlx, game->tree, x * PXL, y * PXL);
			else if (game->twod[y][x] == 'P')
			{
				mlx_image_to_window(game->mlx, game->santa, x * PXL, y * PXL);
				game->p_x = x;
				game->p_y = y;
			}
			else if (game->twod[y][x] == 'E')
				mlx_image_to_window(game->mlx, game->slay, x * PXL, y * PXL);
		}
	}
	ft_fill_window_rest(game);
}

static void	ft_fill_window_rest(t_game *game)
{
	int32_t	x;
	int32_t	y;

	y = -1;
	while (++y < game->height)
	{
		x = -1;
		while (++x < game->width)
		{
			if (game->twod[y][x] == 'C')
			{
				mlx_image_to_window(game->mlx, game->gifts, x * PXL, y * PXL);
				mlx_image_to_window(game->mlx, game->sparks, x * PXL, y * PXL);
				game->sparks->enabled = false;
			}
			else if (game->twod[y][x] == 'G')
			{
				mlx_image_to_window(game->mlx, game->grinch, x * PXL, y * PXL);
				mlx_image_to_window(game->mlx, game->grinch2, x * PXL, y * PXL);
				game->grinch2->enabled = false;
			}
		}
	}
}
