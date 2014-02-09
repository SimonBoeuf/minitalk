# include "./includes/server.h"

void	catch_1(int s, siginfo_t *info, void *context)
{
	pid_t	pid;

	(void)context;
	pid = info->si_pid;
	add_bit_to_char(pid, s - SIGUSR1);
}

void	catch_2(int s, siginfo_t *info, void *context)
{
	pid_t	pid;

	(void)context;
	pid = info->si_pid;
	add_bit_to_char(pid, s - SIGUSR2 + 1);
}
