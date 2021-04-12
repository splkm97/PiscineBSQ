/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_height.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalee <kalee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 20:06:50 by kalee             #+#    #+#             */
/*   Updated: 2021/04/13 02:42:57 by kalee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq_essential.h"

int	is_numeric(char ch)
{
	if (ch >= '0' && ch <= '9')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int i;
	int pos_flag;
	int sum;

	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	pos_flag = 1;
	while (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			pos_flag = !pos_flag;
	if (!is_numeric(str[i]))
		return (0);
	sum = 0;
	while (is_numeric(str[i]))
	{
		sum *= 10;
		sum += str[i] - '0';
		i++;
	}
	if (!pos_flag)
		sum = -sum;
	return (sum);
}

int	setcheck(char *buf, int size)
{
	int i;

	i = -1;
	while (buf[++i])
		if (buf[i] < '0' || buf[i] > '9')
			return (-1);
	return (0);
}

int	is_printable(char ch)
{
	if (ch >= 32 && ch < 127)
		return (1);
	return (0);
}

int	get_map_height(int fd, char *charset, int *endpoint)
{
	int		size;
	char	buf[20];

	size = 0;
	read(fd, buf, 16);
	while (buf[size] != '\n' && size < 15)
		size++;
	if (size == 15)
		return (-1);
	if (size < 4)
		return (-1);
	charset[0] = buf[size - 3];
	charset[1] = buf[size - 2];
	charset[2] = buf[size - 1];
	if (!(is_printable(charset[0]) && is_printable(charset[1]) && is_printable(charset[2])))
		return (-1);
	buf[size - 3] = '\0';
	if (setcheck(buf, size) == -1)
		return (-1);
	*endpoint = size;
	size = ft_atoi(buf);
	return (size);
}
