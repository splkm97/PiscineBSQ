/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalee <kalee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 22:28:00 by kalee             #+#    #+#             */
/*   Updated: 2021/04/11 23:51:45 by kalee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq_essential.h"

void	fill_map_char(char **raw_map, t_point *pts, char *charset)
{
	int i;
	int j;

	i = pts[1].y - 1;
	while (++i < pts[2].y)
	{
		j = pts[1].x - 1;
		while (++j < pts[2].x)
			raw_map[i][j] = charset[2];
	}
}
