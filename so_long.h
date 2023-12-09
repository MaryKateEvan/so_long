/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 09:24:39 by mevangel          #+#    #+#             */
/*   Updated: 2023/12/09 00:04:20 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h> //for the open function
// # include <stdio.h> //for the perror function
// # include <stdbool.h>

# include "my_lib/libft.h"
# include "MLX42/include/MLX42/MLX42.h"

# define SIZE 84
// # define POSX game->pos.x

// typedef struct s_coords
// {
// 	int32_t x;
// 	int32_t y;
// }	t_coords;

typedef struct s_game
{
	// variables for the map:
	char			map[10000];
	char			**twod;
	int32_t			height;
	int32_t			width;
	int32_t			coins;
	int32_t			player_idx;
	int32_t			p_arr[2];
	// t_coords		p_pos;
	int32_t			p_y;
	int32_t			p_x;
	int32_t			exit_idx;
	//variables for the mlx and game:
	mlx_t			*mlx;
	mlx_image_t		*tree;
	mlx_image_t		*snow;
	mlx_image_t		*santa;
	mlx_image_t		*santa_left;
	mlx_image_t		*santa_right;
	mlx_image_t		*santa_back;
	mlx_image_t		*gifts;
	mlx_image_t		*slay;
	mlx_image_t		*grinch;
	mlx_image_t		*grinch2;
	mlx_image_t		*gifts2;
	mlx_image_t		*sparks;
	mlx_image_t		*box_l;
	mlx_image_t		*box_r;
	//the "step" to change y axon by 1
	int32_t			step;
	int32_t			tick;
}	t_game;

void	ft_error_exit(char *perr_msg, int err_code);
void	ft_check_characters(t_game *game);
// void	ft_check_given_map(int map_fd, t_game *game);
void	ft_initialize_game(t_game *game);
// void	ft_hook(void *param);
void	ft_my_keyhook(mlx_key_data_t keydata, void *param);

#endif //SO_LONG_H