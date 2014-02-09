/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdupone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalaing <cmalaing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 08:58:34 by cmalaing          #+#    #+#             */
/*   Updated: 2013/11/26 09:03:15 by cmalaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstdupone(t_list *elem)
{
	t_list	*new;

	new = ft_lstnew(elem->content, elem->content_size);
	new->next = elem->next;
	return (new);
}
