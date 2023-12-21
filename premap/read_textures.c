/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 12:57:49 by frmurcia          #+#    #+#             */
/*   Updated: 2023/12/21 19:50:10 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "texture.h"

// *texture->info[] es la particion en lineas de texture_raw
void process_texture_raw(t_textures *texture)
{
   	int		i;
	char	*info;
	char	**paths;
	char 	**anotherReference;
   
	i = 0;
	texture->info = ft_split(texture->texture_raw, '\n');//texture->info[] es cada linea
	while (i < 6 && texture->info[i])
    {
		info = NULL;
		printf("Dirección de 'texture_info': %p   Y contiene: %s\n", (void *)texture->info[i], texture->info[i]);
		texture->type = get_texture_type(texture, i);
		printf("222. 'texture_info': %p   Y contiene: %s\n", (void *)texture->info[i], texture->info[i]);
		paths = ft_split(texture->info[i], ' ');
		free (texture->info[i]);
		info = ft_strtrim(paths[1], " ");
		free (paths[1]);
		free (paths[0]);
//		printf("Dirección de 'info': %p\n", (void *)info);
//		printf("Dirección de 'texture->type': %p\n", (void *)texture->type);
		if (texture->type == NO)
		{
			texture->paths->north = ft_strdup(info);
		}
		else if (texture->type == SO)
		{
			texture->paths->south = ft_strdup(info);
		}
		else if (texture->type == WE)
		{
			texture->paths->west = ft_strdup(info);
		}
		else if (texture->type == EA)
		{
			texture->paths->east = ft_strdup(info);
		}
		else if (texture->type == F)
		{
			texture->paths->floor = ft_strdup(info);
		}
		else if (texture->type == C)
		{
			texture->paths->ceil = ft_strdup(info);
		}
		free (info);
        i++;
    }
	i = 0;
//	free (info);
//	free (paths);
/*	while (anotherReference[i])
	{
		printf("Direccion another reference = %p\n", (void *)paths[i]);
		free (anotherReference[i]);
		i++;
	}*/
/*	while (texture->info[i])
	{
		printf("2. Dirección de 'texture_info': %p\n", (void *)texture->info[i]);
//		free(texture->info[i]);
		i++;
	}*/
	if (!are_texture_paths_filled (texture->paths))
		ft_write_error("Error\ntexture paths are not filled\n");
	printf("North path = %s\n", texture->paths->north);
	printf("South path = %s\n", texture->paths->south);
	printf("West path = %s\n", texture->paths->west);
	printf("East path = %s\n", texture->paths->east);
	printf("Floor path = %s\n", texture->paths->floor);
	printf("Ceil path = %s\n", texture->paths->ceil);
	i = 0;
/*	while (paths[i])
	{
		free(paths[i]);
		i++;
	}*/
//	free_textures(texture);
//	close_process_texture(texture);
	exit (-1);
}

bool	only_map_chars(char *line)
{
	bool	found_map;
	size_t	i;
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
//		printf("Dirección de 'texture_raw' en !texture: %p\n", (void *)texture->texture_raw);
//		printf("%s\n", texture->texture_raw);
	}
	else if (texture->texture_raw)
	{
		tmp = ft_strjoin(texture->texture_raw, line);
//		printf("Dirección de 'tmp': %p\n", (void *)tmp);
		free (texture->texture_raw);
		texture->texture_raw = ft_strdup(tmp);
		free (tmp);
//		printf("%s\n", texture->texture_raw);
//		free (tmp);
	}
}

void	ft_read_textures(char **argv, t_textures *texture)
{
	int		fd;
	char	*line;

	printf("EBTRO\n");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		close_struct_texture(texture);
		ft_write_error("Error opening map file\n");
	}
	line = get_next_line(fd);
	if (!line)
	{
		close_struct_texture(texture);
		ft_write_error("Error reading lines of the map\n");
	}
//	texture->texture_raw = NULL;
	while (line)
	{
		if (!is_empty_or_spaces(line) && !only_map_chars(line))
			process_textures(texture, line);
		free (line);
		line = get_next_line(fd);
		if (!line)
		{
			process_texture_raw(texture);
			free(texture->texture_raw);
			break ;
		}
	}
}
