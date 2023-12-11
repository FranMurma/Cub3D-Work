/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:59:11 by frmurcia          #+#    #+#             */
/*   Updated: 2023/12/07 18:26:14 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "map.h"

int main(int argc, char** argv) {
    (void)argv;
    t_map *map = init_map();

    if (argc != 2)
        ft_write_error("Usage: ./your_program map.cub");

    ft_read_map(argv, map);
    create_2d(map);

    // Diagnóstico antes de la impresión
//    printf("Max Height: %d, Max Width: %d\n", map->max_height, map->max_width);
//    printf("Last character in map_raw: '%c'\n", map->map_raw[ft_strlen(map->map_raw) - 1]);
	printf("------------------------");
    print_filled_map(map);
	printf("------------------------");
    // Diagnóstico después de la impresión

    copy_line_to_map(map);
    print_filled_map(map);

    return 0;
}
