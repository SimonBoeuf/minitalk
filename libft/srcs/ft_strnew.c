/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalaing <cmalaing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 09:22:20 by cmalaing          #+#    #+#             */
/*   Updated: 2013/12/01 15:52:17 by cmalaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*ptr;

	ptr = (char*)malloc(size + 1);
	if (ptr)
		ft_bzero(ptr, size + 1);
	return (ptr);
}
