/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 02:20:39 by mevangel          #+#    #+#             */
/*   Updated: 2023/12/09 00:23:57 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../my_lib/libft.h"

static void	ft_print_moves(t_game *game)
{
	static int	moves = 0;
	char		*str_moves;

	mlx_image_to_window(game->mlx, game->box_l, (game->width - 2) * SIZE, 
		(game->height - 1) * SIZE);
	mlx_image_to_window(game->mlx, game->box_r, (game->width - 1) * SIZE, 
		(game->height - 1) * SIZE);
	str_moves = ft_itoa(++moves);
	mlx_put_string(game->mlx, "Moves: ", (game->width * SIZE) - 140, 
		(game->height * SIZE) - 50);
	mlx_put_string(game->mlx, str_moves, (game->width * SIZE) - 70, 
		(game->height * SIZE) - 50);
	free(str_moves);
}

static void	ft_update_player(t_game *game, int x_to, int y_to, char look)
{
	mlx_image_to_window(game->mlx, game->snow, game->p_x * SIZE, 
		game->p_y * SIZE);
	game->twod[game->p_y][game->p_x] = '0';
	game->twod[y_to][x_to] = 'P';
	game->p_x = x_to;
	game->p_y = y_to;
	mlx_image_to_window(game->mlx, game->snow, game->p_x * SIZE, 
		game->p_y * SIZE);
	if (look == 'W')
		mlx_image_to_window(game->mlx, game->santa_back, game->p_x * SIZE, 
			game->p_y * SIZE);
	else if (look == 'S')
		mlx_image_to_window(game->mlx, game->santa, game->p_x * SIZE, 
			game->p_y * SIZE);
	else if (look == 'A')
		mlx_image_to_window(game->mlx, game->santa_left, game->p_x * SIZE, 
			game->p_y * SIZE);
	else if (look == 'D')
		mlx_image_to_window(game->mlx, game->santa_right, game->p_x * SIZE, 
			game->p_y * SIZE);
	ft_print_moves(game);
}

static void	ft_do_move(t_game *game, int x_to, int y_to, int look)
{
	if (game->twod[y_to][x_to] == '0')
		ft_update_player(game, x_to, y_to, look);
	else if (game->twod[y_to][x_to] == 'C')
	{
		game->coins--;
		ft_update_player(game, x_to, y_to, look);
	}
	else if (game->twod[y_to][x_to] == 'E' && game->coins == 0)
	{
		ft_update_player(game, x_to, y_to, look);
		ft_printf("Congrats! You helped Santa collect all the gifts! \033[0;32mYOU WON!!\033[37m\n");
		ft_free_2darr(game->twod);
		mlx_close_window(game->mlx);
		mlx_terminate(game->mlx);
		exit(EXIT_SUCCESS);
	}
	else if (game->twod[y_to][x_to] == 'G')
	{
		ft_printf("Grinch stole Christmas! \033[31mYOU LOST!\033[37m\n");
		ft_free_2darr(game->twod);
		mlx_close_window(game->mlx);
		mlx_terminate(game->mlx);
		exit(EXIT_SUCCESS);
	}
}

void	ft_my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	if (keydata.action != MLX_PRESS)
		return ;
	game = param;
	if (keydata.key == MLX_KEY_ESCAPE)
	{
		ft_printf("You didn't help Santa! :( \n");
		mlx_close_window(game->mlx);
		mlx_terminate(game->mlx);
		exit(EXIT_SUCCESS);
	}
	if ((keydata.key == MLX_KEY_W) || (keydata.key == MLX_KEY_UP))
		ft_do_move(game, game->p_x, game->p_y - 1, 'W');
	if ((keydata.key == MLX_KEY_S) || (keydata.key == MLX_KEY_DOWN))
		ft_do_move(game, game->p_x, game->p_y + 1, 'S');
	if ((keydata.key == MLX_KEY_A) || (keydata.key == MLX_KEY_LEFT))
		ft_do_move(game, game->p_x - 1, game->p_y, 'A');
	if ((keydata.key == MLX_KEY_D) || (keydata.key == MLX_KEY_RIGHT))
		ft_do_move(game, game->p_x + 1, game->p_y, 'D');
}

void	ft_initialize_game(t_game *game)
{
	mlx_texture_t *tmp;

	game->twod = ft_split(game->map, '\n');
	if (!game->twod)
		ft_error_exit("malloc for split failed.", 1);
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
	tmp = mlx_load_png("images/gifts2.png");
	game->gifts2 = mlx_texture_to_image(game->mlx, tmp);
	mlx_delete_texture(tmp);
	tmp = mlx_load_png("images/sparks.png");
	game->sparks = mlx_texture_to_image(game->mlx, tmp);
	mlx_delete_texture(tmp);
	game->tick = 0;
	// ft_fill_window(game);
}
