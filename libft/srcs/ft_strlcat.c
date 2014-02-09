/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalaing <cmalaing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 14:17:00 by cmalaing          #+#    #+#             */
/*   Updated: 2013/12/10 12:02:51 by cmalaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	n;
	size_t	result;

	i = 0;
	while (i < size)
	{
		if (dst[i] == '\0')
			break ;
		i++;
	}
	result = i + ft_strlen(src);
	n = size - i - 1;
	if (i != size)
	{
		j = 0;
		while (src[j] && j < n)
			dst[i++] = src[j++];
		dst[i] = '\0';
	}
	return (result);
}
