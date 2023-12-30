/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_and_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 16:40:51 by frmurcia          #+#    #+#             */
/*   Updated: 2023/12/30 11:36:43 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "../premap/texture.h"
#include "../premap/color.h"
#include "../player/player.h"

void	ft_free_map(t_map *map)
{
	int	i;

	i = 0;
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

void	process_line(t_textures *text, t_map *map, char *line, int *line_number)
{
	if (!is_empty_or_spaces(line) && !only_map_chars(line))
		process_textures(text, line);
	else if (!is_empty_or_spaces(line) && only_map_chars(line))
	{
		if (text->path_found == true && map->space_found == false)
		{
			map->found_map = true;
			process_map_line(map, line, line_number);
		}
		else if (text->path_found == false)
			ft_write_error("Error\nCan't find paths before map lines\n");
		else if (map->space_found == true)
			ft_write_error("Error\nSpaces between map lines\n");
	}
	else if (is_empty_or_spaces(line) && map->found_map)
		map->space_found = true;
}

void	ft_read_cub(char **argv, t_textures *text, t_map *map)
{
	int		fd;
	char	*line;
	int		line_number;

	line_number = 0;
	text->path_found = false;
	map->space_found = false;
	map->found_map = false;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_write_error("Error\nOpening map file\n");
	line = get_next_line(fd);
	if (!line)
		ft_write_error("Error\nReading lines of the map\n");
	while (line)
	{
		process_line(text, map, line, &line_number);
		free(line);
		line = get_next_line(fd);
	}
	process_texture_raw(text);
	map->map_end = line_number;
	set_measures_and_close(map, line_number, fd);
}

/****************
 * ES UNA FUNCION SOLO PARA PROBAR QUE TODO SE CARGA BIEN.
 * BORRAR DESPUES!!!
 ******** */
void	print_everything(t_map *map, t_player *player,
		t_textures *texture, t_map_color *color)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->max_height)
	{
		j = 0;
		while (j < map->max_width)
		{
			printf("%c", map->map_2d[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}
	printf("----------------------------------------------------\n");
	printf("Player position on X and Y axes: %f and %f\n",
		player->px, player->py);
	printf("Player direction X axe: %f\n", player->dirx);
	printf("Player direction Y axe: %f\n", player->diry);
	printf("NO %s\n", texture->paths->north);
	printf("SO %s\n", texture->paths->south);
	printf("EA %s\n", texture->paths->east);
	printf("WE %s\n", texture->paths->west);
	printf("Ceil Color: %u\n", color->ceil_color->hex);
	printf("Floor Color: %u\n", color->floor_color->hex);
	printf("----------------------------------------------------\n");
}

void	ft_start_map(char **argv)
{
	t_textures	texture;
	t_map_color	color;
	t_map		map;
//	t_player	player;

	init_textures(&texture);
	init_color(&color);
	init_map(&map);
	ft_read_cub(argv, &texture, &map);
	get_color_floor(&color, &texture);
	get_color_ceil(&color, &texture);
	ft_check_color(&color);
	create_2d(&map);      /////AQUISALE!!!!!! NO ME LO PUEDO CXREWWE!!!
//	copy_line_to_map(&map);
//	init_player(&player);
//	get_player(&map, &player);
//	print_everything(&map, &player, &texture, &color);
	system ("leaks a.out");
	free_textures(&texture);
//	system ("leaks a.out");
	ft_free_colors(&color);
//	system ("leaks a.out");
	ft_free_map(&map);
//	system ("leaks a.out");
	exit(1);
}
