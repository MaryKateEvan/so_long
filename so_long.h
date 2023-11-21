/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 09:24:39 by mevangel          #+#    #+#             */
/*   Updated: 2023/11/21 23:29:49 by mevangel         ###   ########.fr       */
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

typedef struct s_coords
{
	int	y;
	int	x;
}	t_coords;

typedef struct s_game
{
	// char	**map;
	char	map[10000];
	int		height;
	int		width;
	int		coins;
	int		player_idx;
	int		exit_idx;
}	t_game;

void	ft_error_exit(char *perr_msg, int err_code);
void	ft_check_given_map(int map_fd, t_game *game);

#endif //SO_LONG_H