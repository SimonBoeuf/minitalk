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

void	check(int s, siginfo_t *info, void *context)
{
	(void)s;
	(void)info;
	(void)context;
}

void	send_char(int pid, char c)
{
	int					i;
	int					s;
	struct sigaction	*act;

	act = (struct sigaction *)ft_memalloc(sizeof(*act));
	act->sa_flags |= SA_SIGINFO;
	act->sa_sigaction = &check;
	sigaction(SIGUSR1, act, NULL);
	sigaction(SIGUSR2, act, NULL);
	i = 7;
	while (i >= 0)
	{
		s = ((c >> i--) & 1 ? SIGUSR2 : SIGUSR1);
		kill(pid, s);
		pause();
	}
}
