# include "./includes/server.h"

void	add_bit_to_char(char bit)
{
	static char	byte = 0;
	static int	size = 0;

	byte <<= 1;
	byte += bit;
	if (++size == 8)
	{
		if (byte == 0)
			ft_putendl("");
		else
			ft_putchar(byte);
		size = 0;
	}
}
