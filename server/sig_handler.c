# include "./includes/server.h"

int	g_pid;

void	catch(int s, siginfo_t *info, void *context)
{
	pid_t				pid;
	struct sigaction	*act;

	act = (struct sigaction *)ft_memalloc(sizeof(*act));
	act->sa_flags |= SA_SIGINFO;
	act->sa_sigaction = &catch;
	(void)context;
	pid = info->si_pid;
	if (s == SIGUSR1)
		add_bit_to_char(0);
	else if (s == SIGUSR2)
		add_bit_to_char(1);
	sigaction(SIGUSR1, act, NULL);
	sigaction(SIGUSR2, act, NULL);
	g_pid = pid;
}
