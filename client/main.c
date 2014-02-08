# include "./includes/client.h"

int		main(int argc, char **argv)
{
	if (argc == 3)
		send_str(ft_atoi(argv[1]), argv[2]);
	return (0);
}

void	send_str(int	pid, char *str)
{
	while (*str)
		send_char(pid, *str++);
	send_char(pid, *str);
}

void	send_char(int pid, char c)
{
	int	i;
	int	s;

	i = 8;
	while (i > 0)
	{
		s = c << (i -- -1) == 0 ? SIGUSR1 : SIGUSR2;
		kill(pid, s);
	}
}
