# include "./includes/server.h"

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
	while(1);
}
