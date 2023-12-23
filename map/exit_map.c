/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:19:17 by frmurcia          #+#    #+#             */
/*   Updated: 2023/12/23 12:37:50 by frmurcia         ###   ########.fr       */
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

void free_map(t_map *map)
{
    if (map)
    {
        // Liberar map->map_raw si es necesario
        if (map->map_raw)
            free(map->map_raw);

        // Liberar map->map_2d si es necesario
        if (map->map_2d)
        {
            int i;
            for (i = 0; i < map->max_height; i++)
                free(map->map_2d[i]);
            free(map->map_2d);
        }
    }
}
