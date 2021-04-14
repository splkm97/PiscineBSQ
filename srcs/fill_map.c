/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalee <kalee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 22:28:00 by kalee             #+#    #+#             */
/*   Updated: 2021/04/14 19:29:47 by kalee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq_essential.h"

void	fill_map_char(char **raw_map, t_point *pts, char *charset)
{
	int y;
	int x;

	if (pts[1].x == pts[2].x && pts[1].y == pts[2].y)
		raw_map[pts[1].y][pts[1].x] = charset[2];
	if (pts[1].x == -1)
		return ;
	y = pts[1].y;
	while (++y <= pts[2].y)
	{
		x = pts[1].x;
		while (++x <= pts[2].x)
			raw_map[y][x] = charset[2];
	}
}
