/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalee <kalee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 23:19:51 by kalee             #+#    #+#             */
/*   Updated: 2021/04/12 16:29:25 by kalee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define trs(x...) { printf("[%s:%d] %s = ", __func__, __LINE__, #x); printf("%s\n", x); }
#define tri(x...) { printf("[%s:%d] %s = ", __func__, __LINE__, #x); printf("%d\n", x); }
#include "ft_bsq_essential.h"
#include <stdio.h>

void	handle_error(char *msg)
{
	ft_putstr(msg);
	write(1, "\n", 1);
	exit(1);
}

void	bsq_logic(int fd, char *charset, t_point *pts)
{
	char	**map;
	int		**parsed_map;

	map = read_map(fd, pts);
	print_map(map, pts[0].x, pts[0].y);
	close(fd);
	parse_map(map, pts, charset);
	fill_map_char(map, pts, charset);
	print_map(map, pts[0].x, pts[0].y);
	free(map);
	free(pts);
}

int		main(int argc, char **argv)
{
	int		i;
	int		idx;
	int		fd;
	char	charset[3];
	t_point	*pts;

	i = 0;
	while (++i < argc)
	{
		pts = (t_point *)malloc(3 * sizeof(t_point));
		fd = open(argv[i], O_RDONLY);
		if (fd == -1)
			handle_error("map file error: file is missing");
		pts[0].y = get_map_height(fd, charset, &idx);
		if (pts[0].y <= 0)
			handle_error("map error");
		close(fd);
		fd = open(argv[i], O_RDONLY);
		pts[0].x = get_map_width(fd, idx);
		fd = open(argv[i], O_RDONLY);
		bsq_logic(fd, charset, pts);
		close(fd);
	}
	return (0);
}
