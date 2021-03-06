/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalaing <cmalaing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 11:30:28 by cmalaing          #+#    #+#             */
/*   Updated: 2014/01/09 08:23:54 by cmalaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	nblen(int n)
{
	if (n < 0)
		return (1 + nblen(-n));
	if (n < 10)
		return (1);
	return (1 + nblen(n / 10));
}

char		*ft_itoa(int n)
{
	int		len;
	int		neg;
	int		i;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	neg = (n < 0 ? 1 : 0);
	len = nblen(n);
	str = (char*)malloc(sizeof(*str) * (len + 1));
	if (str)
	{
		n = (n < 0 ? -n : n);
		i = len - 1;
		while (i >= neg)
		{
			str[i] = (n % 10) + 48;
			n /= 10;
			i--;
		}
		if (neg)
			str[0] = '-';
		str[len] = '\0';
	}
	return (str);
}
