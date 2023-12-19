/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:42:22 by frmurcia          #+#    #+#             */
/*   Updated: 2023/12/19 19:25:10 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

t_map	*init_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		ft_write_error("Error\nCan't allocate memorry for map\n");
	map->map_raw = NULL;
	map->max_height = 0;
	map->max_width = 0;
//	printf("Map initialized successfully.\n");
	return (map);
}

/******
 * No podemos hacer un free de map_2d, porque es una referencia de map->map_2d.
 * Habra que liberarlo al final del programa.
 * ****/
void	create_2d(t_map *map)
{
	char	**map_2d;
	int		i;
	int		j;

	i = 0;
	map_2d = (char **)malloc((map->max_height) * sizeof(char *));
	if (!map_2d)
	{
		ft_write("Error\nCan't allocate memorry for map 2d\n");
		free_init_map(map);
	}
	while (i < map->max_height)
	{
		j = 0;
		map_2d[i] = (char *)malloc((map->max_width) * sizeof(char));
//		printf("Dirección de memoria de 'map_2d[i]': %p\n", (void *)map_2d[i]);
		while (j < map->max_width)
		{
			map_2d[i][j] = '-';
			j++;
		}
		i++;
	}
	map->map_2d = map_2d;
	i = 0;
//	free_init_map(map);
//	free_map_2d(map, map_2d);
}

void	handle_slash_en(t_map *map, int *y, int *k, int *x)
{
	(*x) = 1;
	(*y)++;
	(*k)++;
}

void	handle_tabs(t_map *map, int y, int *x, int *k)
{
	int	i;

	i = 0;
	while (i < 4 && *x < map->max_width - 1)
	{
		map->map_2d[y][(*x)] = '-';
		(*x)++;
		i++;
	}
	(*k)++;
}

void	copy_line_to_map(t_map *map)
{
	int	y;
	int	x;
	int	k;

	y = 1;
	x = 1;
	k = 0;
//	printf("Entro en COPY\n");
	while (y <= map->max_height - 1 && map->map_raw[k] != '\0')
	{
		while (x <= map->max_width - 1)
		{
			if (map->map_raw[k] != '\n' && map->map_raw[k] != '\0'
				&& map->map_raw[k] != '\t')
				map->map_2d[y][x++] = map->map_raw[k++];
			else if (map->map_raw[k] == ' ')
			{
				map->map_2d[y][x++] = '-';
				k++;
			}
			else if (map->map_raw[k] == '\t')
				handle_tabs(map, y, &x, &k);
			else if (map->map_raw[k] == '\n')
				handle_slash_en(map, &y, &k, &x);
			else
				break ;
		}
	}
//	free (map->map_raw);
//	printf("LLEGO\n");
//	map->map_raw = NULL;
//	print_filled_map(map);
}
