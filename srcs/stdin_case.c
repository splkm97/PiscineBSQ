/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin_case.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alee <alee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 03:56:17 by alee              #+#    #+#             */
/*   Updated: 2021/04/13 06:21:44 by alee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq_essential.h"

int		buffer_check(char *data_buf)
{

	return (0);
}

int		stdin_case(void)
{
	char	buf;
	int		rsize;
	char	buffer[14];
	int		cur_index;
	char	charset[3];
	int		height;

	rsize = read(0, &buf, 1);
	if (rsize == 0 || buf == '\n')
		return (-1)
	cur_index = 0;
	while (buf != '\n')
	{
		if (cur_index >= sizeof(buffer) -1)
			return (-1);
		buffer[cur_index++] = buf;
		rsize = read(0, &buf, 1);
		if (rsize == 0)
			return (-1);
	}
	buffer[cur_index] = '\0';
	charset[0] = buffer[cur_index - 3];
	charset[1] = buffer[cur_index - 2];
	charset[2] = buffer[cur_index - 1];
	buffer[cur_index - 3] = '\0';
	height = ft_atoi(buffer);
	//TODO - Map Checking
	return (0);
}
