#include "ft_select.h"

void	parse_keys(t_env *e, unsigned int key)
{
	if (key == ESC_KEY)
		// exit
		printf("exit prog\n");
}

void	get_input(t_env *e)
{
	unsigned int key;

	ft_bzero(&key, sizeof(unsigned int));
	while((read(0, &key, sizeof(unsigned int))) != 0)
	{
		printf("char: %c, key: %d\n",(char)key, key);
		parse_keys(e, key);
		// key = 0;
		ft_bzero(&key, sizeof(unsigned int));
	}

}
