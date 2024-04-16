# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/04 11:59:35 by bebrandt          #+#    #+#              #
#    Updated: 2024/04/16 14:52:37 by bebrandt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	philo_bonus

SRCS_DIR		=	srcs/

SRCS			=	$(addsuffix .c, philo_bonus check_arg_input verbose libft_utils \
									philosopher_routine perform_philosopher_action \
									perform_philosopher_action_utils \
									perform_philo_supervisor_action \
									perform_parent_action \
									read_philosopher_variable \
									read_philosopher_variable_utils \
									update_philosopher_variable \
									update_philosopher_variable_utils\
									init_lst init_lst_utils time \
									cleaning cleaning_utils test)

OBJ_DIR			=	objs/

OBJ 			=	$(SRCS:.c=.o)

OBJS 			=	$(addprefix $(OBJ_DIR),$(OBJ))

HDRS			=	-Iincludes/.

CC				=	gcc $(HDRS)

CFLAGS			=	-Wall -Wextra -Werror -pthread
RM				=	rm -f

RED				=	\033[0;31m
GREEN			=	\033[0;32m
NONE			=	\033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $@ $^
	@echo "$(GREEN)##### " $@ "Program is created #####$(NONE)"

$(OBJ_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@echo "$(GREEN)##### Creating" [ $@ ] " #####$(NONE)"
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@rm -f $(OBJS)
	@rm -f $(SEM_OBJS)
	@echo "$(RED)##### Removed object files #####$(NONE)"

fclean: clean
	@rm -f $(NAME)
	@rm -f $(SEM_NAME)
	@echo "$(RED)##### Removed binary files #####$(NONE)"

re: fclean all

.PHONY: all clean fclean re
