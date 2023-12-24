/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_and_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 16:40:51 by frmurcia          #+#    #+#             */
/*   Updated: 2023/12/24 16:58:28 by frmurcia         ###   ########.fr       */
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

void	ft_free_colors(t_map_color *color)
{
	if (color->floor_color)
		free(color->floor_color);
	if (color->ceil_color)
		free(color->ceil_color);
}

void	ft_read_cub(char **argv, t_textures *text, t_map *map)
{
	int		fd;
	char	*line;
	int		line_number;

	line_number = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_write_error("Error\nOpening map file\n");
	line = get_next_line(fd);
	if (!line)
		ft_write_error("Error\nReading lines of the map\n");
	while (line)
	{
		if (!is_empty_or_spaces(line) && only_map_chars(line))
			process_map_line(map, line, &line_number);
		else if (!is_empty_or_spaces(line) && !only_map_chars(line))
			process_textures(text, line);
		free(line);
		line = get_next_line(fd);
	}
	process_texture_raw(text);
	map->map_end = line_number;
	set_measures_and_close(map, line_number, fd);
}

void	ft_start_map(char **argv)
{
	t_textures	texture;
	t_map_color	color;
	t_map		map;
	t_player	player;

	init_textures(&texture);
	init_color(&color);
	init_map(&map);
	ft_read_cub(argv, &texture, &map);
	ft_check_color(&color);
	get_color_floor(&color, &texture);
	get_color_ceil(&color, &texture);
	create_2d(&map);
	print_filled_map(&map);
	copy_line_to_map(&map);
	print_filled_map(&map);
	init_player(&player);
	get_player(&map, &player);
	free_textures(&texture);
	ft_free_colors(&color);
	ft_free_map(&map);
	exit(1);
}
