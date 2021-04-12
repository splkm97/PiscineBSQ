/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_mapcheck.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalee <kalee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 22:03:10 by kalee             #+#    #+#             */
/*   Updated: 2021/04/13 02:00:33 by alee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq_essential.h"
#include <stdio.h>

int	mapcheck_width(int fd, int width, char *charset)
{
	char	buf;
	int		rsize;
	int		total_count;
	int		cur_count;

	rsize = read(fd, &buf, 1);
	if (rsize == 0 || buf == '\n')
		return (-1);
	total_count = 1;
	cur_count = width;
	while (cur_count--)
	{
		rsize = read(fd, &buf, 1);
		if (rsize == 0 || buf != charset[0] || buf != charset[1])
			return (-1);
		total_count++;
	}
	return (0);
}

int	valid_mapcheck(int fd, int width, int height, char *charset)
{
	//ret value 
	//error : -1
	//ok	:  0
	char	buf[2];
	char	rsize;

	rsize = read(fd, buf, 1);
	//Exception Case
	if (rsize == 0 || buf[0] == '\n')
		return (-1);
	if (width <= 0 || height <= 0)
		return (-1);
	//Command line Skip
	while (buf[0] != '\n')
	{
		rsize = read(fd, buf, 1);
		if (rsize == 0)
			return (-1);
	}
	//Data Buffer
	while (height--)
	{
		if( mapcheck_width(fd, width, charset) == -1)
			return (-1);
	}
	return (0);
}
