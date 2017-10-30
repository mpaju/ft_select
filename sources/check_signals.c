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

void	check_signals(void)
{
	signal(SIGINT, interrupt_signal);
}
