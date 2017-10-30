#include "ft_select.h"

static void	check_tty(void)
{
	if (!isatty(STDIN_FILENO))
	{
		ft_putendl_fd("ft_select: Error: Not a terminal", 2);
		exit(1);
	}
}

static t_env	*init_env(t_env *e)
{
	char	*termname;

	if (!(e = (t_env *)ft_memalloc(sizeof(t_env))))
		exit(1);
	change_term_mode(0);
	termname = getenv("TERM");
	if ((tgetent(NULL, termname) <= 0))
	{
		ft_putendl_fd("ft_select : tgetent : Error accessing the data base", 2);
		exit(1);
	}
	return (e);
}

int main(int ac, char **av)
{
	t_env 	*e;
	int 	tmp;

	e = NULL;
	// check_args();
	check_tty();
	e = init_env(e);
	check_signals();
	display(e);
	get_input(e);

	while (1)
		;
	return 0;
}
