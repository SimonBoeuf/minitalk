/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalaing <cmalaing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 10:42:38 by cmalaing          #+#    #+#             */
/*   Updated: 2013/11/24 10:24:53 by cmalaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *s)
{
	int		power_of_ten;
	int		result;
	int		neg;
	int		i;

	while (*s == '\n' || *s == '\t' || *s == ' ' || *s == '\f' || *s == '\r'
	|| *s == '\v')
		s++;
	power_of_ten = 1;
	result = 0;
	neg = (*s == '-' ? 1 : 0);
	s = (*s == '+' || *s == '-' ? s + 1 : s);
	i = 0;
	while (ft_isdigit(s[i]))
		i++;
	i--;
	while (i >= 0 && ft_isdigit(s[i]))
	{
		result += (s[i] - 48) * power_of_ten;
		power_of_ten *= 10;
		i--;
	}
	if (neg)
		result *= -1;
	return (result);
}
