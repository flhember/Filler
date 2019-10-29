# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flhember <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/16 09:29:06 by flhember          #+#    #+#              #
#    Updated: 2019/10/29 16:23:41 by flhember         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = flhember.filler
COMP = clang
FLAGS = -Wall -Wextra -Werror

SRC_PATH = ./srcs/
OBJ_PATH = ./obj/
LIB_PATH = ./libft/
INC_PATH = ./includes/

SRC_FILES = main.c				\
			ft_filler.c			\
			ft_get_map_piece.c	\
			ft_resolv.c			\
			ft_check_touch.c	\
			ft_catch_him.c		\
			ft_catch_up.c		\
			ft_catch_down.c		\
			ft_get_data.c		\
			ft_put_piece.c		\
			ft_reduce_piece.c	\
			ft_block.c

INC = ft_filler.h
LIB_FILES = libft.a

LIB = $(addprefix $(LIB_PATH), $(LIB_FILES))
LIB_HEADER = $(addprefix $(LIB_PATH), $(INC_PATH))

INC_FILES = $(addprefix $(INC_PATH), $(INC))
OBJ_FILES = $(SRC_FILES:.c=.o)
	OBJ_EXEC = $(addprefix $(OBJ_PATH), $(OBJ_FILES))

all: $(NAME)

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(FLAGS) -c -I $(INC_PATH) -I$(LIB_HEADER) $< -o $@
	echo "\033[40mCompilation of \033[1m$(notdir $<)\033[0m \033[32mdone.\033[0m"

$(LIB): .FORCE
	make -C $(LIB_PATH)

$(NAME): $(INC_FILES) $(LIB) $(OBJ_PATH) $(OBJ_EXEC)
	$(CC) $(FLAGS) $(OBJ_EXEC) $(LIB) -o $(NAME) -I $(INC_PATH) -I $(LIB_HEADER)
	echo "\033[1;32m$(notdir $(NAME))\033[1;0m\033[32m created.\033[0m"

clean:
	/bin/rm -rf $(OBJ_PATH) $(DEPS)
	make clean -C $(LIB_PATH)
	echo "\033[31mObjects files of \033[1;31m$(notdir $(NAME))\033[1;0m\033[31m removed.\033[0m"

fclean: clean
	/bin/rm -rf $(NAME)
	make fclean -C $(LIB_PATH)
	echo "\033[1;31m$(notdir $(NAME))\033[1;0m\033[31m removed.\033[0m"

re: fclean all

.SILENT:
.FORCE:
.PHONY: clean, fclean, all, re
