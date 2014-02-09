/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalaing <cmalaing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 13:14:47 by cmalaing          #+#    #+#             */
/*   Updated: 2014/01/09 08:25:02 by cmalaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	*d;

	i = 0;
	s = (unsigned char*) s1;
	d = (unsigned char*) s2;
	while (i < n && d[i] != (unsigned char)c)
	{
		s[i] = d[i];
		i++;
	}
	if (i == n)
		return (NULL);
	if (d[i] == (unsigned char)c)
	{
		s[i] = d[i];
		i++;
	}
	return ((void*)(s + i));
}
