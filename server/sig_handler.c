# include "./includes/server.h"

void	catch(int s, siginfo_t *info, void *context)
{
	pid_t	pid;

	(void)context;
	pid = info->si_pid;
	if (s == SIGUSR1)
		add_bit_to_char(0);
	else if (s == SIGUSR2)
		add_bit_to_char(1);
	kill(pid, s);
}
