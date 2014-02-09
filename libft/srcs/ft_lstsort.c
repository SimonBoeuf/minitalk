/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalaing <cmalaing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/06 08:20:42 by cmalaing          #+#    #+#             */
/*   Updated: 2013/12/13 14:39:28 by cmalaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	swap(t_list *parent, t_list *e1, t_list *e2)
{
	t_list	*tmp;

	tmp = e2->next;
	e2->next = e1;
	if (parent)
		parent->next = e2;
	e1->next = tmp;
}

void		ft_lstsort(t_list **lst, int (*f)(t_list*, t_list*))
{
	int		swapped;
	t_list	*elem;
	t_list	*parent;

	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		parent = NULL;
		elem = *lst;
		while (elem && elem->next)
		{
			if (f(elem, elem->next) > 0)
			{
				if (!parent)
					*lst = elem->next;
				swap(parent, elem, elem->next);
				swapped = 1;
			}
			parent = elem;
			elem = elem->next;
		}
	}
}
