/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalee <kalee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:32:56 by kalee             #+#    #+#             */
/*   Updated: 2021/04/12 17:20:56 by kalee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq_essential.h"

int	**parse_map(char **raw_map, t_point *pts, char *charset)
{
	int y;
	int x;
	int **result;
	
	result = gen_intmap(pts[0].x, pts[0].y);
	y = -1;
	while (++y < pts[0].y)
	{
		x = -1;
		while (++x < pts[0].x)
		{
			if (raw_map[y][x] == charset[0])
				result[y][x] = 1;
			else if (raw_map[y][x] == charset[1])
				result[y][x] = 0;
		}
	}
	return result;
}
