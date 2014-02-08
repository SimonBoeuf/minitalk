# include "./includes/client.h"
#include <unistd.h>

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

void	check(int s)
{
	(void)s;
}

void	send_char(int pid, char c)
{
	int					i;
	int					s;

	signal(SIGUSR1, check);
	signal(SIGUSR2, check);
	i = 7;
	while (i >= 0)
	{
		s = ((c >> i--) & 1 ? SIGUSR2 : SIGUSR1);
		kill(pid, s);
		pause();
	}
}
