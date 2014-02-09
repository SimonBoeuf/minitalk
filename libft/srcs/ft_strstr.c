/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalaing <cmalaing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 14:44:42 by cmalaing          #+#    #+#             */
/*   Updated: 2013/11/25 11:53:30 by cmalaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;

	if (*s2 == 0)
		return ((char*)s1);
	i = 0;
	while (s1[i])
	{
		j = 0;
		while (s2[j] && s1[i + j] == s2[j])
			j++;
		if (!s2[j])
			return ((char*)(s1 + i));
		i++;
	}
	return (NULL);
}
