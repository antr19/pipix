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

GNL = ft_gnl/get_next_line.c
OBJS_G = $(GNL:.c=.o)

SRCS =	child.c pipex.c here_doc.c
OBJS = 	$(SRCS:.c=.o)

HEAD =	pipex.h

CC = 	cc
FLAGS = -Wall -Wextra -Werror
RM = 	rm -f

all:	$(NAME)

run: $(NAME)
#	@./pipex infile "ls -l" "wc -l" "wc -l" outfile
	@./pipex infile "cat" "sort" "wc" "ls" "cd" "wc" outfile
#	@./pipex here_doc LIMITER "cat -e" "wc -l"
#	leaks --atExit -- ./$(NAME)
	@< infile cat | sort | wc | ls | cd | wc > check_outfile

$(NAME): $(OBJS) $(OBJS_G) 
	$(MAKE) -C ./libft
	$(CC) $(FLAGS) $(OBJS) $(OBJS_G) ./libft/libft.a -o $(NAME)
 
bonus: $(NAME) 

.c.o: $(HEAD)
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

clean:
	$(MAKE) clean -C ./ft_gnl
	$(MAKE) clean -C ./libft
	${RM} ${OBJS} $(B_OBJS)

fclean: clean
	$(RM) $(NAME) $(B_NAME)

re: fclean all

.PHONY: all clean fclean re bonus