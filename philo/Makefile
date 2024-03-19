# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/04 11:59:35 by bebrandt          #+#    #+#              #
#    Updated: 2024/03/19 15:48:52 by bebrandt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo
SRCS		=	$(addsuffix .c, philo ft_atoi)
OBJ 		= $(SRCS:.c=.o)
OBJS 	= $(addprefix $(OBJ_DIR),$(OBJ))

SRCS_DIR		=	srcs/

OBJ_DIR			=	objs/

HDRS			=	-Iincludes/.

CC				=	gcc $(HDRS)

CFLAGS			=	-Wall -Wextra -Werror -pthread -g

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
	@rm -f $(OBJS)
	@echo "$(RED)##### Removed object files #####$(NONE)"

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME)
	@echo "$(RED)##### Removed binary files #####$(NONE)"

re: fclean all

.PHONY: all clean fclean re
