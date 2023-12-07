/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:02:30 by mevangel          #+#    #+#             */
/*   Updated: 2023/12/03 19:05:03 by mevangel         ###   ########.fr       */
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
		ft_error_exit("the game must have one player starting position", 0);
	if (e != 1)
		ft_error_exit("the game must have one exit", 0);
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

static void	ft_check_surrounding_walls(t_game *game)
{
	int		x;
	int		y;
	char	**array;

	y = 0;
	array = ft_split(game->map, '\n');
	if (!array)
		ft_error_exit("malloc for split failed.", 1);
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			// printf("Checking (%d, %d): %c\n", x, y, tmp[y][x]);
			if ((y == 0 || y == (game->height - 1) || x == 0 || 
				x == (game->width - 1)) && array[y][x] != '1')
			{
				ft_free_2darr(array);
				ft_error_exit("map is not surrounded by walls.", 0);
			}
			x++;
		}
		y++;
	}
	ft_free_2darr(array);
}

static void	ft_flood_fill(char *map, int idx, int *coins, int *exit)
{
	int	step;

	step = ft_linelen(map) + 1;
	if (map[idx] == '1')
		return ;
	if (map[idx] == 'E')
	{
		(*exit)++;
		// return ; //with this line i save the case the exit is before a collectible, but i have problem with exit says unreachable though it is
	}
	if (map[idx] == 'C')
		(*coins)++;
	map[idx] = '1';
	ft_flood_fill(map, idx - 1, coins, exit);
	ft_flood_fill(map, idx + 1, coins, exit);
	ft_flood_fill(map, idx - step, coins, exit);
	ft_flood_fill(map, idx + step, coins, exit);
}

static void	ft_check_player_paths(t_game *game)
{
	int		coins;
	int		exit;
	char	*tmp_map;

	coins = 0;
	exit = 0;
	tmp_map = ft_strdup(game->map);
	ft_flood_fill(tmp_map, game->player_idx, &coins, &exit);
	free(tmp_map);
	if (coins != game->coins && exit != 1)
		ft_error_exit("exit and collectible(s) not reachable", 0);
	if (coins != game->coins)
		ft_error_exit("collectible(s) not reachable", 0);
	if (exit != 1)
		ft_error_exit("exit is not reachable", 0);
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
	ft_check_surrounding_walls(game);
	ft_check_player_paths(game);
}


