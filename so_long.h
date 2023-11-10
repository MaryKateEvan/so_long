/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 09:24:39 by mevangel          #+#    #+#             */
/*   Updated: 2023/11/10 11:29:08 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h> //for the open function

# include "my_lib/libft.h"
# include "MLX42/include/MLX42/MLX42.h"

void	ft_error_exit(int err_code);

#endif //SO_LONG_H