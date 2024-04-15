# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/04 11:59:35 by bebrandt          #+#    #+#              #
#    Updated: 2024/04/15 10:22:45 by bebrandt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	philo_bonus

SRCS_DIR		=	srcs/

SRCS			=	$(addsuffix .c, philo_bonus check_arg_input verbose libft_utils \
									init_lst init_lst_utils time \
									cleaning cleaning_utils test)

OBJ_DIR			=	objs/

OBJ 			=	$(SRCS:.c=.o)

OBJS 			=	$(addprefix $(OBJ_DIR),$(OBJ))

SEM_NAME		=	unlink_semaphore
SEM_SRCS		=	$(addsuffix .c, unlink)
SEM_OBJ 		= 	$(SEM_SRCS:.c=.o)
SEM_OBJS 		= 	$(addprefix $(OBJ_DIR),$(SEM_OBJ))

HDRS			=	-Iincludes/.

CC				=	gcc $(HDRS)

CFLAGS			=	-Wall -Wextra -Werror -pthread -g

RM				=	rm -f

RED				=	\033[0;31m
GREEN			=	\033[0;32m
NONE			=	\033[0m

all: $(NAME)

sem: $(SEM_NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $@ $^
	@echo "$(GREEN)##### " $@ "Program is created #####$(NONE)"

$(SEM_NAME): $(SEM_OBJS)
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

.PHONY: all clean fclean re sem
