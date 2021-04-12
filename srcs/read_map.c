/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalee <kalee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 03:35:50 by kalee             #+#    #+#             */
/*   Updated: 2021/04/12 18:07:20 by kalee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq_essential.h"

char	**read_map(int fd, t_point *pts)
{
	int		i;
	int		j;
	char	trash[16];
	char	**result;
	char	*buf;

	j = -1;
	result = gen_charmap(pts[0].x, pts[0].y);
	read(fd, trash, 1);
	while (trash[0] != '\n')
		read(fd, trash, 1);
	buf = (char *)malloc((pts[0].x + 5) * sizeof(char));
	while (++j < pts[0].y)
	{
		i = -1;
		while (++i < pts[0].x + 1)
		{
			read(fd, buf, 1);
			if (buf[0] != '\n')
				result[j][i] = buf[0];
			else
				result[j][i] = '\0';
		}
	}
	return (result);
}
