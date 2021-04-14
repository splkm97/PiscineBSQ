/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_width.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alee <alee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 05:24:36 by alee              #+#    #+#             */
/*   Updated: 2021/04/14 18:12:42 by kalee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq_essential.h"

int		is_newline(char c)
{
	if (c == '\n')
		return (1);
	return (0);
}

int		get_map_width(int fd, int idx)
{
	char	*buffer;
	int		width;
	int		size;

	size = 2;
	buffer = (char *)malloc(size * sizeof(char));
	buffer = read_line(buffer, &size, &width);
	return (width);
}
