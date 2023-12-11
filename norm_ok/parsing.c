/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:02:30 by mevangel          #+#    #+#             */
/*   Updated: 2023/12/11 02:25:07 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../my_lib/libft.h"

static void	ft_find_p_e_c(t_game *game, char *map);
static void	ft_check_surrounding_walls(t_game *game);
static void	ft_check_player_paths(t_game *game);
static void	ft_flood_fill(char *map, int idx, int *coins, int *exit);

void	ft_parse_map(t_game *game)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = game->map;
	while (tmp[i++] != '\0')
	{
		while (tmp[i] != '\n' && tmp[i] != '\0')
		{
			if (!(tmp[i] == '0' || tmp[i] == '1' || tmp[i] == 'C' || \
					tmp[i] == 'E' || tmp[i] == 'P' || tmp[i] == 'G'))
				ft_error_exit("non acceptable character(s) inside the map.", 0);
			if (tmp[i] == 'P')
				game->player_idx = i;
			i++;
		}
	}
	ft_find_p_e_c(game, game->map);
	ft_check_surrounding_walls(game);
	ft_check_player_paths(game);
}

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
			if ((y == 0 || y == (game->height - 1) || x == 0 || \
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

static void	ft_check_player_paths(t_game *game)
{
	int		coins;
	int		exit;
	char	*tmp_map;
	int		i;

	coins = 0;
	exit = 0;
	i = -1;
	tmp_map = ft_strdup(game->map);
	while (tmp_map[++i])
	{
		if (tmp_map[i] == 'G')
			tmp_map[i] = '1';
	}
	ft_flood_fill(tmp_map, game->player_idx, &coins, &exit);
	free(tmp_map);
	if (coins != game->coins && exit == 0)
		ft_error_exit("exit and collectible(s) not reachable", 0);
	if (coins != game->coins)
		ft_error_exit("collectible(s) not reachable", 0);
	if (exit == 0)
		ft_error_exit("exit is not reachable", 0);
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
		return ;
	}
	if (map[idx] == 'C')
		(*coins)++;
	map[idx] = '1';
	ft_flood_fill(map, idx - 1, coins, exit);
	ft_flood_fill(map, idx + 1, coins, exit);
	ft_flood_fill(map, idx - step, coins, exit);
	ft_flood_fill(map, idx + step, coins, exit);
}
