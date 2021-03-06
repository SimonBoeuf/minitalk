/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalaing <cmalaing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 05:27:06 by cmalaing          #+#    #+#             */
/*   Updated: 2014/01/02 05:28:07 by cmalaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_pow(int nb, int exp)
{
	if (exp <= 0)
		return (1);
	else
		return (nb * (ft_pow(nb, exp - 1)));
}
