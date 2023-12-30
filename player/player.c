/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:59:44 by frmurcia          #+#    #+#             */
/*   Updated: 2023/12/29 16:05:18 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "../map/map.h"

void	init_player(t_player *player)
{
	player->px = 0;
	player->py = 0;
	player->dirx = 0;
	player->diry = 0;
}

void	get_player(t_map *map, t_player *player)
{
	int	y;
	int	x;
	int	p;

	y = 0;
	p = 0;
	while (y < map->max_height)
	{
		x = 0;
		while (x < map->max_width)
		{
			if (map->map_2d[y][x] == 'N' || map->map_2d[y][x] == 'S'
				|| map->map_2d[y][x] == 'W' || map->map_2d[y][x] == 'E')
			{
				player->px = x;
				player->py = y;
				get_player_direction(map, player, y, x);
				p++;
			}
			x++;
		}
		y++;
	}
	if (p != 1)
		ft_write_error("Error\nBad player (0 players or more than 1)\n");
}

void	get_player_direction(t_map *map, t_player *player, int y, int x)
{
	if (map->map_2d[y][x] == 'N')
	{
		player->diry = 1;
		player->dirx = 0;
	}
	else if (map->map_2d[y][x] == 'S')
	{
		player->diry = -1;
		player->dirx = 0;
	}
	else if (map->map_2d[y][x] == 'W')
	{
		player->diry = 0;
		player->dirx = -1;
	}
	else if (map->map_2d[y][x] == 'E')
	{
		player->diry = 0;
		player->dirx = 1;
	}
	map->map_2d[(int)(player->py)][(int)(player->px)] = '0';
	if (!check_map(map))
		ft_write_error("Error\nThe map is not closed or are spaces inside\n");
}

bool	is_space_around(t_map *map, int y, int x)
{
	if (map->map_2d[y - 1][x] == ' ')
		return (true);
	else if (map->map_2d[y + 1][x] == ' ')
		return (true);
	else if (map->map_2d[y][x - 1] == ' ')
		return (true);
	else if (map->map_2d[y][x + 1] == ' ')
		return (true);
	else
		return (false);
}

bool	check_map(t_map *map)
{
	int	y;
	int	x;

	y = 1;
	while (y < map->max_height)
	{
		x = 1;
		while (x < map->max_width)
		{
			if (map->map_2d[y][x] == '0' && is_space_around(map, y, x))
				return (false);
			x++;
		}
		y++;
	}
	return (true);
}
