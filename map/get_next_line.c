/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:10:05 by frmurcia          #+#    #+#             */
/*   Updated: 2023/12/19 11:30:00 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

char	*ft_substr_m(char const *s, unsigned int start, size_t len)
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

char	*ft_strchr(const char *s, int c)
{
	int	cont;

	cont = 0;
	while (s[cont] != '\0')
	{
		if (s[cont] == (char)c)
			return ((char *)(s + cont));
		cont++;
	}
	if (s[cont] == (char)c)
		return ((char *)(s + cont));
	return (NULL);
}
/*
char	*ft_cutword(char *prt)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	j = 0;
	while (prt[i] != '\n' && prt[i])
		i++;
	if (!prt[i])
	{
		free(prt);
		return (NULL);
	}
	if (prt[i] == '\n')
		i++;
	dest = malloc(sizeof(char) * (ft_strlen(prt) - i + 1));
	if (!dest)
		return (NULL);
	while (prt[i])
		dest[j++] = prt[i++];
	dest[j] = '\0';
	free(prt);
	return (dest);
}*/
/*
char	*ft_read(int fd, char *ptr)
{
	int		bytes;
	char	*temp;

	bytes = 1;
	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	while (!ft_strchr(ptr, '\n') && bytes != 0)
	{
		bytes = read(fd, temp, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(temp);
			free(ptr);
			return (NULL);
		}
		temp[bytes] = '\0';
		ptr = ft_strjoin(ptr, temp);
	}
	free(temp);
	return (ptr);
}*/
/*
char	*get_next_line(int fd)
{
	static char	*ptr;
	char		*line;
	int			cont;

	cont = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!ptr)
		ptr = ft_strdup("");
//	if (!handle_blank_lines(fd, &ptr))
//		return (NULL);
	ptr = ft_read(fd, ptr);
	if (!ptr)
	{
		free(ptr);
		return (NULL);
	}
	while (ptr[cont] != '\n' && ptr[cont])
		cont++;
	line = ft_substr_m(ptr, 0, cont + 1);
	ptr = ft_cutword(ptr);
	if (!line || !line[0])
	{
		free(line);
		return (NULL);
	}
	return (line);
}*/

char	*free_malloc(char *str)
{
	free(str);
	return (NULL);
}

int	contain_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	get_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	get_storage_len(char *storage)
{
	if (storage)
		return (get_len(storage));
	else
		return (0);
}

char	*concat_str(char *storage, char *buffer, int len_b)
{
	int		i;
	int		len_s;
	char	*str;

	len_s = get_storage_len(storage);
	str = malloc(sizeof(char) * (len_s + len_b + 1));
	if (str == NULL)
		return (free_malloc(storage));
	i = 0;
	while (i < len_s)
	{
		str[i] = storage[i];
		i++;
	}
	i = 0;
	while (i < len_b)
	{
		str[len_s + i] = buffer[i];
		i++;
	}
	str[len_s + i] = '\0';
	free(storage);
	return (str);
}

int	count_line_words(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (i + 1);
}

void	clean_storage(char *storage)
{
	int		old_len;
	int		new_len;
	int		i;

	old_len = count_line_words(storage);
	new_len = get_len(storage) - old_len;
	i = 0;
	while (i < new_len)
	{
		storage[i] = storage[old_len + i];
		i++;
	}
	while (i < old_len)
	{
		storage[i] = '\0';
		i++;
	}
	storage[i] = '\0';
}

char	*extract_line(char *str)
{
	int		words;
	int		i;
	char	*line;

	words = count_line_words(str);
	line = malloc(sizeof(char) * (words + 1));
	if (line == NULL)
	{
		free(str);
		return (NULL);
	}
	i = 0;
	while (i < words)
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	clean_storage(str);
	return (line);
}

char	*extract_last_line(char *str, int numbytes, char *buffer)
{
	int		words;
	int		i;
	char	*line;

	free(buffer);
	if (str == NULL || numbytes == -1)
		return (free_malloc(str));
	if (str[0] == '\0')
		return (free_malloc(str));
	words = get_len(str);
	line = malloc(sizeof(char) * (words + 1));
	if (line == NULL)
		return (free_malloc(str));
	i = 0;
	while (i < words)
	{
		line[i] = str[i];
		str[i] = '\0';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*storage;
	int			numbytes;

	if (fd == -1 || fd >= 1000)
		return (NULL);
	if (storage && contain_line(storage) == 1)
		return (extract_line(storage));
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (free_malloc(storage));
	numbytes = read(fd, buffer, BUFFER_SIZE);
	if (numbytes == 0 || numbytes == -1)
		return (extract_last_line(storage, numbytes, buffer));
	buffer[BUFFER_SIZE] = '\0';
	storage = concat_str(storage, buffer, numbytes);
	free(buffer);
	buffer = NULL;
	if (storage == NULL)
		return (NULL);
	return (get_next_line(fd));
}
