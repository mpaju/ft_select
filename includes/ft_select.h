/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaju <mpaju@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 14:15:51 by mpaju             #+#    #+#             */
/*   Updated: 2017/10/30 16:14:32 by mpaju            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
#define FT_SELECT_H

#include "libft.h"

#include <signal.h>
#include <termios.h>
#include <termcap.h>
#include <term.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <wchar.h>
#include <limits.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>

#define ESC_KEY 27
#define UP_KEY 4283163
#define LEFT_KEY 4479771
#define DOWN_KEY 4348699
#define RIGHT_KEY 4414235

typedef struct		s_args
{
	int		pos;
	char	*name;
	int		highlight;
	int		active;
	struct s_args	*next;
}					t_args;

typedef struct		s_env
{
	int 			width;
	int 			height;
	struct s_args	*args;
}					t_env;

void	change_term_mode(int restore);
void	check_signals(void);
void	delete_active(t_env *e);
void	display(t_env *e);
void	get_input(t_env *e);

void	tc_clear_screen(int fd);
void	tc_underline_mode_on(int fd);
void	tc_underline_mode_off(int fd);
void	tc_random_cursor_pos(int fd);


#endif
