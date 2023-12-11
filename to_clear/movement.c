/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 02:20:39 by mevangel          #+#    #+#             */
/*   Updated: 2023/12/11 21:39:26 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_do_move(t_game *game, int x_to, int y_to, int look);
static void	ft_update_player(t_game *game, int x_to, int y_to, char look);
static void	ft_print_moves(t_game *game);

void	ft_keyhook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	if (keydata.action != MLX_PRESS)
		return ;
	game = param;
	if (keydata.key == MLX_KEY_ESCAPE)
	{
		ft_printf("You didn't help Santa! :( \n");
		ft_exit_game(game, 0);
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
		ft_printf("Congrats! You helped Santa collect all the \
			gifts! \033[0;32mYOU WON!!\033[37m\n");
		ft_exit_game(game, 0);
	}
	else if (game->twod[y_to][x_to] == 'G')
	{
		ft_printf("Grinch stole Christmas! \033[31mYOU LOST!\033[37m\n");
		ft_exit_game(game, 0);
	}
}

static void	ft_update_player(t_game *game, int x_to, int y_to, char look)
{
	mlx_image_to_window(game->mlx, game->snow, game->p_x * PXL, \
		game->p_y * PXL);
	game->twod[game->p_y][game->p_x] = '0';
	game->twod[y_to][x_to] = 'P';
	game->p_x = x_to;
	game->p_y = y_to;
	mlx_image_to_window(game->mlx, game->snow, game->p_x * PXL, \
		game->p_y * PXL);
	if (look == 'W')
		mlx_image_to_window(game->mlx, game->santa_back, game->p_x * PXL, \
			game->p_y * PXL);
	else if (look == 'S')
		mlx_image_to_window(game->mlx, game->santa, game->p_x * PXL, \
			game->p_y * PXL);
	else if (look == 'A')
		mlx_image_to_window(game->mlx, game->santa_left, game->p_x * PXL, \
			game->p_y * PXL);
	else if (look == 'D')
		mlx_image_to_window(game->mlx, game->santa_right, game->p_x * PXL, \
			game->p_y * PXL);
	ft_print_moves(game);
}

static void	ft_print_moves(t_game *game)
{
	static int	moves = 0;
	char		*str_moves;

	mlx_image_to_window(game->mlx, game->box_l, (game->width - 2) * PXL, \
		(game->height - 1) * PXL);
	mlx_image_to_window(game->mlx, game->box_r, (game->width - 1) * PXL, \
		(game->height - 1) * PXL);
	str_moves = ft_itoa(++moves);
	mlx_put_string(game->mlx, "Moves: ", (game->width * PXL) - 140, \
		(game->height * PXL) - 50);
	mlx_put_string(game->mlx, str_moves, (game->width * PXL) - 70, \
		(game->height * PXL) - 50);
	free(str_moves);
}

void	ft_animation(void *param)
{
	t_game	*game;
	int32_t	x;
	int32_t	y;
	uint8_t	toggle;
	uint8_t	toggle2;

	game = param;
	toggle = (game->tick / 30) % 2;
	toggle2 = (game->tick / 22) % 2;
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
				game->sparks->enabled = !toggle2;
		}
	}
	game->tick++;
}
