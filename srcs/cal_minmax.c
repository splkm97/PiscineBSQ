/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_minmax.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalee <kalee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:37:33 by kalee             #+#    #+#             */
/*   Updated: 2021/04/14 05:24:02 by kalee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq_essential.h"

int		check_around(int **map, int y, int x)
{
	int min_val;

	if (map[y][x] == 0)
		return (0);
	if (y == 0 || x == 0)
		return (map[y][x]);
	min_val = map[y - 1][x - 1];
	if (map[y - 1][x] < min_val)
		min_val = map[y - 1][x];
	if (map[y][x - 1] < min_val)
		min_val = map[y][x - 1];
	return (min_val + 1);
}

void	update(t_point *point, int x, int y)
{
	point->x = x;
	point->y = y;
}

void	singleline_process(int **parsed_map, t_point *pts)
{
	int i;

	i = -1;
	while (++i < pts[0].x)
	{
		if (parsed_map[0][i] == 1)
		{
			update(&pts[1], i, 0);
			update(&pts[2], i, 0);
			break ;
		}
	}
}

void	reparse(int **parsed_map, t_point *pts)
{
	int	x;
	int	y;
	int	max_val;
	t_point	max_point;

	y = 0;
	while (++y < pts[0].y)
	{
		x = -1;
		while (++x < pts[0].x)
		{
			parsed_map[y][x] = check_around(parsed_map, y, x);
			if (parsed_map[y][x] > max_val)
			{
				max_val = parsed_map[y][x];
				update(&max_point, x, y);
			}
		}
	}
	update(&pts[1], max_point.x - max_val, max_point.y - max_val);
	update(&pts[2], max_point.x, max_point.y);
}

void	cal_minmax(int **parsed_map, t_point *pts)
{
	if (pts[0].y == 1)
	{
		singleline_process(parsed_map, pts);
		return ;
	}
	reparse(parsed_map, pts);
}
