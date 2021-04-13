/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin_case.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alee <alee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 03:56:17 by alee              #+#    #+#             */
/*   Updated: 2021/04/14 04:01:14 by alee             ###   ########.fr       */
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
	

	//overlap check
	
	//nonprintable check
	

	return (0);
}

int		stdin_case(void)
{
	char	*buffer;
	int		buffer_size;
	char	charset[3];
	int		newline_index;

	buffer_size = 2;
	buffer = (char*)malloc(buffer_size);	
	
	//Expand buffer
	buffer = read_line(buffer, &buffer_size, &newline_index);

	//Extract charset
	if (extract_charset(charset, buffer, newline_index))
		return (-1);	
	
	//Extract height value
	

	//Comfirm hegith value [numeric]
	

	return (0);
}
