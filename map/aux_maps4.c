/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_maps4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:07:20 by frmurcia          #+#    #+#             */
/*   Updated: 2023/12/19 12:50:26 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "map.h"
/*
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned long	d;
	unsigned long	s;

	d = 0;
	s = 0;
	while (src[s] != '\0')
	{
		s++;
	}
	if (dstsize != 0)
	{
		while (d < dstsize - 1 && src[d] != '\0')
		{
			dst[d] = src[d];
			d++;
		}
		dst[d] = '\0';
	}
	return (s);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	str_l;
	size_t	l;

	str_l = ft_strlen(s);
	if (str_l - start >= len)
		l = len + 1;
	else
		l = str_l - start + 1;
	if (len == 0 || str_l == 0 || start > str_l)
	{
		str = malloc(sizeof(char));
		if (str == NULL)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	str = malloc(sizeof(char) * l);
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, (s + start), l);
	return (str);
}*/

char	*ft_strndup(char *s1, size_t len)
{
	char	*new_str;
	size_t	i;

	i = 0;
	new_str = malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (NULL);
	while (s1[i] && i < len)
	{
		new_str[i] = s1[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
