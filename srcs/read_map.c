/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalee <kalee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 03:35:50 by kalee             #+#    #+#             */
/*   Updated: 2021/04/12 16:28:16 by kalee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq_essential.h"

char	**gen_map(int width, int height)
{
	char	**result;
	int		i;

	result = (char **)malloc(height * sizeof(char *));
	i = -1;
	while (++i < height)
		result[i] = (char *)malloc(width * sizeof(char));
	return (result);
}

char	**read_map(int fd, t_point *pts)
{
	int		i;
	int		j;
	char	trash[16];
	char	**result;
	char	*buf;

	j = 0;
	result = gen_map(pts[0].x, pts[0].y);
	read(fd, trash, 1);
	while (trash[0] != '\n')
		read(fd, trash, 1);
	buf = (char *)malloc((pts[0].x + 5) * sizeof(char));
	while (j < pts[0].y)
	{
		i = 0;
		while (i < pts[0].x + 1)
		{
			read(fd, buf, 1);
			if (buf[0] != '\n')
				result[j][i] = buf[0];
			i++;
		}
		j++;
	}
	return (result);
}
