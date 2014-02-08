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
	signal(SIGUSR1, catch_1);
	signal(SIGUSR2, catch_2);
	while(1);
}
