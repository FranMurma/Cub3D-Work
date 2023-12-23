/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:46:20 by frmurcia          #+#    #+#             */
/*   Updated: 2023/12/23 12:35:55 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# define BUFFER_SIZE 100
# define TAB_SPACES 4

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>

# include "../premap/texture.h"

typedef struct s_map
{
	char	*map_raw;
	char	**map_2d;
	int		max_height;
	int		max_width;
	int		map_start;
	int		map_end;
	bool	found_map;
}	t_map;

//check parameters
bool    ft_check_nbr_arguments(int argc);
bool    ft_check_extension(char **argv);
void    ft_check_parameters(int argc, char **argv);
void	ft_start_map(char **argv);

// map.c
t_map	init_map(t_map *map);
void	create_2d(t_map *map);
void    handle_slash_en(int *y, int *k, int *x);
void    handle_tabs(t_map *map, int y, int *x, int *k);
void    copy_line_to_map(t_map *map);

// read_map.c
bool    is_empty_or_spaces(char *line);
void    append_line_to_map_raw(t_map *map, char *line, int *line_number);
void    process_map_line(t_map *map, char *line,
		int *line_number);
void 	set_measures_and_close(t_map *map, int line_number, int fd);
void 	ft_read_map(char** argv, t_map *map);
void    print_filled_map(t_map *map);

// aux_maps.c
// // Funciones de libft y el write error con mensaje
void	ft_write_error(char *message);
char 	*ft_strncpy(char *dest, const char *src, size_t n);
int     ft_strlen(const char *str);
char    *ft_strdup(const char *s1);
char    *ft_strjoin(char const *s1, char const *s2);

// aux_maps2.c
void	ft_write(char *message);
char    *ft_strtrim(char const *s1, char const *set);
bool    ft_strcmp(char *s1, char *s2);
size_t  ft_strlcpy(char *dst, const char *src, size_t dstsize);
void    *ft_memmove(void *dst, const void *src, size_t len);
//aux_maps3.c
bool    ft_check_comas(char *input);
void    ft_bzero(void *str, size_t n);
void    *ft_calloc(size_t count, size_t size);
void    *ft_memcpy(void *dst, const void *src, size_t n);
char    *ft_substr(char const *s, unsigned int start, size_t len);

//aux_mapa4.c
char    *ft_strndup(char *s1, size_t len);

// check_lines.c
	// Funciones para asegurar que la linea es de mapa y ver que linea es la mas ancha
bool    skip_whitespace(char *line, int *length);
void    start_map(int *length, bool *map_started);
void    process_other_chars(char *line, int *length);
bool    is_valid_map_line(char *line);
bool    is_valid_line_inside(char *line);

// get_next_line
char    *get_next_line(int fd);
char    *ft_read(int fd, char *ptr);
char    *ft_cutword(char *prt);
char    *ft_strchr(const char *s, int c);
char    *ft_substr_m(char const *s, unsigned int start, size_t len);


//split
char		**ft_split(char const *s, char c);

//exit_map.c
void    free_init_map(t_map *map);
void    free_map_2d(t_map *map);
void	free_map(t_map *map);

# endif
