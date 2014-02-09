/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalaing <cmalaing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 14:38:56 by cmalaing          #+#    #+#             */
/*   Updated: 2013/11/21 14:48:24 by cmalaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		i;

	i = 0;
	str = NULL;
	while (s[i])
	{
		if (s[i] == (char)c)
			str = (char*)s + i;
		i++;
	}
	if (c == 0)
		return ((char*)s + i);
	return (str);
}
