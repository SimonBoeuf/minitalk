# include "./includes/server.h"

int		g_pid;

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
	struct sigaction	*act;

	act = (struct sigaction *)ft_memalloc(sizeof(*act));
	act->sa_flags |= SA_SIGINFO;
	act->sa_sigaction = &catch;
	sigaction(SIGUSR1, act, NULL);
	sigaction(SIGUSR2, act, NULL);
	g_pid = 0;
	while(1)
	{
		if (g_pid)
		{
			usleep(1);
			kill(g_pid, SIGUSR1);
			g_pid = 0;
		}
	}
}
