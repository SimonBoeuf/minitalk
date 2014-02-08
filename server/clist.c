# include "./includes/server.h"

t_clist	*clist_new(char c)
{
	t_clist	*list;

	list = (t_clist*)malloc(sizeof(t_clist));
	list->c = c;
	list->next = NULL;
	return (list);
}

void	clist_add(t_clist *list, char c)
{
	t_clist *new_elm;

	new_elm = clist_new(c);
	while (list->next != NULL)
		list = list->next;
	list->next = new_elm;
}

void	clist_print(t_clist *list)
{
	while (list != NULL)
	{
		write (1, &list->c, 1);
		list = list->next;
	}
	write (1, "\n", 1);
}

void	clist_del(t_clist *list)
{
	t_clist	*tmp;

	while (list != NULL)
	{
		tmp = list->next;
		free (list);
		list = tmp;
	}
}
