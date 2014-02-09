#ifndef _CLIENT_H_
# define _CLIENT_H_

# include <sys/types.h>
# include <signal.h>
# include "../../libft/libft.h"

void	send_str(int pid, char *str);
int		send_char(int pid, char c);

#endif
