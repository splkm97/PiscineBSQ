/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_mapcheck.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalee <kalee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 22:03:10 by kalee             #+#    #+#             */
/*   Updated: 2021/04/12 22:29:40 by kalee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq_essential.h"

int	valid_mapcheck(int fd, int width, int height)
{
	char	buf[2];
	int		rsize;

	rsize = read(fd, buf, 1);
	while (buf[0] == '\n')
	{
		rsize = read(fd, buf, 1);
		if (rsize == 0)
			return (0);
	}
	while (height != 0)
	{
		//TODO map error check
		height--;
	}
	rsize = read(fd, buf, 1);
	if (rsize == 0)
		return (0);
}
