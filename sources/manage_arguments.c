#include "ft_select.h"

/*
**	searches for the current argument and deletes it while assigning active
**	status to the next argument
*/

void	delete_active(t_env *e)
{
	t_args	**curr;
	t_args	*tmp;

	curr = &e->args;
	while (*curr)
	{
		if ((*curr)->active == 1)
		{
			tmp = *curr;
			*curr = (*curr)->next;
			// need to think about the logic here
			if (*curr == NULL)
				e->args->active = 1;
			else
				(*curr)->active = 1;
			ft_strdel(&tmp->name);
			free(tmp);
			return ;
		}
		curr = &(*curr)->next;
	}
	ft_putendl_fd("no active node available", 2);
}
