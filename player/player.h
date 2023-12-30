/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:00:37 by frmurcia          #+#    #+#             */
/*   Updated: 2023/12/30 12:23:57 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "../map/map.h"

typedef struct player
{
	int		px;
	int		py;
	int		dirx;
	int		diry;
	double	plane_x;
	double	plane_y;
}	t_player;

// player.c
void	init_player(t_player *player);
void	get_player(t_map *map, t_player *player);
void	get_player_direction(t_map *map, t_player *player, int y, int x);
bool	is_space_around(t_map *map, int x, int y);
bool	check_map(t_map *map);

#endif
