/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 02:20:39 by mevangel          #+#    #+#             */
/*   Updated: 2023/12/07 14:38:34 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../my_lib/libft.h"

static void	ft_fill_window(t_game *game)
{
	int		x;
	int		y;
	char	**map;

	map = ft_split(game->map, '\n');
	if (!map)
		ft_error_exit("malloc for split failed.", 1);
	y = -1;
	while (++y < game->height)
	{
		x = -1;
		while (++x < game->width)
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
		}
	}
	ft_free_2darr(map);
}

void	ft_update_player(t_game *game, int go_to, int print)
{
	static int	moves = 0;

	game->map[game->player_idx] = '0';
	game->map[go_to] = 'P';
	game->player_idx = go_to;
	ft_fill_window(game);
	if (print == 1)
	{
		ft_putstr_fd("Moves: ", 1);
		ft_putendl_fd(ft_itoa(++moves), 1);
	}
}

void	ft_do_move(t_game *game, int go_to)
{
	

	if (game->map[go_to] == '0')
	{
		ft_update_player(game, go_to, 1);
	}
	else if (game->map[go_to] == 'C')
	{
		game->coins--;
		ft_update_player(game, go_to, 1);
	}
	else if (game->map[go_to] == 'E' && game->coins == 0)
	{
		ft_update_player(game, go_to, 0);
		ft_putendl_fd("Congrats! Off Santa goes!", 1);
		mlx_close_window(game->mlx);
		mlx_terminate(game->mlx);
		exit(EXIT_SUCCESS);
	}
	// else if (game->map[go_to] == 'E' && game->coins != 0)
	// {
		
	// }

}

// void	ft_do_move(t_game *game, int go_to)
// {
// 	// if ((game->map[go_to] == '1') || (go_to < 0) || (go_to > (int)ft_strlen(game->map)))
// 	// 	return ;
// 	if (game->map[go_to] == '0')
// 	{
// 		game->map[game->player_idx] = '0';
// 		game->map[go_to] = 'P';
// 		game->player_idx = go_to;
// 		ft_fill_window(game);
// 	}
// 	else if (game->map[go_to] == 'C')
// 	{
// 		game->coins--;
// 		game->map[game->player_idx] = '0';
// 		game->map[go_to] = 'P';
// 		game->player_idx = go_to;
// 		ft_fill_window(game);
// 	}
// 	else if (game->map[go_to] == 'E' && game->coins == 0)
// 	{
// 		game->map[game->player_idx] = '0';
// 		game->map[go_to] = 'P';
// 		game->player_idx = go_to;
// 		ft_fill_window(game);
// 		ft_putendl_fd("Congrats! Off Santa goes!", 1);
// 		mlx_close_window(game->mlx);
// 		mlx_terminate(game->mlx);
// 		exit(EXIT_SUCCESS);
// 		return ;
// 	}
// 	else if (game->map[go_to] == 'E' && game->coins != 0)
// 	{
		
// 	}
// }

void	ft_my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	if (keydata.action != MLX_PRESS)
		return ;
	game = param;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(game->mlx);
	if ((keydata.key == MLX_KEY_W) || (keydata.key == MLX_KEY_UP))
		ft_do_move(game, game->player_idx - game->step);
	if ((keydata.key == MLX_KEY_S) || (keydata.key == MLX_KEY_DOWN))
		ft_do_move(game, game->player_idx + game->step);
	if ((keydata.key == MLX_KEY_A) || (keydata.key == MLX_KEY_LEFT))
		ft_do_move(game, game->player_idx - 1);
	if ((keydata.key == MLX_KEY_D) || (keydata.key == MLX_KEY_RIGHT))
		ft_do_move(game, game->player_idx + 1);
}

// void	ft_hook(void *param)
// {
// 	t_game	*game;

// 	game = param;
// 	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
// 		mlx_close_window(game->mlx);
// 	if (mlx_is_key_down(game->mlx, MLX_KEY_W)
// 		|| mlx_is_key_down(game->mlx, MLX_KEY_UP))
// 		ft_do_move(game, game->player_idx - game->step);
// 	if (mlx_is_key_down(game->mlx, MLX_KEY_S)
// 		|| mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
// 		ft_do_move(game, game->player_idx + game->step);
// 	if (mlx_is_key_down(game->mlx, MLX_KEY_A)
// 		|| mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
// 		ft_do_move(game, game->player_idx - 1);
// 	if (mlx_is_key_down(game->mlx, MLX_KEY_D)
// 		|| mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
// 		ft_do_move(game, game->player_idx + 1);
// }

void	ft_initialize_game(t_game *game)
{
	// char	**map;
	// game->twod = ft_split(game->map, '\n');
	// if (!game->twod)
	// 	ft_error_exit("malloc for split failed.", 1);
	// game->player_pos->x = 0;
	// game->player_pos->y = 0;
	
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
	game->step = ft_linelen(game->map) + 1;
	// map = ft_split(game->map, '\n');
	// if (!map)
	// 	ft_error_exit("malloc for split failed.", 1);
	ft_fill_window(game);

}