/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalaing <cmalaing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 08:16:08 by cmalaing          #+#    #+#             */
/*   Updated: 2014/01/09 08:24:43 by cmalaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

static int	secure_string_add(char **line, char *buf, int n)
{
	char	*ret;
	int		len;

	len = (*line ? ft_strlen(*line) : 0);
	if (!(ret = (char*)malloc(sizeof(char) * (len + n + 1))))
		return (0);
	ft_bzero(ret, len + n + 1);
	if (*line)
	{
		ft_strcpy(ret, *line);
		free(*line);
	}
	ft_strncat(ret, buf, n);
	*line = ret;
	return (1);
}

static int	refresh(char *buf, int i)
{
	ft_strncpy(buf, &(buf[i]), BUFF_SIZE);
	return (1);
}

static int	loop_concat(int const fd, int *check, char **buf, char **line)
{
	int		i;

	i = 0;
	while (*check > -1 && (*buf)[i] != '\n'
		&& !((*buf)[i] == '\0' && *check == 0))
	{
		if ((*buf)[i] == '\0')
		{
			if (!secure_string_add(line, *buf, i))
				return (-1);
			*check = read(fd, (*buf), BUFF_SIZE);
			(*buf)[*check] = 0;
			i = -1;
		}
		i++;
	}
	return (i);
}

int			get_next_line(int const fd, char **line)
{
	static char	*buf;
	int			i;
	static int	check;

	*line = NULL;
	if (!buf)
	{
		if (!(buf = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))))
			return (-1);
		check = read(fd, buf, BUFF_SIZE);
		buf[check] = 0;
	}
	if (!check)
		return (0);
	i = loop_concat(fd, &check, &buf, line);
	if (buf[i] == '\n' || buf[i] == '\0')
	{
		if (!secure_string_add(line, buf, i) || !refresh(buf, i + 1))
			return (-1);
	}
	return (check);
}
