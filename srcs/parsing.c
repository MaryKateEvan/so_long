/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:02:30 by mevangel          #+#    #+#             */
/*   Updated: 2023/11/21 21:31:59 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../my_lib/libft.h"

static void	ft_find_p_e_c(t_game *game, char *map)
{
	int	p;
	int	e;

	p = 0;
	e = 0;
	game->coins = 0;
	while (*(map++) != '\0')
	{
		while (*map != '\n' && *map != '\0')
		{
			if (*map == 'P')
				p++;
			else if (*map == 'E')
				e++;
			else if (*map == 'C')
				game->coins++;
			map++;
		}
	}
	if (p != 1)
		ft_error_exit("the game must have only one player starting position", 0);
	if (e != 1)
		ft_error_exit("the game must have only one exit", 0);
	if (game->coins < 1)
		ft_error_exit("the game must have at least one collectible", 0);
}

static void	ft_check_characters(t_game *game)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = game->map;
	while (tmp[i++] != '\0')
	{
		while (tmp[i] != '\n' && tmp[i] != '\0')
		{
			if (!(tmp[i] == '0' || tmp[i] == '1' || tmp[i] == 'C' || 
					tmp[i] == 'E' || tmp[i] == 'P'))
				ft_error_exit("non acceptable character inside the map.", 0);
			if (tmp[i] == 'P')
				game->player_idx = i;
			if (tmp[i] == 'E')
				game->exit_idx = i;
			i++;
		}
	}
	ft_find_p_e_c(game, game->map);
}

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
	ft_check_characters(game);
	ft_check_walls(game);
	// ft_check_player_paths()
}


