#include "ft_select.h"

// clear_screen();
// refresh_screen();

static void			set_window_size(t_env *e)
{
	struct winsize	window;

	ioctl(0, TIOCGWINSZ, &window);
	e->width = window.ws_col;
	e->height = window.ws_row;
}

void	display(t_env *e)
{
	set_window_size(e);
	printf("winx: %d, winy: %d\n", e->width, e->height);
	printf("screenheight: %d\n", tgetnum("li"));
	// ft_putstr_fd(tgetstr("ce", NULL), 2);
	// ft_putstr_fd(tgetstr("cl", NULL), 2);
	return ;
}
