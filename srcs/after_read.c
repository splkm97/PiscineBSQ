/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   after_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalee <kalee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 19:10:56 by kalee             #+#    #+#             */
/*   Updated: 2021/04/14 19:18:19 by kalee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq_essential.h"

int		after_read(char **raw_map, char *charset, t_point *pts)
{
	int		**parsed_map;

	parsed_map = parse_map(raw_map, pts, charset);
	if (parsed_map == 0)
		return (-1);
	cal_minmax(parsed_map, pts);
	fill_map_char(raw_map, pts, charset);
	print_map(raw_map, pts[0].x, pts[0].y);
	free_intmap(parsed_map, pts[0].y);
	free_charmap(raw_map, pts[0].y);
	free(pts);
	return (0);
}
