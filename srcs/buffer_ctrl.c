/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_ctrl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalee <kalee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 03:05:52 by kalee             #+#    #+#             */
/*   Updated: 2021/04/15 02:04:53 by alee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq_essential.h"

void	ft_strncpy(char *dest, char *src, int size)
{
	int i;

	i = 0;
	trs("strncpy() called")
	while (i < size)
	{
		tri(i);
		dest[i] = src[i];
		i++;
	}
	trs("strncpy() ok")
}

char	*expand_buf(char *buf, int *size)
{
	char *result;

	trs("expand_buf() called")
	result = (char *)malloc(sizeof(char) * (*size << 1));
	if (!result)
	{
		ft_putstr("malloc error\n");
		exit(0);
	}
	tri(*size)
	ft_strncpy(result, buf, *size);
	trs("strncpy() ok")
	*size <<= 1;
	free(buf);
	trs("expand_buf() end")
	return (result);
}

char	*read_line(char *buf, int *size, int *last_idx)
{
	int		i;
	char	ch;

	trs("read_line() called")
	read(0, &ch, 1);
	i = 1;
	while (ch != '\n')
	{
		if (i + 1 == *size)
			buf = expand_buf(buf, size);
		buf[i] = ch;
		read(0, &ch, 1);
		i++;
	}
	*last_idx = ++i;
	trs("read_line ok")
	return (buf);
}

char	*read_line_file(int fd, char *buf, int *size, int *last_idx)
{
	int		i;
	char	ch;

	read(fd, &ch, 1);
	i = -1;
	while (ch != '\n')
	{
		if (++i + 1 == *size)
			buf = expand_buf(buf, size);
		buf[i] = ch;
		read(fd, &ch, 1);
	}
	*last_idx = ++i;
	return (buf);
}
