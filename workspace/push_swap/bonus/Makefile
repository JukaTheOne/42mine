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

SRCS			=	ft_split.c bonus.c ft_gnl.c ft_lst_general_utils.c ft_lst_moves_push.c ft_lst_moves_revrot.c ft_lst_moves_rot.c ft_lst_moves_swap.c ft_general_utils.c

OBJS			=	$(SRCS:%.c=%.o)
#OBJS 			= 	$(SRCS:srcs/%.c=$(OBJ_DIR)/%.o)


RANDOM_NUMBERS	:= $(shell seq -250 250 | shuf -n 500)
SET_NUMBERS		=

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
