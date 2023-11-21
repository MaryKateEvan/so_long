/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:02:30 by mevangel          #+#    #+#             */
/*   Updated: 2023/11/21 19:15:38 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../my_lib/libft.h"

static void	ft_check_characters(char *map)
{
	int	p;
	int	e;
	int	c;

	p = 0;
	e = 0;
	c = 0;
	while (*(map++) != '\0')
	{
		while (*map != '\n' && *map != '\0')
		{
			if (!(*map == '0' || *map == '1' || *map == 'C' || *map == 'E' 
					|| *map == 'P'))
				ft_error_exit("non acceptable character inside the map.", 0);
			if (*map == 'P')
				p++;
			else if (*map == 'E')
				e++;
			else if (*map == 'C')
				c++;
			map++;
		}
	}
	if (p != 1 || e != 1 || c < 1)
		ft_error_exit("invalid map", 0);
}

// void	ft_num_pec()

static void	ft_check_walls(t_game *game)
{
	int		x;
	int		y;
	char	**tmp;

	y = 0;
	tmp = ft_split(game->map, '\n');
	if (!tmp)
		ft_error_exit("malloc for split failed.", 1);
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			// printf("Checking (%d, %d): %c\n", x, y, tmp[y][x]);
			if ((y == 0 || y == (game->height - 1) || x == 0 || 
				x == (game->width - 1)) && tmp[y][x] != '1')
			{
				ft_free_2darr(tmp);
				ft_error_exit("map is not surrounded by walls.", 0);
			}
			x++;
		}
		y++;
	}
	ft_free_2darr(tmp);
}

void	ft_check_given_map(int map_fd, t_game *game)
{
	char	*line;

	line = get_next_line(map_fd);
	ft_strlcpy(game->map, line, ft_strlen(line) + 1);
	game->width = ft_linelen(line);
	game->height = 0;
	while (line != NULL)
	{
		game->height++;
		free(line);
		line = get_next_line(map_fd);
		if (line == NULL)
			break ;
		if (ft_linelen(line) != game->width)
		{
			free(line);
			ft_error_exit("map is not rectangular.", 0);
		}
		ft_strlcat(game->map, line, 10000);
	}
	free(line);
	ft_check_characters(game->map);
	ft_check_walls(game);
	ft_check_player_paths()
}


