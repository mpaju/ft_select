#include "ft_select.h"

/*
** "cl" - clear the entire screen and put cursor at upper left corner
** "us" - turn on underline mode
** "ue" - turn off undeline mode
** "ti" - initialize terminal for random cursor motion
*/

void	tc_clear_screen(int fd)
{
	ft_putstr_fd(tgetstr("cl", NULL), fd);
}

void	tc_underline_mode_on(int fd)
{
	ft_putstr_fd(tgetstr("us", NULL), fd);
}

void	tc_underline_mode_off(int fd)
{
	ft_putstr_fd(tgetstr("ue", NULL), fd);
}

void	tc_random_cursor_pos(int fd)
{
	ft_putstr_fd(tgetstr("ti", NULL), 2);
}

		// ft_putstr_fd(tgetstr("me", NULL), 2);
	// ft_putstr_fd(tgetstr("so", NULL), 2);
