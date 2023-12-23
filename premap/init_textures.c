/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:59:29 by frmurcia          #+#    #+#             */
/*   Updated: 2023/12/23 12:37:10 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../map/map.h"

bool	are_texture_paths_filled(t_cardinal *paths)
{
	return (paths->north && paths->south && paths->east && paths->west
		&& paths->floor && paths->ceil);
}

t_textures	init_textures(t_textures *texture)
{
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
	return (*texture);
}

void	free_textures(t_textures *texture)
{
	int	i;

	i = 0;
	if (texture)
	{
		if (texture->path)
			free (texture->path);
		if (texture->texture_raw)
			free (texture->texture_raw);
		if (texture->info)
		{
			while (texture->info[i])
			{
				free (texture->info[i]);
				i++;
			}
			free (texture->info);
		}
		free_cardinals(texture->paths);
	}
}

void	free_cardinals(t_cardinal *paths)
{
	if (paths)
	{
		if (paths->north)
			free (paths->north);
	}
}
