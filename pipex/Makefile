# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mikabuto <mikabuto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/07 17:55:58 by mikabuto          #+#    #+#              #
#    Updated: 2022/03/07 17:55:58 by mikabuto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 	pipex
B_NAME = checker

SRCS =	pipex.c

HEAD =	push_swap.h

OBJS = 	$(SRCS:.c=.o)
# B_OBJS = $(B_SRCS:.c=.o)

CC = 	cc
# FLAGS = -Wall -Wextra -Werror
FLAGS = 
RM = 	rm -f

all:	$(NAME)

run: $(NAME)
	@./pipex

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

bonus: $(B_NAME)

$(B_NAME): $(B_OBJS)
	$(CC) $(FLAGS) $(B_OBJS) -o $(B_NAME)

.c.o: $(HEAD)
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

clean:
	${RM} ${OBJS} $(B_OBJS)

fclean: clean
	$(RM) $(NAME) $(B_NAME)

re: fclean all

.PHONY: all clean fclean re bonus