/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboeuf <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 16:40:26 by sboeuf            #+#    #+#             */
/*   Updated: 2014/02/09 16:40:27 by sboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/client.h"

volatile sig_atomic_t	g_parity;

int		main(int argc, char **argv)
{
	if (argc == 3)
		send_str(ft_atoi(argv[1]), argv[2]);
	return (0);
}

void	check(int s)
{
	g_parity = s;
}

void	send_str(int pid, char *str)
{
	struct sigaction	*act;

	act = (struct sigaction *)ft_memalloc(sizeof(*act));
	act->sa_handler = &check;
	sigaction(SIGUSR1, act, NULL);
	sigaction(SIGUSR2, act, NULL);
	while (*str)
	{
		if (!send_char(pid, *str))
			str++;
	}
	send_char(pid, *str);
}

int		calc_parity_bit(char c)
{
	int		bit;
	int		i;

	i = 6;
	bit = 0;
	while (i >= 0)
		bit ^= ((c >> i--) & 1);
	return (bit);
}

int		send_char(int pid, char c)
{
	int		i;
	int		s;
	int		parity;

	parity = calc_parity_bit(c);
	s = (parity ? SIGUSR2 : SIGUSR1);
	kill(pid, s);
	i = 6;
	while (i >= 0)
	{
		usleep(50);
		s = ((c >> i--) & 1 ? SIGUSR2 : SIGUSR1);
		kill(pid, s);
	}
	if (usleep(500) == -1)
	{
		s = (parity ? SIGUSR2 : SIGUSR1);
		if (g_parity != s)
		{
			ft_putendl("An error has occured, deal with it ! (^_^)");
			g_parity = 0;
		}
		return (g_parity == s ? 0 : 1);
	}
	return (1);
}
