/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:59:29 by frmurcia          #+#    #+#             */
/*   Updated: 2023/12/22 20:00:11 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture.h"
#include "../map/map.h"

bool	are_texture_paths_filled(t_cardinal *paths)
{
	return (paths->north && paths->south && paths->east && paths->west
		&& paths->floor && paths->ceil);
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
	texture->type = UNKNOWN;
	texture->path = NULL;
	texture->texture_raw = NULL;
	texture->info = NULL;
	texture->paths = (t_cardinal *)malloc(sizeof(t_cardinal));
	if (texture->paths == NULL)
		ft_write_error("Error\n Can't initilize paths\n");
	texture->paths->north = NULL;
	texture->paths->south = NULL;
	texture->paths->east = NULL;
	texture->paths->west = NULL;
	texture->paths->floor = NULL;
	texture->paths->ceil = NULL;
	return (texture);
}
