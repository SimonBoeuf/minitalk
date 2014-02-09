/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalaing <cmalaing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/05 15:45:38 by cmalaing          #+#    #+#             */
/*   Updated: 2013/12/13 16:38:14 by cmalaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstrev(t_list **lst)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!lst || !*lst)
		return ;
	tmp = NULL;
	while (*lst)
	{
		tmp2 = (*lst)->next;
		(*lst)->next = tmp;
		tmp = *lst;
		*lst = tmp2;
	}
	*lst = tmp;
}
