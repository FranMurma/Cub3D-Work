/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 12:58:57 by frmurcia          #+#    #+#             */
/*   Updated: 2023/12/11 19:39:49 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include "../map/map.h"

typedef enum {
	NO,
	SO,
	WE,
	EA,
	F,
	C,
	UNKNOWN
} t_texture_type;

typedef struct s_textures {
    t_texture_type	type;
    char			*path;
	char    		*texture_raw;
	char			**info;
} t_textures;

typedef struct s_texture
{
//	t_image			north;
//	t_image			south;
//	t_image			east;
//	t_image			west;
	unsigned int	floor;
	unsigned int	ceil;
}	t_texture;


// read_textures
void    ft_read_textures(char **argv, t_textures *texture);
void    process_textures(t_textures *texture, char *line);

# endif
