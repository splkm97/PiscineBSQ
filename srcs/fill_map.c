/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalee <kalee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 22:28:00 by kalee             #+#    #+#             */
/*   Updated: 2021/04/12 18:00:46 by kalee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq_essential.h"

void	fill_map_char(char **raw_map, t_point *pts, char *charset)
{
	int y;
	int x;

	y = pts[1].y;
	while (++y <= pts[2].y)
	{
		x = pts[1].x;
		while (++x <= pts[2].x)
			raw_map[y][x] = charset[2];
	}
}
