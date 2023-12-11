/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:26:04 by frmurcia          #+#    #+#             */
/*   Updated: 2023/12/11 17:45:18 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "map.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*str_nueva;
	size_t	len_s;
	size_t	cont;

	len_s = 0;
	while (s[len_s])
		len_s++;
	if (len_s < start)
		len = 0;
	else if (len >= (len_s - start))
		len = len_s - start;
	str_nueva = malloc(sizeof(char) * (len + 1));
	if (!str_nueva)
		return (NULL);
	cont = 0;
	while (cont < len)
	{
		str_nueva[cont] = s[start];
		cont++;
		start++;
	}
	str_nueva[cont] = '\0';
	return (str_nueva);
}

void	*ft_free(char **str_n)
{
	int	cont;

	cont = 0;
	while (str_n[cont])
	{
		free (str_n[cont]);
		cont++;
	}
	free (str_n);
	return (NULL);
}

int	ft_words(char *s, char c)
{
	int	cont_s;
	int	words;

	cont_s = 0;
	words = 0;
	while (s[cont_s])
	{
		if (s[cont_s] == c || s[cont_s + 1] == '\0')
			words++;
		cont_s++;
	}
	printf("Encontradas estas strings: %i\n", words);
	return (words);
}

char	**ft_newstring(char *s, char c, char **s_n)
{
	int		cont_s;
	int		cont_n;
	int		start;

	cont_s = 0;
	cont_n = 0;
	start = 0;
	while (s[cont_s])
	{
		if (s[cont_s] == c && (s[cont_s + 1] || (s[cont_s + 1] == '\0')))
			start = cont_s + 1;
		if (s[cont_s] && ((s[cont_s + 1] == 'c') || (s[cont_s + 1]) == '\0'))
		{
			s_n[cont_n] = ft_substr(s, start, cont_s - start + 1);
			if (!s_n[cont_n])
				return (ft_free(s_n));
			cont_n++;
		}
		cont_s++;
	}
	s_n[cont_n] = NULL;
	return (s_n);
}

char	**ft_split(char *s, char c)
{
	int		words;
	int		i = 0;
	char	**s_n;

	words = ft_words(s, c);
	s_n = (char **) malloc(sizeof(char *) * (words + 1));
	if (!s_n)
		return (NULL);
	s_n = ft_newstring(s, c, s_n);
	while (s_n[i])
	{
		printf("Cadenas: %s\n", s_n[i]);
		i++;
	}
	return (s_n);
}
