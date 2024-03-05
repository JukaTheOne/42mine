# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/16 21:06:41 by fandre-b          #+#    #+#              #
#    Updated: 2024/02/16 21:06:41 by fandre-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap
BONUS_NAME		= checker

OBJ_DIR			= ./obj

SRCS			=	utils_general.c utils_list_general.c utils_list_manipularion.c \
					push_swap.c list_movements/push_top.c list_movements/rotate.c \
					list_movements/rev_rotate.c list_movements/swap.c ft_sorter.c utils_sorter.c 

OBJ_W_DIR		=	$(addprefix srcs/,$(SRCS))

OBJS			=	$(SRCS:%.c=$(OBJ_W_DIR)/%.o)
#OBJS 			= 	$(SRCS:srcs/%.c=$(OBJ_DIR)/%.o)


RANDOM_NUMBERS	:= $(shell shuf -i 1-500 -n 500)

CC					= @cc
RM					= @rm -f
CFLAGS				= -Wall -Wextra -Werror -std=c99
VAL					= -@valgrind --leak-check=full

$(OBJ_DIR)/%.o: 	%.c
		mkdir -p 	$(OBJ_DIR) list_movements
					$(CC) $(CFLAGS) -c $< -o $@

all:			$(NAME)

$(NAME):		$(OBJS_DIR)

				$(CC) $(CFLAGS) $(OBJ_W_DIR) -o $(NAME)

${CHECK}:		$(BONUS_OBJS)
				$(CC) $(CFLAGS) $(OBJS) -o $(BONUS_NAME)


test:			$(NAME)
				@echo "Number of movements: $$(./push_swap $(RANDOM_NUMBERS) | wc -l)"
				$(VAL) ./push_swap $(RANDOM_NUMBERS) > output.txt 2>&1
				./push_swap $(RANDOM_NUMBERS)
				@grep -B 2 "HEAP SUMMARY" output.txt | awk 'NR==1'
				@grep "total heap usage" output.txt
				@grep -A 2 "total heap usage" output.txt | tail -n 1
				$(RM) output.txt
				$(MAKE) fclean
			
debug:
				@gcc -g $(CFLAGS) -o $(NAME) $(OBJS)
				@gdb ./push_swap
				$(MAKE) fclean

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all test settest debug clean fclean re
