/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalaing <cmalaing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 13:22:46 by cmalaing          #+#    #+#             */
/*   Updated: 2013/12/10 12:07:52 by cmalaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	unsigned char	*str;

	if (!s1 || !s2)
		return (NULL);
	str = (unsigned char*)malloc(sizeof(*str) * n);
	ft_memcpy(str, s2, n);
	ft_memcpy(s1, str, n);
	free(str);
	return (s1);
}
