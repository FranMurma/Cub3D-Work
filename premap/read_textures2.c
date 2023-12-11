/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_textures2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:26:09 by frmurcia          #+#    #+#             */
/*   Updated: 2023/12/11 19:36:36 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "texture.h"

t_texture_type	process_texture_raw (t_textures *texture)
{
	int	i;

	i = 0;
	char	**parts;

	parts = ft_split(texture->texture_raw, ' ');
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
	return (texture->type);
}

t_textures	get_textures(t_textures *texture)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		type = 
	}
}
