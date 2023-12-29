/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 13:56:40 by frmurcia          #+#    #+#             */
/*   Updated: 2023/12/29 15:12:20 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

void	ft_free_colors(t_map_color *color)
{
	if (color->floor_color)
		free(color->floor_color);
	if (color->ceil_color)
		free(color->ceil_color);
}

void	free_colors(char **col)
{
	int	i;

	i = 0;
	while (col[i])
	{
		free(col[i]);
		i++;
	}
	free(col);
}
