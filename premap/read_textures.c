/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 12:57:49 by frmurcia          #+#    #+#             */
/*   Updated: 2023/12/11 19:26:14 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "texture.h"
# include "../map/map.h"
/*
t_texture_types	get_texture_type(char *texture)
{
	char				**parse;
	t_texture_type		type;

	type = 0;
	parse = ft_split(texture, ' ');
	if (ft_strcmp(parse[0], "NO", true))
		type = NO;
	if (ft_strcmp(parse[0], "SO", true))
		type = SO;
	if (ft_strcmp(parse[0], "WE", true))
		type = WE;
	if (ft_strcmp(parse[0], "EA", true))
		type = EA;
	if (ft_strcmp(parse[0], "F", true))
		type = F;
	if (ft_strcmp(parse[0], "C", true))
		type = C;
//	ft_free_matrix(parse);
	return (type);
}*/

void	process_texture_raw (t_textures *texture)
{
	int	i;

	i = 0;
	char	**parts;

	parts = ft_split(texture->texture_raw, ' ');
	while (parts[i])
	{
		if (ft_strcmp(parts[i], "NO"))
			texture->type = NO;
		else if (ft_strcmp(parts[i], "SO"))
			texture->type = SO;
		else if (ft_strcmp(parts[i], "WE"))
			texture->type = WE;
		else if (ft_strcmp(parts[i], "EA"))
			texture->type = EA;
		else if (ft_strcmp(parts[i], "F"))
			texture->type = F;
		else if (ft_strcmp(parts[i], "C"))
			texture->type = C;
		i++;
	}
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
	if (!texture->texture_raw && !only_map_chars(line))
		texture->texture_raw = ft_strdup(line);
	else if (texture->texture_raw && !only_map_chars(line))
		texture->texture_raw = ft_strjoin(texture->texture_raw, line);
	free(line);
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
	texture->texture_raw = NULL;
	while (line)
	{
		if (!is_empty_or_spaces(line))
			process_textures(texture, line);
		line = get_next_line(fd);
		if (!line)
			break ;
	}
	free(line);
	texture->info = ft_split(texture->texture_raw, '\n');
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        ft_write_error("Usage: ./test_textures cub_file.cub\n");
        return (1);
    }

    t_textures texture;
    ft_read_textures(argv, &texture);
    // Imprimir o realizar otras operaciones según sea necesario
    printf("Texture Raw:\n%s\n", texture.texture_raw);
	printf("Longitud de char* textura: %i\n", ft_strlen(texture.texture_raw));


    return (0);
}
