/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq_essential.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalee <kalee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 00:42:32 by kalee             #+#    #+#             */
/*   Updated: 2021/04/12 17:28:34 by kalee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BSQ_ESSENTIAL_H
# define FT_BSQ_ESSENTIAL_H

# define trs(x...) { printf("[%s:%d] %s = ", __func__, __LINE__, #x); printf("%s\n", x); }
# define tri(x...) { printf("[%s:%d] %s = ", __func__, __LINE__, #x); printf("%d\n", x); }
# include <stdio.h>

# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct	s_point
{
	int x;
	int y;
}				t_point;

typedef struct	s_entry
{
	int		area;
	t_point	left;
	t_point	right;
	int		idx;
	int		height;
}				t_entry;

int				**parse_map(char **raw_map, t_point *pts, char *charset);
int				get_map_height(int fd, char *charset, int *endpoint);
int				get_map_width(int fd, int idx);
char			**read_map(int fd, t_point *pts);
void			cal_minmax(int **parsed_map, t_point *pts);
void			fill_map_char(char **raw_map, t_point *pts, char *charset);
void			print_map(char **filled_map, int xsize, int ysize);
void			handle_error(char *msg);
void			ft_putstr(char *str);
int				**gen_intmap(int width, int height);
void			free_intmap(int **map, int height);
void			free_charmap(char **map, int height);

#endif
