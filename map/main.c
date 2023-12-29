/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:59:11 by frmurcia          #+#    #+#             */
/*   Updated: 2023/12/29 12:18:21 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "../premap/texture.h"
#include "../premap/color.h"

int	main(int argc, char **argv)
{
	ft_check_parameters(argc, argv);
	ft_start_map(argv);
	return (0);
}
