/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 09:24:39 by mevangel          #+#    #+#             */
/*   Updated: 2023/12/25 23:34:13 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <fcntl.h>
# include "my_lib/my_lib.h"
# include "MLX42/include/MLX42/MLX42.h"

# define PXL 84

typedef struct s_game
{
	char		map[500];
	char		**twod;
	int32_t		height;
	int32_t		width;
	int32_t		coins;
	int32_t		player_idx;
	int32_t		p_y;
	int32_t		p_x;
	int32_t		tick;
	mlx_t		*mlx;
	mlx_image_t	*tree;
	mlx_image_t	*snow;
	mlx_image_t	*santa;
	mlx_image_t	*santa_left;
	mlx_image_t	*santa_right;
	mlx_image_t	*santa_back;
	mlx_image_t	*gifts;
	mlx_image_t	*slay;
	mlx_image_t	*grinch;
	mlx_image_t	*grinch2;
	mlx_image_t	*sparks;
	mlx_image_t	*box_l;
	mlx_image_t	*box_r;
}	t_game;

void	ft_parse_map(t_game *game);
void	ft_window_images(t_game *game);
void	ft_keyhook(mlx_key_data_t keydata, void *param);
void	ft_animation(void *param);
void	ft_exit_game(t_game *game, int exit_code);

#endif //SO_LONG_H