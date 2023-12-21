/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:59:29 by frmurcia          #+#    #+#             */
/*   Updated: 2023/12/20 19:19:26 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "texture.h"
# include "../map/map.h"

bool	are_texture_paths_filled(t_cardinal *paths)
{
	return (paths->north && paths->south && paths->east && paths->west &&
		paths->floor && paths->ceil);
}

t_textures	*init_textures(void)
{
	t_textures	*texture;
	texture = malloc(sizeof(t_textures));
	if (!texture)
	{
		ft_write("Error\n Allocating memory for map\n");
		return (NULL);
	}
	// Inicializar la estructura con valores predeterminados o nulos
	texture->type = UNKNOWN;
	texture->path = NULL;
	texture->texture_raw = NULL;
	texture->info = NULL;

// Inicializar la estructura t_cardinal dentro de t_textures
	texture->paths = (t_cardinal *)malloc(sizeof(t_cardinal));
	if (texture->paths == NULL)
	{
// Manejo de error: No se pudo asignar memoria
	exit(EXIT_FAILURE);
	}

// Inicializar los campos de t_cardinal
	texture->paths->north = NULL;
	texture->paths->south = NULL;
	texture->paths->east = NULL;
	texture->paths->west = NULL;
	texture->paths->floor = NULL;
	texture->paths->ceil = NULL;
	return (texture);
}

void	close_texture(t_textures *texture)
{
	if (!texture)
		return;
        // Liberar la memoria asignada para cada path en t_cardinal
	free(texture->paths->north);
	free(texture->paths->south);
	free(texture->paths->east);
	free(texture->paths->west);
	free(texture->paths->floor);
	free(texture->paths->ceil);
        // Liberar la memoria asignada para la estructura t_cardinal
	free(texture->paths);
	texture->paths = NULL;
    // Finalmente, liberar la memoria asignada para la estructura t_textures
	free(texture);
}

void	close_struct_texture(t_textures *texture)
{
	free (texture);
	free (texture->paths);
}

void	close_process_texture (t_textures *texture)
{
	int	i;

	i = 0;
	if (texture->info)
	{
		while (i < 6 && texture->info[i] != NULL)
		{
			free (texture->info[i]);
			i++;
		}
		free (texture->info);
	}
}
	
/*
	free (texture->paths->north);
	free (texture->paths->south);
	free (texture->paths->east);
	free (texture->paths->west);
	free (texture->paths->floor);
	free (texture->paths->ceil);
	free (texture->texture_raw);
//	free (texture->paths);// Ya liberado
//	free(texture);
}*/

void free_texture_paths(t_cardinal *paths) {
    free(paths->north);
    free(paths->south);
    free(paths->east);
    free(paths->west);
    free(paths->floor);
    free(paths->ceil);
}
