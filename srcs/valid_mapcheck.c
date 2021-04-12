/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_mapcheck.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalee <kalee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 22:03:10 by kalee             #+#    #+#             */
/*   Updated: 2021/04/13 03:25:32 by kalee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq_essential.h"

int	mapcheck_width(int fd, int width)
{
	char	buf;
	int		rsize;
	int		total_count;

	rsize = read(fd, &buf, 1);
	if (rsize == 0)
		return (-1);
	total_count = 1;
	while (buf != '\n')
	{
		rsize = read(fd, &buf, 1);
		if (rsize == 0)
			return (-1);
		total_count++;
	}
	if (total_count - 1 != width)
		return (-1);
	return (0);
}

int	valid_mapcheck(int fd, int width, int height)
{
	char	buf[2];
	char	rsize;

	rsize = read(fd, buf, 1);
	if (rsize == 0 || buf[0] == '\n')
		return (-1);
	if (width <= 0 || height <= 0)
		return (-1);
	while (buf[0] != '\n')
	{
		rsize = read(fd, buf, 1);
		if (rsize == 0)
			return (-1);
	}
	while (height--)
	{
		if (mapcheck_width(fd, width) == -1)
			return (-1);
	}
	return (0);
}
