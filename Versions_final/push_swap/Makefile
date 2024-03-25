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

NAME			:= push_swap
BONUS_NAME		:= checker

RANDOM_NUMBERS	:= $(shell shuf -i 1-500 -n 500)
#RANDOM_NUMBERS	:= "1 2 4 6" "3123 23 13"

CC := @cc
RM := -@rm -f
CFLAGS := -Wall -Wextra -Werror -std=c99
VAL := valgrind --leak-check=full --show-leak-kinds=all -s

OBJ_DIR := obj
INCLUDES_DIR := includes

SRCS := srcs/ft_sorter.c\
srcs/ft_push_swap.c\
srcs/ft_sorter_utils.c\
srcs/list_moves/ft_lst_moves_rot.c\
srcs/list_moves/ft_lst_moves_push.c\
srcs/list_moves/ft_lst_moves_revrot.c\
srcs/list_moves/ft_lst_moves_swap.c\
srcs/utils/ft_lst_general_utils.c\
srcs/utils/ft_general_utils.c\
srcs/utils/ft_split.c\

BONUS := bonus/ft_gnl.c\
bonus/bonus.c\
bonus/list_moves/ft_lst_moves_rot.c\
bonus/list_moves/ft_lst_moves_push.c\
bonus/list_moves/ft_lst_moves_revrot.c\
bonus/list_moves/ft_lst_moves_swap.c\
bonus/utils/ft_lst_general_utils.c\
bonus/utils/ft_general_utils.c\
bonus/utils/ft_split.c\

OBJS := $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
OBJ_BONUS := $(addprefix $(OBJ_DIR)/, $(BONUS:.c=.o))

all:	$(NAME) bonus

$(OBJ_DIR)/%.o:	%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I $(INCLUDES_DIR) -c $< -o $@

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus:	$(BONUS_NAME)

$(BONUS_NAME):	$(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(BONUS_NAME)

test:	re
	@echo "<Teste sorter>"
	@echo $(RANDOM_NUMBERS) > random_numbers.txt
	@echo "//Number of movements: $$(./$(NAME) "$$(cat random_numbers.txt)" | tee output.txt | wc -l)"
	-@$(VAL) --leak-check=full --show-leak-kinds=all -s ./$(NAME) "$$(cat random_numbers.txt)" > output2.txt 2>&1
	@grep "total heap usage" output2.txt
#	@awk '/HEAP SUMMARY:/ {flag=1} flag' output2.txt
	@echo "________________________________________________________________________________\n"
	@echo "<Teste checker>"
	@ARG=$$(cat random_numbers.txt); ./push_swap $$ARG | ./checker $$ARG > output.txt 2>&1
	@echo "//checker result: $$(cat output.txt)"
	-@ARG=$$(cat random_numbers.txt); $(VAL) ./push_swap $$ARG 2>&1 | $(VAL) ./checker $$ARG > output2.txt 2>&1
	@grep "total heap usage" output2.txt
#	@awk '/HEAP SUMMARY:/ {flag=1} flag' output.txt
	@echo "________________________________________________________________________________\n"
	@echo "<Teste Norminette>"
	@norminette -R CheckDefine . | awk '/Error/'
	@echo "\n"
	$(RM) output.txt output2.txt random_numbers.txt
	@$(MAKE) -s fclean

clean:
	$(RM) -rf $(OBJ_DIR)
	@echo "Objects removed"

fclean:	clean
	$(RM) $(NAME) $(BONUS_NAME)
	@echo "Executable removed"

re:	fclean all

PHONY:	all $(NAME) bonus test debug clean fclean re