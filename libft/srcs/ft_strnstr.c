/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalaing <cmalaing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 14:53:24 by cmalaing          #+#    #+#             */
/*   Updated: 2013/12/01 16:16:41 by cmalaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	if (!(*s2))
		return ((char*)s1);
	i = 0;
	while (s1[i] && i < n)
	{
		j = 0;
		while (i + j < n && s2[j] && s1[i + j] == s2[j])
			j++;
		if (!s2[j])
			return ((char*)(s1 + i));
		i++;
	}
	return (NULL);
}
