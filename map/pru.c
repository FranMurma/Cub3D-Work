# include "map.h"

void	process_map_line(t_map *map, char *line, int *line_number)
{
	if (!map->map_raw)
	{
		if (is_valid_map_line(line, map) && !(is_empty_or_spaces(line)))
		{
			map->found_map = true;
			map->map_raw = ft_strdup(line);
			map->map_start = *line_number;
		}
		else
			map->found_map = false;
	}
	else if (map->map_raw)
	{
		if (is_valid_line_inside(line, map) && !(is_empty_or_spaces(line)))
			map->map_raw = ft_strjoin(map->map_raw, line);
		else
		{
			free (line);
			free_init_map(map);
			ft_write_error("Error. Bad map!\n");
		}
	}
	if (map->map_raw)
		(*line_number)++;
}




	if (!is_valid_map_line(line, map))
	{
		map->found_map = false;
		printf("Line = %s\n", line);
	}
	else if (!map->map_raw && is_valid_map_line(line, map)
		&& !(is_empty_or_spaces(line)))
	{
		map->found_map = true;
		printf("1\n");
		map->map_raw = ft_strdup(line);
		map->map_start = *line_number;
		found_content = 1;
	}
	else if (map->map_raw && is_valid_line_inside(line, map)
		&& !(is_empty_or_spaces(line)))
	{
		map->found_map = true;
		printf("2\n");
		map->map_raw = ft_strjoin(map->map_raw, line);
		found_void = 0;
	}
	else if (map->map_raw && (is_empty_or_spaces(line)
			|| !is_valid_map_line(line, map)))
    {
		printf("3\n");
		found_void = 1;
		if (found_content && found_void)
		{
			free (line);
			free_init_map(map);
			ft_write_error("Error. Bad map!\n");
		}
	}
	(*line_number)++;
	free(line);
}
