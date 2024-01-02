/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:59:29 by frmurcia          #+#    #+#             */
/*   Updated: 2024/01/02 18:20:28 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	are_texture_paths_filled(t_textures *text)
{
	printf("N: %s\n", text->paths->north);
	printf("S: %s\n", text->paths->south);
	printf("E: %s\n", text->paths->east);
	printf("W: %s\n", text->paths->west);
	printf("C: %s\n", text->paths->ceil);
	printf("F: %s\n", text->paths->floor);	
	return (text->paths->north && text->paths->south && text->paths->east
		&& text->paths->west && text->paths->floor && text->paths->ceil);
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
