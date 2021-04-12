/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alee <alee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 05:15:34 by alee              #+#    #+#             */
/*   Updated: 2021/04/11 23:05:50 by kalee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_map(char **filled_map, int xsize, int ysize)
{
	int height_index;

	height_index = 0;
	while (height_index < ysize)
	{
		write(1, &filled_map[height_index][0], xsize);
		write(1, "\n", 1);
		height_index++;
	}
	return ;
}
