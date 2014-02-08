#ifndef _SERVER_H_
# define _SERVER_H_

# include <sys/types.h>
# include <unistd.h>
# include <signal.h>
# include "../../libft/includes/libft.h"

typedef struct	s_clist
{
	char			c;
	struct s_clist	*next;
}				t_clist;

void	display_pid(void);
void	launch_server(void);

void	catch(int s, siginfo_t *info, void *context);

void	add_bit_to_char(char bit);
void	add_char_to_string(char c);

t_clist	*clist_new(char c);
void	clist_add(t_clist *list, char c);
void	clist_print(t_clist *list);
void	clist_del(t_clist *list);

extern int	g_pid;

#endif
