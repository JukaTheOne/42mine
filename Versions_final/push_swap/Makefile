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

#TODO Adicionar os vddrs ficheiros.
#TODO reordenar header functions pelos ficheiros.
#TODO adicionar static qd nao usamos fora do scope.
#TODO arranjar test e debug rules.
NAME			= push_swap
BONUS_NAME		= checker

# RANDOM_NUMBERS	:= $(shell shuf -i 1-500 -n 500)
RANDOM_NUMBERS	:= "1 2 4 6" "3123 23 13"

CC = @cc
RM = @rm -f
CFLAGS = -Wall -Wextra -Werror -std=c99
VAL = -@valgrind --leak-check=full

OBJ_DIR = obj
INCLUDES_DIR = includes

SRCS_DIR = srcs
CHECK_DIR = bonus
UTILS_DIR = utils
MOV_DIR = list_moves

SRCS_PUSH =	ft_push_swap.c ft_sorter.c ft_sorter_utils.c
SRCS_CHECK = bonus.c ft_gnl.c
SRCS_UTILS = ft_split.c ft_lst_general_utils.c ft_general_utils.c
SRCS_MOVS = ft_lst_moves_push.c ft_lst_moves_revrot.c ft_lst_moves_rot.c ft_lst_moves_swap.c

SRCS_UTILS_DIR = $(addprefix $(UTILS_DIR)/,$(SRCS_UTILS))
SRCS_MOVS_DIR = $(addprefix $(MOV_DIR)/,$(SRCS_MOVS))

SRCS = $(SRCS_PUSH) $(SRCS_UTILS_DIR) $(SRCS_MOVS_DIR)
SRCS_BONUS = $(SRCS_CHECK) $(SRCS_UTILS_DIR) $(SRCS_MOVS_DIR) 

OBJS = $(addprefix $(OBJ_DIR)/$(SRCS_DIR)/,$(SRCS:%.c=%.o))
OBJ_BONUS  = $(addprefix $(OBJ_DIR)/$(CHECK_DIR)/,$(SRCS_BONUS:%.c=%.o))

 $(OBJ_DIR)/$(SRCS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(dir $(OBJS))
	$(CC) $(CFLAGS) -I $(INCLUDES_DIR) -c $< -o $@

$(OBJ_DIR)/$(CHECK_DIR)/%.o: $(CHECK_DIR)/%.c
	@mkdir -p $(dir $(OBJ_BONUS))
	$(CC) $(CFLAGS) -I $(INCLUDES_DIR) -c $< -o $@

all: $(NAME) bonus

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(BONUS_NAME)

test: $(NAME) bonus
	@echo "<Teste sorter>"
	@echo "//Number of movements: $$(./$(NAME) $(RANDOM_NUMBERS) | tee output.txt | wc -l)\n"
	$(VAL) --leak-check=full --show-leak-kinds=all -s ./$(NAME) $(RANDOM_NUMBERS) > output2.txt 2>&1
#	@grep "total heap usage" output2.txt
	@awk '/HEAP SUMMARY:/ {flag=1} flag' output2.txt
	@echo "________________________________________________________________________________\n"
	@echo "<Teste checker>"
	@./$(NAME) $(RANDOM_NUMBERS) | ./$(BONUS_NAME) $(RANDOM_NUMBERS) > output2.txt 2>&1
	@echo "//checker result: $$(cat output2.txt)\n"
	$(VAL) --leak-check=full --show-leak-kinds=all -s ./$(BONUS_NAME) $(RANDOM_NUMBERS) < output.txt > output.txt 2>&1
	@awk '/HEAP SUMMARY:/ {flag=1} flag' output.txt
#	@grep "total heap usage" output.txt
	@echo "________________________________________________________________________________\n"
	@echo "<Norminette>"
	@norminette -R CheckDefine . | awk '/Error/'
	@$(RM) output.txt output2.txt

clean:
	@echo "Objects removed"
	$(RM) -rf $(OBJ_DIR)

fclean: clean
	@echo "Executable removed"
	$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all bonus test debug clean fclean re
