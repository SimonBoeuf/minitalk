/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboeuf <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 16:37:27 by sboeuf            #+#    #+#             */
/*   Updated: 2014/02/09 16:38:28 by sboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/server.h"

int		main(void)
{
	display_pid();
	launch_server();
	return (0);
}

void	display_pid(void)
{
	ft_putnbr(getpid());
	ft_putendl("");
}

void	launch_server(void)
{
	struct sigaction	*act1;
	struct sigaction	*act2;

	act1 = (struct sigaction *)ft_memalloc(sizeof(*act1));
	act1->sa_flags |= SA_SIGINFO;
	act1->sa_sigaction = &catch_1;
	sigaction(SIGUSR1, act1, NULL);
	act2 = (struct sigaction *)ft_memalloc(sizeof(*act2));
	act2->sa_flags |= SA_SIGINFO;
	act2->sa_sigaction = &catch_2;
	sigaction(SIGUSR2, act2, NULL);
	while (1)
	{
	}
	ft_putendl("Server has died");
}
