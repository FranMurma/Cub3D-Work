/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_maps2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:45:30 by frmurcia          #+#    #+#             */
/*   Updated: 2023/12/19 18:24:51 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# include "map.h"

void	ft_write(char *message)
{
    write(2, message, ft_strlen(message));
    write(2, "\n", 1);
    return ;
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		start;
	size_t		end;
	char		*s2;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) -1;
	while ((ft_strchr(set, s1[start])) && s1[start])
		start++;
	while ((ft_strchr(set, s1[end])) && end >= 0)
		end--;
	s2 = ft_substr_m(s1, start, (end - start + 1));
	if (!s2)
		return (NULL);
	return (s2);
}

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

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*s;
	unsigned char	*d;

	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	if (!dst && !src)
		return (NULL);
	if (dst > src)
	{
		while (len > 0)
		{
			d[len - 1] = s[len - 1];
			len--;
		}
		return (dst);
	}
	else
		return (ft_memcpy(dst, src, len));
}
