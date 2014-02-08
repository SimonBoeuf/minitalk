# include "./includes/server.h"

void	catch_1(int s)
{
	add_bit_to_char(s - SIGUSR1);
}

void	catch_2(int s)
{
	add_bit_to_char(s - SIGUSR2 + 1);
}
