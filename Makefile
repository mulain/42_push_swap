# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wmardin <wmardin@student.42wolfsburg.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/10 21:26:51 by wmardin           #+#    #+#              #
#    Updated: 2022/08/03 11:37:26 by wmardin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

NAME =	push_swap
SRC =	main.c\
		helperfunctions.c\
		algo_slices.c\
		algo_util_calc.c\
		algo_util_check.c\
		algo_util_get.c\
		algo_util_getnode.c\
		do_swap.c do_push.c do_rotate.c do_revrotate.c\
		util_setup.c util_operations.c util_assignrank.c\

NAME2 =	checker
SRC2 =	checker_main.c checker_util.c\
		helperfunctions.c\
		algo_slices.c\
		algo_util_calc.c\
		algo_util_check.c\
		algo_util_get.c\
		algo_util_getnode.c\
		do_swap.c do_push.c do_rotate.c do_revrotate.c\
		util_setup.c util_operations.c util_assignrank.c\

LIBFT = libft/libft.a

$(NAME): $(LIBFT) $(NAME2)
	@$(CC) $(CFLAGS) $(SRC) $(LIBFT) -o $(NAME)
	@echo '$(NAME) created.'

$(LIBFT):
	@make --no-print-directory -C ./libft
	
$(NAME2):
	@$(CC) $(CFLAGS) $(SRC2) $(LIBFT) -o $(NAME2)
	@echo '$(NAME2) created.'
	
all: $(NAME)

clean:
	@$(RM) $(OBJ)
	@echo 'clean performed.'
	
fclean: clean
	@$(RM) $(NAME) $(LIBFT) $(NAME2) a.out
	@echo 'fclean performed.'

re: fclean all

test:
	$(CC) $(CFLAGS) $(SRC) $(LIBFT) -o $(NAME)

testnoflag:
	$(CC) $(SRC) $(LIBFT)