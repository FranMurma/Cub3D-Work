/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 12:57:49 by frmurcia          #+#    #+#             */
/*   Updated: 2023/12/23 12:40:51 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture.h"

void	process_texture_raw(t_textures *texture)
{
	int		i;
	char	*info;
	char	**paths;
	char	*textinfo;

	i = 0;
	texture->info = ft_split(texture->texture_raw, '\n');
	while (texture->info[i] != NULL)
	{
		textinfo = ft_strdup(texture->info[i]);
		paths = ft_split(textinfo, ' ');
		free (textinfo);
		info = ft_strtrim(paths[1], " ");
		get_texture_type(texture, info, paths);
		free_texture_paths(paths);
		free (info);
		i++;
	}
	if (i > 6)
	{
		ft_write_error("Error\nBad paths number\n");
	}
	if (!are_texture_paths_filled (texture->paths))
		ft_write_error("Error\ntexture paths are not filled\n");
}

void	free_texture_paths(char **paths)
{
	int	j;

	j = 0;
	while (paths[j] && paths[j] != NULL)
	{
		free (paths[j]);
		j++;
	}
	free (paths);
	if (j > 2)
		ft_write_error("Error\nBad data in the paths\n");
}

bool	only_map_chars(char *line)
{
	bool	found_map;
	int		i;
	size_t	length;

	found_map = false;
	i = 0;
	length = ft_strlen(line);
	while (i < ft_strlen(line))
	{
		if (line[i] == '0' || line[i] == '1' || line[i] == 'N'
			|| line[i] == 'S' || line[i] == 'E' || line[i] == 'W')
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

void	process_textures(t_textures *texture, char *line)
{
	char	*tmp;

	if (!texture->texture_raw)
	{
		texture->texture_raw = ft_strdup(line);
	}
	else if (texture->texture_raw)
	{
		tmp = ft_strjoin(texture->texture_raw, line);
		free (texture->texture_raw);
		texture->texture_raw = ft_strdup(tmp);
		free (tmp);
	}
}

void	ft_read_textures(char **argv, t_textures *texture)
{
	int		fd;
	char	*line;

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
		free (line);
		line = get_next_line(fd);
		if (!line)
		{
			process_texture_raw(texture);
//			free(texture->texture_raw);
			break ;
		}
	}
}
