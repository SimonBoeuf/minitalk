#ifndef _SERVER_H_
# define _SERVER_H_

# include <sys/types.h>
# include <unistd.h>
# include <signal.h>
# include "../../libft/includes/libft.h"

void	display_pid(void);
void	launch_server(void);

void	catch_1(int s, siginfo_t *info, void *context);
void	catch_2(int s, siginfo_t *info, void *context);

void	add_bit_to_char(pid_t pid, char bit);
void	add_char_to_string(char c);

#endif
