/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stradd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalaing <cmalaing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/07 10:46:28 by cmalaing          #+#    #+#             */
/*   Updated: 2013/12/07 10:49:42 by cmalaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_stradd(char const *s1, char const *s2)
{
	char	*result;

	result = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (result)
	{
		ft_strcpy(result, s1);
		ft_strcat(result, s2);
	}
	return (result);
}
