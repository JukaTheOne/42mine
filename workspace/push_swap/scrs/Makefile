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

SRCS			=	push_swap.c lst_manipulation.c sorter.c

OBJS			=	$(SRCS:%.c=%.o)
#OBJS 			= 	$(SRCS:srcs/%.c=$(OBJ_DIR)/%.o)


RANDOM_NUMBERS	:= $(shell shuf -i 1-500 -n 500)

CC					= @cc
RM					= @rm -f
CFLAGS				= -Wall -Wextra -Werror -std=c99
VAL					= -@valgrind --leak-check=full

$/%.o: 	%.cs
					$(CC) $(CFLAGS) -c $< -o $@

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

${CHECK}:		$(BONUS_OBJS)
				$(CC) $(CFLAGS) $(OBJS) -o $(BONUS_NAME)


test:			$(NAME)
				@echo "Number of movements: $$(./push_swap $(RANDOM_NUMBERS) | wc -l)"
				$(VAL) ./push_swap $(RANDOM_NUMBERS) > output.txt 2>&1
				@./push_swap $(RANDOM_NUMBERS)
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
