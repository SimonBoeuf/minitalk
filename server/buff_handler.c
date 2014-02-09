# include "./includes/server.h"

int		calc_parity_bit(char c)
{
	int		bit;
	int		i;

	i = 6;
	bit = 0;
	while (i >= 0)
		bit ^= ((c >> i--) & 1);
	return (bit);
}

int		check_parity(char c)
{
	int		calc;
	int		reference;

	reference = (c & 128) && 1;
	calc = calc_parity_bit(c);
	return (reference == calc);
}

void	add_bit_to_char(pid_t pid, char bit)
{
	static unsigned char	byte = 0;
	static int				size = 0;
	int						s;

	byte = byte << 1;
	byte += bit;
	if (++size == 8)
	{
		if (check_parity(byte))
		{
			byte &= 127;
			add_char_to_string(byte);
		}
		s = calc_parity_bit(byte);
		s = (s ? SIGUSR2 : SIGUSR1);
		byte = 0;
		size = 0;
		kill(pid, s);
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
			ft_stredel(&s);
		}
		else
		{
			tmp = s;
			s = (char*)malloc(ft_strlen(s) + 2);
			s = ft_strcpy(s, tmp);
			s[ft_strlen(tmp)] = c;
			s[ft_strlen(tmp) + 1] = 0;
			ft_stredel(&tmp);
		}
	}
}
