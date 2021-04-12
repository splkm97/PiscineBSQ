/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalee <kalee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 23:19:51 by kalee             #+#    #+#             */
/*   Updated: 2021/04/13 01:08:09 by kalee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq_essential.h"

void	bsq_logic(char *filename, char *charset, t_point *pts)
{
	int		fd;
	char	**map;
	int		**parsed_map;

	fd = open(filename, O_RDONLY);
	map = read_map(fd, pts);
	close(fd);
	parsed_map = parse_map(map, pts, charset);
	cal_minmax(parsed_map, pts);
	fill_map_char(map, pts, charset);
	print_map(map, pts[0].x, pts[0].y);
	free_intmap(parsed_map, pts[0].y);
	free_charmap(map, pts[0].y);
}

int		io_process(char *filename, char *charset, t_point *pts)
{
	int	fd;
	int	idx;
	int	flag;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	pts[0].y = get_map_height(fd, charset, &idx);
	close(fd);
	if (pts[0].y <= 0)
		return (-1);
	fd = open(filename, O_RDONLY);
	pts[0].x = get_map_width(fd, idx);
	close(fd);
	fd = open(filename, O_RDONLY);
	flag = valid_mapcheck(fd, pts[0].x, pts[0].y, charset);
	close(fd);
	if (flag == -1)
		return (-1);
}

int		main(int argc, char **argv)
{
	int		i;
	int		flag;
	char	charset[3];
	t_point	*pts;

	i = 0;
	while (++i < argc)
	{
		pts = (t_point *)malloc(3 * sizeof(t_point));
		flag = io_process(argv[i], charset, pts);
		if (flag == -1)
		{
			ft_putstr("map error\n");
			continue;
		}
		bsq_logic(argv[i], charset, pts);
		free(pts);
	}
	return (0);
}
