/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalaing <cmalaing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:20:43 by cmalaing          #+#    #+#             */
/*   Updated: 2013/11/25 13:34:56 by cmalaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	str = (char*)malloc(sizeof(*str) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str)
	{
		i = 0;
		while (*s1)
		{
			str[i++] = *s1;
			s1++;
		}
		while (*s2)
		{
			str[i++] = *s2;
			s2++;
		}
		str[i] = '\0';
	}
	return (str);
}
