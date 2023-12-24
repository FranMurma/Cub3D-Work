/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:59:44 by frmurcia          #+#    #+#             */
/*   Updated: 2023/12/24 13:27:46 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "player.h"
# include "../map/map.h"

void	init_player(t_player *player)
{
	player->px = 0;
	player->py = 0;
	player->dirx = 0;
	player->diry = 0;
}


void    get_player(t_map *map, t_player *player)
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
	printf("P = %i\n", p);
	if (p != 1)
		ft_write_error("Error\nBad player position (0 players or more than 1)\n");
	printf("Number of players: %i\n", p);
	printf("Player position\nX = %i\nY = %i\n", x, y);
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
	map->map_2d[y][x] = '0';
	if (!check_map(map))
		ft_write_error("Error\nThe map is not closed or are spaces inside\n");
	else
	{
		printf("Player direction X axe: %f\n", player->dirx);
		printf("Player direction Y axe: %f\n", player->diry);
	}
}

bool	is_space_around(t_map *map, int y, int x)
{
	if (map->map_2d[y - 1][x] == ' ')
		return (true);
	else if  (map->map_2d[y + 1][x] == ' ')
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
	int y;
	int	x;

	y = 1;
	while (y < map->max_height)
	{
		x = 1;
        while (x < map->max_width)
		{
			if (map->map_2d[y][x] == '0' && is_space_around(map, y, x))
				return (false);  // Si hay un '0' rodeado por ' ', retorna falso
			x++;
		}
		y++;
	}
	return (true);  // Si no se encontraron problemas, retorna verdadero
}
