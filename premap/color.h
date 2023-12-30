/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:23:38 by frmurcia          #+#    #+#             */
/*   Updated: 2023/12/29 17:13:30 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "../map/map.h"
# include "texture.h"

typedef struct s_color
{
	int				r;
	int				g;
	int				b;
	unsigned int	hex;
}	t_color;

typedef struct s_map_color
{
	t_color		*floor_color;
	t_color		*ceil_color;
}	t_map_color;

//color.c
t_map_color		init_color(t_map_color *color);
void			get_color_floor(t_map_color *color, t_textures *texture);
void			get_color_ceil(t_map_color *color, t_textures *texture);
void			ft_check_color(t_map_color *color);
unsigned int	create_hex_color(int r, int g, int b);
void			free_colors(char **char_numbers);

//aux_color.c
bool			ft_isdigit(int c);
bool			is_numeric(const char *str);
int				ft_atoi(const char *str);
bool			is_color(int color);
void			ft_check_color(t_map_color *color);

// free_colors.c
void			ft_free_colors(t_map_color *color);
void			free_colors(char **col);

#endif
