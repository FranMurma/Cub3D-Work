/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_textures2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:26:09 by frmurcia          #+#    #+#             */
/*   Updated: 2023/12/19 19:45:50 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "texture.h"

t_texture_type	get_texture_type(t_textures *texture, int index)
{
	texture->info[index] = ft_strtrim(texture->info[index], " ");

	if (ft_strcmp("NO", texture->info[index]))
		return (NO);
	else if (ft_strcmp("SO", texture->info[index]))
		return (SO);
	else if (ft_strcmp("WE", texture->info[index]))
		return (WE);
	else if (ft_strcmp("EA", texture->info[index]))
		return (EA);
	else if (ft_strcmp("F", texture->info[index]))
		return (F);
	else if (ft_strcmp("C", texture->info[index]))
		return (C);
	else
		return (UNKNOWN);
}

void free_textures(t_textures *texture)
{
    if (texture)
    {
        // Liberar texture->texture_raw si es necesario
        if (texture->texture_raw)
            free(texture->texture_raw);

        // Liberar las rutas en texture->paths si son necesarias
        if (texture->paths)
        {
            if (texture->paths->north)
                free(texture->paths->north);
            if (texture->paths->south)
                free(texture->paths->south);
            if (texture->paths->east)
                free(texture->paths->east);
            if (texture->paths->west)
                free(texture->paths->west);
            if (texture->paths->floor)
                free(texture->paths->floor);
            if (texture->paths->ceil)
                free(texture->paths->ceil);

            // Liberar la estructura texture->paths
            free(texture->paths);
        }

        // Liberar la estructura t_textures
        free(texture);
    }
}
