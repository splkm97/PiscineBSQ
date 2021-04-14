/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin_case.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alee <alee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 03:56:17 by alee              #+#    #+#             */
/*   Updated: 2021/04/15 01:13:08 by alee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq_essential.h"

int		extract_charset(char *charset, char* dest_buffer, int newline_index)
{
	int cur_index;

	cur_index = 0;
	charset[0] = dest_buffer[newline_index - 3];
	charset[1] = dest_buffer[newline_index - 2];
	charset[2] = dest_buffer[newline_index - 1];

	//non printable check	
	while (cur_index < 3)
	{
		if (is_printable(charset[cur_index]) == 0)
			return (-1);
	}
	//overlap check
	if (charset[0] == charset[1] || charset[1] == charset[2] || charset[2] == charset[0])
		return (-1);
	return (0);
}

int		extract_height(char *dest_buffer, int newline_index, int *height)
{
	dest_buffer[newline_index - 3] = '\0';

	//height numeric check
	if (setcheck(dest_buffer) == -1)
		return (-1);
	//height value check
	*height = ft_atoi(dest_buffer);
	if (*height <= 0)
		return (-1);
	return (0);
}

int		map_cpy(char **dest_buf, char* src_buf, int width, int height)
{
	int cur_index;
	int buffer_size;
	int map_width;

	height--;
	cur_index = 0;
	ft_strncpy(dest_buf[cur_index++], src_buf, width);
	while (height--)
	{
		free(src_buf);
		buffer_size = width;
		map_width = 0;
		src_buf = (char*)malloc(buffer_size);
		src_buf = read_line(src_buf, &buffer_size, &map_width);
		if (buffer_size != map_width)
			return (-1);
		ft_strncpy(dest_buf[cur_index++], src_buf, map_width);
	}
	return (0);
}

void	buffer_alloc(char *alloc_buffer, int *size)
{
	*size = 2;
	alloc_buffer = (char*)malloc(*size);
	return ;
}

int		extract_proc(char* buffer, char* charset, int *newline_index, int *height)
{
	return (-1);
}

int		stdin_case(char* charset, t_point* pts)
{
	char	*buffer;
	int		buffer_size;
	int		newline_index;
	int		height;
	char	**map_buff;
	
	trs("!")
	buffer_alloc(buffer, &buffer_size);
	buffer = read_line(buffer, &buffer_size, &newline_index);
	//extract proc
	//if(extract_proc(buffer, charset, &newline_index, &height) == 0)
	//	return (-1);
	trs("!!")
	if (extract_charset(charset, buffer, newline_index) == -1
			|| extract_height(buffer, newline_index, &height) == -1)
	{
		free(buffer);
		ft_putstr("map error\n");
		exit(0);
	}
	free(buffer);
	trs("!!!")
	buffer_alloc(buffer, &buffer_size);
	trs("!!!!")
	buffer = read_line(buffer, &buffer_size, &newline_index);
	trs("!!!!!")
	map_buff = gen_charmap(newline_index, height);
	trs("!!!!!!")
	if (map_cpy(map_buff, buffer, newline_index, height) == -1)
	{
		free_charmap(map_buff, height);
		free(buffer);
		ft_putstr("map error\n");
		exit(0);
	}
	trs("123")
	pts = (t_point*)malloc(sizeof(t_point) * 3);
	trs("1234")
	after_read(map_buff, charset, pts);
	trs("12345")
	return (0);
}
