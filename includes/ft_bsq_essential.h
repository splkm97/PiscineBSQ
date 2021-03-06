/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq_essential.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalee <kalee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 00:42:32 by kalee             #+#    #+#             */
/*   Updated: 2021/04/15 04:41:29 by kalee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BSQ_ESSENTIAL_H
# define FT_BSQ_ESSENTIAL_H

# include <unistd.h>
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

void			ft_putstr(char *str);
int				ft_atoi(char *str);
int				is_numeric(char ch);
int				is_printable(char ch);
int				setcheck(char *buf);
char			*read_line(char *buf, int *size, int *last_idx);
char			*read_line_file(int fd, char *buf, int *size, int *last_idx);

int				stdin_case(char *charset, t_point *pts);
int				get_map_height(int fd, char *charset, int *endpoint);
int				get_map_width(int fd, int idx);
int				valid_mapcheck(int fd, int width, int height);

char			**read_map(int fd, t_point *pts);
int				**parse_map(char **raw_map, t_point *pts, char *charset);
int				after_read(char **map, char *charset, t_point *pts);
void			cal_minmax(int **parsed_map, t_point *pts);
void			fill_map_char(char **raw_map, t_point *pts, char *charset);
void			print_map(char **filled_map, int xsize, int ysize);

int				**gen_intmap(int width, int height);
char			**gen_charmap(int width, int height);
void			free_intmap(int **map, int height);
void			free_charmap(char **map, int height);

void			ft_strncpy(char *dest, char *src, int size);

#endif
