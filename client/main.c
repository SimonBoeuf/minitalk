# include "./includes/client.h"
#include <unistd.h>

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

void	send_str(int	pid, char *str)
{
	struct sigaction	*act;

	act = (struct sigaction *)ft_memalloc(sizeof(*act));
	act->sa_handler = &check;
	sigaction(SIGUSR1, act, NULL);
	sigaction(SIGUSR2, act, NULL);
	while (*str)
	{
		if(!send_char(pid, *str))
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
		usleep(100);
		s = ((c >> i--) & 1 ? SIGUSR2 : SIGUSR1);
		kill(pid, s);
	}
	usleep(1000);
	s = (parity ? SIGUSR2 : SIGUSR1);
	if (g_parity == s)
		return (0);
	else
	{
		write(1, "hey\n", 4);
		g_parity = 0;
		return (1);
	}
}
