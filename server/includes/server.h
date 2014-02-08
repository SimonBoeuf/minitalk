#ifndef _SERVER_H_
# define _SERVER_H_

# include <sys/types.h>
# include <unistd.h>
# include <signal.h>
# include "../../libft/includes/libft.h"

void	display_pid(void);
void	launch_server(void);

void	catch_1(int s);
void	catch_2(int s);

void	add_bit_to_char(char bit);
void	add_char_to_string(char c);

#endif
