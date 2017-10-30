#include "ft_select.h"

// clear_screen();
// refresh_screen();

static void			get_window_size(t_env *e)
{
	struct winsize	window;

	ioctl(0, TIOCGWINSZ, &window);
	e->width = window.ws_col;
	e->height = window.ws_row;
}

static void	print_current_arg(t_args *curr)
{
	ft_putendl_fd(curr->name, 2);
	// if (curr->selected)
}

void	print_args(t_env *e)
{
	t_args	*curr;

	curr = e->args;
	while (curr)
	{
		print_current_arg(curr);
		curr = curr->next;
	}
}

void	display(t_env *e)
{
	delete_active(e);
	tc_clear_screen(2);
	ft_putstr_fd(tgetstr("so", NULL), 2);
	print_args(e);
	return ;
}
