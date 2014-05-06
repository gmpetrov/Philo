# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/15 00:09:57 by ebaudet           #+#    #+#              #
#    Updated: 2014/05/06 20:14:41 by gpetrov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo
FILES	= main.c
SRCS	= $(addprefix srcs/, $(FILES))
OBJS	= $(SRCS:srcs/%.c=.obj/%.o)
INC		= -I includes -I libft/includes
FLAGS	= -Wall -Wextra -Werror
LIB		= -L libft -lft
LIBMLX	= -L /usr/X11/lib -lmlx -lXext -lX11
CC		= cc

all: $(NAME)

$(NAME): libft_comp create_fold_obj $(OBJS)
	@$(CC) $(FLAGS) $(SRCS) -o $(NAME) $(INC) $(LIB) $(LIBMLX)
	@echo "\n > \033[36m$(NAME)\033[m project compilation [\033[32mDONE\033[m]\n"

.obj/%.o: srcs/%.c
	@$(CC) -c $< -o $@ $(FLAGS) $(INC)
	@echo -n .

libft_comp:
	@make -C libft

create_fold_obj:
	@mkdir -p .obj

clean:
	@rm -rf .obj

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)
	@echo "fclean : [\033[32mDONE\033[m]"

re: fclean all

gdb: libft_comp
	cc -g $(FLAGS) $(SRCS) -o $(NAME) $(INC) $(LIB) $(LIBMLX)
	gdb $(NAME)

.PHONY: all libft_comp create_fold_obj clean fclean re
