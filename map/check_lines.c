/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:55:13 by frmurcia          #+#    #+#             */
/*   Updated: 2023/12/09 13:19:14 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

bool	skip_whitespace(t_map *map, char *line, int *length, int *length_width)
{
	map->max_width = 0;
	*length = 0;
	*length_width = 0;
	while (line[*length] == ' ' || line[*length] == '\t')
	{
		if (line[*length] == '\t')
		{
			*length_width += TAB_SPACES;
			(*length)++;
		}
		else if (line[*length] == ' ')
		{
			(*length)++;
			(*length_width)++;
		}
		if (line[*length] == '\0')
			return (false);
	}
	return (true);
}

void	start_map(t_map *map, int *length, int *length_width, bool *map_started)
{
	*map_started = true;
	(*length)++;
	(*length_width)++;
}

void	process_other_chars(t_map *map, char *line, int *length,
		int *length_width)
{
	if (line[*length] == '\n' || line[*length] == ' ')
	{
		(*length)++;
		(*length_width)++;
	}
	else if (line[*length] == '\t')
	{
		(*length)++;
		(*length_width) += TAB_SPACES;
	}
}

bool	is_valid_map_line(char *line, t_map *map)
{
	int		length;
	int		length_width;
	bool	map_started;

	map->max_width = 0;
	length = 0;
	length_width = 0;
	map_started = false;
	while (line[length] == ' ' || line[length] == '\t')
		if (!skip_whitespace(map, line, &length, &length_width))
			return (false);
	while (line[length])
	{
		if (line[length] == '0' || line[length] == '1' || line[length] == 'N'
			|| line[length] == 'S' || line[length] == 'E' || line[length]
			== 'W')
			start_map(map, &length, &length_width, &map_started);
		else if ((line[length] == '\n' || line[length] == ' '
				|| line[length] == '\t') && map_started)
			process_other_chars(map, line, &length, &length_width);
		else
			return (false);
	}
	map->max_width = length_width + 1;
	return (true);
}

bool	is_valid_line_inside(char *line, t_map *map)
{
	int	length;
	int	length_width;

	length = 0;
	length_width = 0;
	while (line[length])
	{
		if ((line[length] == '0' || line[length] == '1' || line[length] == 'N'
			|| line[length] == 'S' || line[length] == 'E' || line[length]
			== 'W' || line[length] == '\n' || line[length] == ' '))
			{
			length++;
			length_width++;
		}
		else if (line[length] == '\t')
		{
			length++;
			length_width += TAB_SPACES;
		}
		else
			return (false);
	}
	if (map->max_width < (length_width + 1))
		map->max_width = length_width + 1;
	return (true);
}
