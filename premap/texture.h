/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 12:58:57 by frmurcia          #+#    #+#             */
/*   Updated: 2023/12/29 17:17:52 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

# include "../map/map.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>

typedef enum s_texture_type
{
	NO,
	SO,
	WE,
	EA,
	F,
	C,
	UNKNOWN
}	t_texture_type;

typedef struct s_cardinal
{
	char		*north;
	char		*south;
	char		*east;
	char		*west;
	char		*floor;
	char		*ceil;
}	t_cardinal;

typedef struct s_textures
{
	t_texture_type	type;
	char			*path;
	char			*texture_raw;
	char			**info;
	t_cardinal		*paths;
	bool			path_found;
}	t_textures;

//init_textures.c
bool			are_texture_paths_filled(t_cardinal *paths);
t_textures		init_textures(t_textures *texture);
void			free_textures(t_textures *texture);
void			free_cardinals(t_cardinal *paths);

// read_textures.c
void			get_texture_type(t_textures *texture, char *info, char **paths);
void			ft_free_paths(char **paths);
void			process_texture_raw(t_textures *texture);
bool			only_map_chars(char *line);
void			process_textures(t_textures *texture, char *line);

#endif
