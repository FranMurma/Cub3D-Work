/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:27:50 by frmurcia          #+#    #+#             */
/*   Updated: 2023/12/19 18:32:09 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

bool	is_empty_or_spaces(char *line)
{
	while (*line)
	{
		if (*line != ' ' && *line != '\t' && *line != '\n'
			&& *line != '\r' && *line != '\f' && *line != '\v')
			return (false);
		line++;
	}
	return (true);
}

/*****
 * Aqui cojo el max_width
 ***** */
void	append_line_to_map_raw(t_map *map, char *line, int *line_number)
{
	char	*tmp;
	char	*dup;
	size_t	len;

//	printf("Entro en append line\n");
	len = ft_strlen(line);
//	printf("len - 1 = %d, posicion del len: %zu \n", line[len - 1], len);
	while ((len > 0) && (line[len - 2] == ' ' || line[len - 2] == '\t'))
	{
//		printf("Entro en bajar el len\n");
		len--;
	}
	if (len > map->max_width)
		map->max_width = len + 1;
	tmp = ft_strndup(line, len);
	printf("Dirección de memoria de 'tmp': %p\n", (void *)tmp);
	tmp[len - 1] = '\n';

	if (!map->map_raw)
	{
		map->found_map = true;
		map->map_raw = tmp;
		map->map_start = *line_number;
//		free (tmp); Da un error al liberar sin estar allocado
	}
	else if (map->map_raw)
	{
		dup = ft_strjoin(map->map_raw, tmp);
		free (tmp);
		free(map->map_raw);
		map->map_raw = dup;
//		free (dup); Da un error al liberar sin estar allocado
	}
}

void	process_map_line(t_map *map, char *line, int *line_number)
{

	if (!map->map_raw)
	{
//		if (!is_empty_or_spaces(line) && !is_valid_map_line(line, map))//anadido
//			process_textures(texture, line);//anadido
		if (is_valid_map_line(line, map) && !(is_empty_or_spaces(line)))
			append_line_to_map_raw(map, line, line_number);
		else
			map->found_map = false;
	}
	else if (map->map_raw)
	{
		if (is_valid_line_inside(line, map) && !(is_empty_or_spaces(line)))
		{
			append_line_to_map_raw(map, line, line_number);
//			printf("Dirección de memoria de 'line en join': %p\n", (void *)map->map_raw);
		}
		else
		{
			free (line);
			free (map->map_raw);
//			free_init_map(map);
			ft_write_error("Error. Bad map!\n");
		}
	}
	if (map->map_raw)
		(*line_number)++;
}

void	set_measures_and_close(t_map *map, int line_number, int fd)
{
	printf("XXXXXXXXXXXXX\n");
	if (close(fd) == -1)
		ft_write_error("Error\nWhile closing file descriptor\n");
	if (map->found_map)
	{
		map->map_end = line_number;
		map->max_height = map->map_end - map->map_start + 2;
//		printf("Max height = %d\n", map->max_height);
//		printf("Max width = %d\n", map->max_width);
//		printf("map_raw = %s\n", map->map_raw);
//		free(map->map_raw);
//		free_init_map(map);
	}
	else
	{
		write(1, "2\n", 2);
//		free_init_map(map);
		ft_write_error("Error. Bad map, I can't found signs for map!\n");
	}
}

void	ft_read_map(char **argv, t_map *map)
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
		process_map_line(map, line, &line_number);
		free (line);
		line = get_next_line(fd);
//		printf("Dirección de memoria de 'line': %p\n", (void *)line);
		if (!line)
		{
			map->map_end = line_number;
			break ;
		}
	}
	free(line);
	write(1, "yyyyyyyyyyyy\n", 13);
	set_measures_and_close(map, line_number, fd);
}

void	print_filled_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
//	printf("Llego a print map\n");
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
