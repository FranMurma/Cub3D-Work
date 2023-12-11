/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_maps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:59:15 by frmurcia          #+#    #+#             */
/*   Updated: 2023/12/11 17:44:58 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "map.h"

	// Funciones de libft y el write error con mensaje
void	ft_write_error(char *message)
{
    write(2, "Error\n", 6);
    write(2, message, ft_strlen(message));
    write(2, "\n", 1);
    exit(-1);
}

char *ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t i;

	i = 0;
	if (dest == NULL || src == NULL)
	   	return NULL;
	while (i < n && src[i])
	{
        dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
   	return (dest);
}

int		ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return(i);
}

char	*ft_strdup(const char *s1)
{
	char	*str_nueva;
	int		cont;
	int		len;

	len = 0;
	while (s1[len])
		len++;
	str_nueva = malloc(sizeof(char) * (len + 1));
	if (!str_nueva)
		return (NULL);
	cont = 0;
	while (s1[cont])
	{
		str_nueva[cont] = s1[cont];
		cont++;
	}
	str_nueva[cont] = '\0';
	return (str_nueva);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		cont_s1;
	int		cont_s2;
	char	*s3;

	s3 = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s3)
		return (NULL);
	cont_s1 = 0;
	cont_s2 = 0;
	while (s1[cont_s1])
	{
		s3[cont_s1] = s1[cont_s1];
		cont_s1++;
	}
	while (s2[cont_s2])
	{
		s3[cont_s1 + cont_s2] = s2[cont_s2];
		cont_s2++;
	}
	s3[cont_s1 + cont_s2] = '\0';
	return (s3);
}
