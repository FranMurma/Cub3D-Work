/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_textures2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:26:09 by frmurcia          #+#    #+#             */
/*   Updated: 2023/12/22 19:43:14 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture.h"

void	get_texture_type(t_textures *texture, int index, char *info,
		char **paths)
{
	if (ft_strcmp("NO", paths[0]) && texture->paths->north == NULL)
		texture->paths->north = ft_strdup(info);
	else if (ft_strcmp("SO", paths[0]) && texture->paths->south == NULL)
		texture->paths->south = ft_strdup(info);
	else if (ft_strcmp("WE", paths[0]) && texture->paths->west == NULL)
		texture->paths->west = ft_strdup(info);
	else if (ft_strcmp("EA", paths[0]) && texture->paths->east == NULL)
		texture->paths->east = ft_strdup(info);
	else if (ft_strcmp("F", paths[0]) && texture->paths->floor == NULL)
		texture->paths->floor = ft_strdup(info);
	else if (ft_strcmp("C", paths[0]) && texture->paths->ceil == NULL)
		texture->paths->ceil = ft_strdup(info);
	else
		ft_write_error("Error\nBad data in the paths\n");
}
