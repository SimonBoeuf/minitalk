/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnumlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clement <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/11 11:54:56 by clement           #+#    #+#             */
/*   Updated: 2013/12/11 11:57:18 by clement          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns the length of a positive number.
*/

int		ft_getnumlen(int nb)
{
	if (nb < 10)
		return (1);
	return (1 + ft_getnumlen(nb / 10));
}
