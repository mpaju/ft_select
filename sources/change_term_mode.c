#include "ft_select.h"

void	change_term_mode(int restore)
{
	struct termios			newt;
	static struct termios	oldt;

	if (restore == 0)
	{
		tcgetattr(STDIN_FILENO, &oldt);
		tcgetattr(STDIN_FILENO, &newt);
		// newt = e->term->newt;
		newt.c_lflag &= ~(ICANON | ECHO);
		newt.c_cc[VMIN] = 1;
		newt.c_cc[VTIME] = 0;
		tcsetattr(STDIN_FILENO, TCSADRAIN, &newt);
	}
	else
	{
		tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
		ft_putendl("b2n");
	}
}
