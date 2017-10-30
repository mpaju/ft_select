# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpaju <mpaju@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/17 17:18:15 by mpaju             #+#    #+#              #
#    Updated: 2017/10/30 11:43:34 by mpaju            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	ft_select
UNAME		=	Select

CC			=	gcc
FLAGS		=	# -Wall -Wextra -Werror

SRC_DIR		=	sources
FILES		=	main.c \
				check_signals.c \
				change_term_mode.c \
				get_input.c \
				display.c \

SRCS		=	$(addprefix $(SRC_DIR)/, $(FILES))

HEAD_DIR	=	includes
HEAD		=	fractol.h
HEAD_FILES	=	$(addprefix $(HEAD_DIR)/, $(HEAD))
LIBFT_HEAD	=	-Ilibft/includes/
HEAD_LINK	=	-I
HEAD_LOC	=	$(addprefix $(HEAD_LINK), $(HEAD_DIR))

OBJ_DIR		=	objects
OBJ_FILES	=	$(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))
OBJ_DIRS	=	$(sort $(dir $(OBJ_FILES)))

LIB			=	libft/libft.a
LIBS		=	libft libmlx
LIBFT_DIR	=	libft/
MYLIB		=	-L./libft -lft
TERM_LIB	=	-ltermcap

all: build $(NAME)

$(NAME): $(LIB) $(OBJ_FILES)
	@$(CC) -o $@ $^ -g $(MYLIB) $(TERM_LIB)
	@echo "\033[0;37m$(UNAME) make all done\033[0;38m"

build:
	@mkdir -p $(OBJ_DIRS)

$(LIB):
	@make -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(FLAGS) $(HEAD_LOC) $(LIBFT_HEAD) -c -o $@ $< -g

clean:
	@make clean -C $(LIBFT_DIR)
	@rm -f $(OBJ_FILES)
	@echo "\033[0;33m$(UNAME) make clean done\033[0;38m"

fclean:
	@make fclean -C $(LIBFT_DIR)
	@rm -rf $(OBJ_DIR)
	@rm -f $(NAME)
	@echo "\033[0;34m$(UNAME) make fclean done\033[0;38m"

re: fclean all
	@echo "\033[0;36m$(UNAME) make re done\033[0;38m"

.PHONY: re fclean clean deb all
