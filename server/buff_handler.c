# include "./includes/server.h"
#include <stdlib.h>

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

	reference = (c & 128) >> 7;
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
	static t_list	*lst = NULL;
	t_list			*tmp;

	if (c != 0)
		ft_lstaddlast(&lst, ft_lstnew(&c, sizeof(char*)));
	else
	{
		while (lst)
		{
			c = *((char*)lst->content);
			write(1, &c, 1);
			tmp = lst;
			lst = lst->next;
			free(tmp->content);
			free(tmp);
			tmp = NULL;
		}
		write(1, "\n", 1);
	}
}
