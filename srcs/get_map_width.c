/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_width.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alee <alee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 05:24:36 by alee              #+#    #+#             */
/*   Updated: 2021/04/12 16:26:28 by kalee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int		is_newline(char c)
{
	if (c == '\n')
		return (1);
	return (0);
}

int		get_map_width(int fd, int idx)
{
	char	buffer[128];
	int		cur_index;
	int		read_count;
	int		width_count;

	cur_index = 0;
	read_count = idx / sizeof(buffer);
	while (read_count--)
		read(fd, buffer, sizeof(buffer));
	read(fd, buffer, sizeof(buffer));
	while (*(buffer + cur_index) != '\n')
		cur_index++;
	width_count = 0;
	cur_index++;
	while (is_newline(*(buffer + cur_index)) == 0)
	{
		cur_index++;
		width_count++;
	}
	return (width_count);
}
