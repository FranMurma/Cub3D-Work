/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 12:57:49 by frmurcia          #+#    #+#             */
/*   Updated: 2023/12/24 17:56:01 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture.h"

void ft_free_paths(char **paths)
{
	int i;

	i = 0;
	while (paths[i])
	{
		free(paths[i]);
		i++;
	}
	free(paths);
}

void process_texture_raw(t_textures *texture)
{
	int	j;
	int i;
	char *info;
	char **paths;
	char **aux;
	char *textinfo;

	i = 0;
	aux = ft_split(texture->texture_raw, '\n');
	while (aux[i])
	{
		j = 0;
		textinfo = ft_strdup(aux[i]);
		paths = ft_split(textinfo, ' ');
		if (paths[2] && paths[2] != NULL)
			ft_write_error("Error\nBad data in the paths\n");
		info = ft_strtrim(paths[1], " ");
		free(textinfo);
		get_texture_type(texture, info, paths);
		free(info);
		ft_free_paths(paths);
		i++;
	}
	i = 0;
	while (aux[i])
	{
		free(aux[i]);
		i++;
	}
	free(aux);

	if (i > 6)
		ft_write_error("Error\nBad paths number\n");
	if (!are_texture_paths_filled(texture->paths))
		ft_write_error("Error\ntexture paths are not filled\n");
}

void free_texture_paths(char **paths)
{
	int j;

	j = 0;
	while (paths[j] && paths[j] != NULL)
	{
		free(paths[j]);
		j++;
	}
	free(paths);
	if (j > 2)
		ft_write_error("Error\nBad data in the paths\n");
}

bool only_map_chars(char *line)
{
	bool found_map;
	int i;
	size_t length;

	found_map = false;
	i = 0;
	length = ft_strlen(line);
	while (i < ft_strlen(line))
	{
		if (line[i] == '0' || line[i] == '1' || line[i] == 'N' || line[i] == 'S' || line[i] == 'E' || line[i] == 'W')
		{
			found_map = true;
			i++;
		}
		else if (line[i] == ' ' || line[i] == '\t' || line[i] == '\n')
			i++;
		else
			return (false);
	}
	return (found_map);
}

void process_textures(t_textures *texture, char *line)
{
	char *tmp;

	if (!texture->texture_raw)
	{
		texture->texture_raw = ft_strdup(line);
	}
	else if (texture->texture_raw)
	{
		tmp = ft_strjoin(texture->texture_raw, line);
		free(texture->texture_raw);
		texture->texture_raw = ft_strdup(tmp);
		free(tmp);
	}
}

void ft_read_textures(char **argv, t_textures *texture)
{
	int fd;
	char *line;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_write_error("Error opening map file\n");
	line = get_next_line(fd);
	if (!line)
		ft_write_error("Error reading lines of the map\n");
	while (line)
	{
		if (!is_empty_or_spaces(line) && !only_map_chars(line))
			process_textures(texture, line);
		free(line);
		line = get_next_line(fd);
		if (!line)
		{
			process_texture_raw(texture);
			//			free(texture->texture_raw);
			break;
		}
	}
	// close(fd);
}
