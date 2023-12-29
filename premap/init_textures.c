/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:59:29 by frmurcia          #+#    #+#             */
/*   Updated: 2023/12/29 13:12:20 by frmurcia         ###   ########.fr       */
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
	if (!texture->paths)
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
		if (texture->path != NULL)
			free(texture->path);
	}
}

void	free_cardinals(t_cardinal *paths)
{
	if (paths)
	{
		if (paths->north)
			free(paths->north);
		if (paths->south)
			free(paths->south);
		if (paths->ceil)
			free(paths->ceil);
		if (paths->floor)
			free(paths->floor);
		if (paths->west)
			free(paths->west);
		if (paths->east)
			free(paths->east);
	}
}
