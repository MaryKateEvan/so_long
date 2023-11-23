/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 09:24:39 by mevangel          #+#    #+#             */
/*   Updated: 2023/11/23 03:46:38 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h> //for the open function
# include <stdio.h> //for the perror function
# include <stdbool.h>

# include "my_lib/libft.h"
# include "MLX42/include/MLX42/MLX42.h"

# define RED "\033[1;31m"
# define SIZE 84

typedef struct s_coords
{
	int	y;
	int	x;
}	t_coords;

typedef struct s_game
{
	// variables for the map:
	char			map[10000];
	char			**array;
	int				height;
	int				width;
	int				coins;
	int				player_idx;
	int				exit_idx;
	//variables for the mlx and game:
	mlx_t			*mlx;
	mlx_texture_t	*santa;
	mlx_texture_t	*chimney;
	mlx_texture_t	*cookie;
	mlx_texture_t	*tree;
	mlx_texture_t	*floor;
	//images:
	mlx_image_t		*img_tree;
	mlx_image_t		*img_floor;
	mlx_image_t		*img_santa;
	mlx_image_t		*img_cookie;
	mlx_image_t		*img_chimney;
}	t_game;

void	ft_error_exit(char *perr_msg, int err_code);
void	ft_check_given_map(int map_fd, t_game *game);
void	ft_initialize_game(t_game *game);

#endif //SO_LONG_H