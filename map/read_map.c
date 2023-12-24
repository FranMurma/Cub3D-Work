/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:27:50 by frmurcia          #+#    #+#             */
/*   Updated: 2023/12/24 16:39:16 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

bool	is_empty_or_spaces(char *line)
{
	while (*line)
	{
		if (*line != ' ' && *line != '\n' && *line != '\r'
			&& *line != '\f' && *line != '\v')
			return (false);
		line++;
	}
	return (true);
}

void	append_line_to_map_raw(t_map *map, char *line, int *line_number)
{
	char	*tmp;
	char	*dup;
	int		len;

	len = ft_strlen(line);
	while (len > 0 && line[len - 2] == ' ')
		len--;
	if (len > map->max_width)
		map->max_width = len + 1;
	tmp = ft_strndup(line, len);
	tmp[len - 1] = '\n';
	if (!map->map_raw)
	{
		map->found_map = true;
		map->map_raw = ft_strdup(tmp);
		map->map_start = *line_number;
	}
	if (map->map_raw)
	{
		dup = ft_strjoin(map->map_raw, tmp);
		free(map->map_raw);
		map->map_raw = ft_strdup(dup);
		free(dup);
	}
	free(tmp);
}

void	process_map_line(t_map *map, char *line, int *line_number)
{
	if (!map->map_raw)
	{
		if (is_valid_map_line(line))
		{
			map->found_map = true;
			append_line_to_map_raw(map, line, line_number);
		}
		else
			map->found_map = false;
	}
	else if (map->map_raw)
	{
		if (is_valid_line_inside(line))
			append_line_to_map_raw(map, line, line_number);
		else
			ft_write_error("Error\nMap lines without allowed chars!\n");
	}
	if (map->map_raw)
		(*line_number)++;
}

void	set_measures_and_close(t_map *map, int line_number, int fd)
{
	if (close(fd) == -1)
		ft_write_error("Error\nWhile closing file descriptor\n");
	if (map->found_map)
	{
		map->map_end = line_number;
		map->max_height = map->map_end - map->map_start + 3;
	}
	else
		ft_write_error("Error\nBad map, not only map chars!\n");
}

void	print_filled_map(t_map *map)
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
	printf("\n");
}
