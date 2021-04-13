/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_ctrl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalee <kalee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 03:05:52 by kalee             #+#    #+#             */
/*   Updated: 2021/04/14 03:55:35 by kalee            ###   ########.fr       */
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
	{
		ft_putstr("malloc error\n");
		exit(0);
	}
	ft_strncpy(result, buf, *size);
	*size <<= 1;
	free(buf);
	return (result);
}

char	*read_line(char *buf, int *size, int *last_idx)
{
	int		i;
	char	ch;

	read(0, &ch, 1);
	i = -1;
	while (ch != '\n')
	{
		if (++i + 1 == *size)
			buf = expand_buf(buf, size);
		buf[i] = ch;
		read(0, &ch, 1);
	}
	*last_idx = ++i;
	return (buf);
}
