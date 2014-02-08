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
	static char *s = NULL;
	char		*tmp;

	if (s == NULL)
	{
		s = (char*)malloc(2);
		s[0] = c;
		s[1] = 0;
	}
	else
	{
		if (c == 0)
		{
			ft_putendl(s);
			s = NULL;
		}
		else
		{
			tmp = s;
			s = (char*)malloc(ft_strlen(s) + 2);
			s = ft_strcpy(s, tmp);
			s[ft_strlen(tmp)] = c;
			s[ft_strlen(tmp) + 1] = 0;
		}
	}
}
