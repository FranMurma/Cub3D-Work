/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:55:13 by frmurcia          #+#    #+#             */
/*   Updated: 2023/12/19 11:36:50 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

bool	skip_whitespace(t_map *map, char *line, int *length)
{
	*length = 0;
	while (line[*length] == ' ' || line[*length] == '\t')
	{
		if (line[*length] == '\t')
		{
			(*length)++;
		}
		else if (line[*length] == ' ')
		{
			(*length)++;
		}
		if (line[*length] == '\0')
			return (false);
	}
	return (true);
}

void	start_map(t_map *map, int *length, bool *map_started)
{
	*map_started = true;
	(*length)++;
}

void	process_other_chars(t_map *map, char *line, int *length)
{
	if (line[*length] == '\n' || line[*length] == ' ')
	{
		(*length)++;
	}
	else if (line[*length] == '\t')
	{
		(*length)++;
	}
}

bool	is_valid_map_line(char *line, t_map *map)
{
	int		length;
	bool	map_started;

	length = 0;
	map_started = false;
	while (line[length] == ' ' || line[length] == '\t')
		if (!skip_whitespace(map, line, &length))
			return (false);
	while (line[length])
	{
		if (line[length] == '0' || line[length] == '1' || line[length] == 'N'
			|| line[length] == 'S' || line[length] == 'E' || line[length]
			== 'W')
			start_map(map, &length, &map_started);
		else if ((line[length] == '\n' || line[length] == ' '
				|| line[length] == '\t') && map_started)
			process_other_chars(map, line, &length);
		else
			return (false);
	}
	return (true);
}

bool	is_valid_line_inside(char *line, t_map *map)
{
	int	length;

	length = 0;
	while (line[length])
	{
		if ((line[length] == '0' || line[length] == '1' || line[length] == 'N'
			|| line[length] == 'S' || line[length] == 'E' || line[length]
			== 'W' || line[length] == '\n' || line[length] == ' '))
			{
			length++;
		}
		else if (line[length] == '\t')
		{
			length++;
		}
		else
			return (false);
	}
	return (true);
}
