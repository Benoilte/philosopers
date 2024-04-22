# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/04 11:59:35 by bebrandt          #+#    #+#              #
#    Updated: 2024/04/22 08:34:44 by bebrandt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	philo

SRCS_DIR		=	srcs/

SRCS			=	$(addsuffix .c, philo \
									init_lst \
									init_philo_lst \
									check_arg_input \
									set_philosophers \
									supervisor_action \
									philosopher_routine \
									verbose libft_utils \
									manage_philosophers_forks \
									perform_philosophers_action\
									modify_shared_variable \
									read_shared_variable \
									time \
									cleaning \
									test)

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
	@rm -f $(OBJS)
	@echo "$(RED)##### Removed object files #####$(NONE)"

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME)
	@echo "$(RED)##### Removed binary files #####$(NONE)"

re: fclean all

.PHONY: all clean fclean re
