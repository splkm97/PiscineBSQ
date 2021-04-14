/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_minmax.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalee <kalee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:37:33 by kalee             #+#    #+#             */
/*   Updated: 2021/04/14 19:53:39 by kalee            ###   ########.fr       */
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

void	init_max(int **parsed_map, int width, int *max_val, t_point *max_point)
{
	int x;

	x = -1;
	*max_val = -1;
	while (++x < width)
	{
		if (parsed_map[0][x] > *max_val)
		{
			*max_val = parsed_map[0][x];
			update(max_point, x, 0);
		}
	}
}

void	cal_minmax(int **parsed_map, t_point *pts)
{
	int	x;
	int	y;
	int	max_val;
	t_point	max_point;

	init_max(parsed_map, pts[0].x, &max_val, &max_point);
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
		} // TODO add full count case process
	}
	update(&pts[1], max_point.x - (max_val - 1), max_point.y - (max_val - 1));
	update(&pts[2], max_point.x, max_point.y);
	if (max_val == 0)
		update(&pts[1], -1, -1);
}
