/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalee <kalee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:45:23 by kalee             #+#    #+#             */
/*   Updated: 2021/04/12 17:36:35 by kalee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq_essential.h"

int		**gen_intmap(int width, int height)
{
	int **result;
	int i;
	
	result = (int **)malloc(height * sizeof(int *));
	i = -1;
	while (++i < height)
		result[i] = malloc(width * sizeof(int));
	return result;
}

void	free_charmap(char **map, int height)
{
	int i;

	trs("free_charmap called");
	i = -1;
	while (++i < height)
		free(map[i]);
	trs("free all map[i]s");
	free(map);
}

void	free_intmap(int **map, int height)
{
	int i;

	i = -1;
	while (++i < height)
		free(map[i]);
	free(map);
}
