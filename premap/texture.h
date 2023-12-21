/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 12:58:57 by frmurcia          #+#    #+#             */
/*   Updated: 2023/12/21 19:50:07 by frmurcia         ###   ########.fr       */
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

/*
struct s_color;
typedef struct s_color t_color;

struct s_map_color;
typedef struct s_map_color t_map_color;
*/

typedef enum {
	NO,
	SO,
	WE,
	EA,
	F,
	C,
	UNKNOWN
} t_texture_type;

typedef struct s_cardinal
{
	char			*north;
	char			*south;
	char			*east;
	char			*west;
	char			*floor;
	char			*ceil;
}	t_cardinal;

typedef struct s_textures {
    t_texture_type	type;
    char			*path;
	char    		*texture_raw;
	char			**info;
	t_cardinal		*paths;
} t_textures;

//init_textures.c
bool			are_texture_paths_filled(t_cardinal *paths);
t_textures		*init_textures(void);
void			close_texture(t_textures *texture);
void			close_struct_texture(t_textures *texture);
void			close_process_texture (t_textures *texture);
 void free_texture_paths(t_cardinal *paths);

// read_textures
void    		ft_read_textures(char **argv, t_textures *texture);
void   		 	process_textures(t_textures *texture, char *line);
bool		    only_map_chars(char *line);
void		    process_texture_raw (t_textures *texture);
t_texture_type  get_texture_type(t_textures *texture, int index);
void free_textures(t_textures *texture);

# endif
