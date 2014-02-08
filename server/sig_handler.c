# include "./includes/server.h"

void	catch(int s, siginfo_t *info, void *context)
{
	pid_t	pid;

	(void)context;
	pid = info->si_pid;
	add_bit_to_char(s == SIGUSR1 ? 0 : 1);
	kill(pid, s);
}
