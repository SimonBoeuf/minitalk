# include "./includes/server.h"

void	add_bit_to_char(char bit)
{
	static char	byte = 0;
	static int	size = 0;

	byte <<= 1;
	byte += bit;
	if (++size == 8)
	{
		add_char_to_string(byte);
		size = 0;
	}
}

void	add_char_to_string(char c)
{
	static t_clist	*string = NULL;

	if (string == NULL)
		string = clist_new(c);
	else
		clist_add(string, c);
	if (c == 0)
	{
		clist_print(string);
		clist_del(string);
		string = NULL;
	}
}
