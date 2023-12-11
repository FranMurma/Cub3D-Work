/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_maps2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:45:30 by frmurcia          #+#    #+#             */
/*   Updated: 2023/12/11 19:11:20 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# include "map.h"

bool	ft_strcmp(char *s1, char *s2)
{
	size_t			cont;

	cont = 0;
	if (s1 == NULL || s2 == NULL)
		return (false);

	while (s1[cont] != '\0')
	{
		if (s1[cont] != s2[cont])
			return (false);
		cont++;
	}
	return (true);
}

bool	ft_check_comas(char *input)
{
	int	c;
	int	coma;

	c = 0;
	coma = 0;
	while (input[c])
	{
		if (input[c] == ',')
			coma++;
		c++;
	}
	if (coma != 2)
		return (false);
	return (true);
}
