/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_minmax.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalee <kalee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:37:33 by kalee             #+#    #+#             */
/*   Updated: 2021/04/12 18:01:34 by kalee            ###   ########.fr       */
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

void	cal_minmax(int **parsed_map, t_point *pts)
{
	int		y;
	int		x;
	int		max_val;
	t_point	max_point;

	y = 0;
	max_val = 0;
	while (++y < pts[0].y)
	{
		x = -1;
		while (++x < pts[0].x)
		{
			parsed_map[y][x] = check_around(parsed_map, y, x);
			if (parsed_map[y][x] > max_val)
			{
				max_val = parsed_map[y][x];
				max_point.x = x;
				max_point.y = y;
			}
		}
	}
	pts[1].x = max_point.x - max_val;
	pts[1].y = max_point.y - max_val;
	pts[2].x = max_point.x;
	pts[2].y = max_point.y;
}
