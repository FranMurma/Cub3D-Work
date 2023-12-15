/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:19:17 by frmurcia          #+#    #+#             */
/*   Updated: 2023/12/15 18:20:46 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "map.h"

void	free_init_map(t_map *map)
{
    free(map->map_raw);
    free(map);

}