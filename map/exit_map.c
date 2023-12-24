/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:19:17 by frmurcia          #+#    #+#             */
/*   Updated: 2023/12/24 16:18:23 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	free_init_map(t_map *map)
{
	write (1, "free_init, en exit\n", 19);
	free(map->map_raw);
	free (map->map_2d);
	free(map);
	exit (-1);
}

void	free_map_2d(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->max_height)
	{
		free(map->map_2d[i]);
		i++;
	}
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	if (map)
	{
		if (map->map_raw)
			free(map->map_raw);
		if (map->map_2d)
		{
			while (i < map->max_height)
			{
				free(map->map_2d[i]);
				i++;
			}
			free(map->map_2d);
		}
	}
}
