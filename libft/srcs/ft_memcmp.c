/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalaing <cmalaing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 13:40:40 by cmalaing          #+#    #+#             */
/*   Updated: 2013/11/24 10:37:23 by cmalaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	*ptr;

	str = (unsigned char*)s1;
	ptr = (unsigned char*)s2;
	i = 0;
	while (str[i] == ptr[i] && i < n)
		i++;
	if (i == n)
		i -= 1;
	return (str[i] - ptr[i]);
}
