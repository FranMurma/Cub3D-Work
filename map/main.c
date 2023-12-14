/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:59:11 by frmurcia          #+#    #+#             */
/*   Updated: 2023/12/13 20:04:53 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "map.h"
# include "../premap/texture.h"
# include "../premap/color.h"

int main(int argc, char** argv) {

    ft_check_parameters(argc, argv);
	ft_start_map(argv);

    // Diagnóstico antes de la impresión
//    printf("Max Height: %d, Max Width: %d\n", map->max_height, map->max_width);
//    printf("Last character in map_raw: '%c'\n", map->map_raw[ft_strlen(map->map_raw) - 1]);
    return 0;
}
