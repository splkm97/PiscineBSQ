/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_mapcheck.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalee <kalee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 22:03:10 by kalee             #+#    #+#             */
/*   Updated: 2021/04/13 00:57:13 by alee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq_essential.h"

int	mapcheck_width(int fd, int width)
{
	char	buf;
	int		rsize;
	int		total_count;

	rsize = read(fd, buf, 1);
	if (rsize == 0)
		return (-1);
	total_count = 1;
	while (buf[0] != '\n')
	{
		rsize = read(fd, buf, 1);
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
	//char	buf[2];
	//int		rsize;

	//rsize = read(fd, buf, 1);
	//while (buf[0] != '\n')
	//{
	//	rsize = read(fd, buf, 1);
	//	if (rsize == 0)
	//		return (0);
	//}
	//while (height != 0)
	//{
	//	//TODO map error check
	//	height--;
	//}
	//rsize = read(fd, buf, 1);
	//if (rsize == 0)
	//	return (0);
	//ret value 
	//error : -1
	//ok	:  0
	char	buf[2];
	char	rsize;

	rsize = read(fd, buf, 1);
	if (rsize == 0)
		return (-1);
	while (buf[0] != '\n')
	{
		rsize = read(fd, buf, 1);
		if (rsize == 0)
			return (-1);
	}
	while (height--)
	{
		if( mapcheck_width(fd, width) == -1)
			return (-1);
	}
	return (0);
}
