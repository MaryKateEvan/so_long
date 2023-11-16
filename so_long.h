/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 09:24:39 by mevangel          #+#    #+#             */
/*   Updated: 2023/11/16 11:19:28 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h> //for the open function

# include "my_lib/libft.h"
# include "MLX42/include/MLX42/MLX42.h"

# define RED "\033[1;31m"

typedef struct s_game
{
	int map_height;
	int map_width;
}	t_game;


void	ft_error_exit(int err_code);

#endif //SO_LONG_H