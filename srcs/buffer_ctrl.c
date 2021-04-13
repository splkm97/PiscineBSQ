/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_ctrl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalee <kalee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 03:05:52 by kalee             #+#    #+#             */
/*   Updated: 2021/04/14 03:06:30 by kalee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq_essential.h"

void	ft_strncpy(char *dest, char*src, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
}

char	*expand_buf(char *buf, int *size)
{
	char *result;

	if (!(result = (char *)malloc(*size << 1)))
		exit(0);
	ft_strncpy(result, buf, *size);
	*size <<= 1;
	free(buf);
	return (result);
}
