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

void	display(t_env *e)
{
	delete_active(e);
	return ;
}
