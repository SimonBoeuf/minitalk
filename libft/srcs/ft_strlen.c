/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalaing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/17 12:41:24 by cmalaing          #+#    #+#             */
/*   Updated: 2013/11/25 12:43:22 by cmalaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlen(const char *str)
{
	char	*s;

	if (!str)
		return (0);
	s = (char*)str;
	while (*s)
		s++;
	return (s - str);
}
