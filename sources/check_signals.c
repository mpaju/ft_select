#include "ft_select.h"

void	interrupt_signal(int num)
{
	printf("CTRL + C\n");
	change_term_mode(1);
	ft_putstr_fd(tgetstr("te", NULL), 2);
	ft_putstr_fd(tgetstr("ve", NULL), 2);
	ft_putstr_fd(tgetstr("se", NULL), 2);
	exit(1);
}

static void	screen_size_test(int num)
{
	struct winsize	window;

	ioctl(0, TIOCGWINSZ, &window);
	printf("new screen size col: %d, row: %d\n", window.ws_col, window.ws_row);
}

void	check_signals(void)
{
	signal(SIGINT, interrupt_signal);
	signal(SIGWINCH, screen_size_test);
}
