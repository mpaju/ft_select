#include "ft_select.h"

void	interrupt_signal(int num)
{
	printf("CTRL + C\n");
	change_term_mode(1);
	exit(1);
}

void	check_signals(void)
{
	signal(SIGINT, interrupt_signal);
}
