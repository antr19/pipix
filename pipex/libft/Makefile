NAME = libft.a
HEAD = libft.h
SRCS = $(shell find "." -name "*.c")
OBJS = $(SRCS:.c=.o)
FLAGS = -Wall -Werror -Wextra
CC = cc
AR = ar csr

all:	$(NAME)

$(NAME): ${OBJS}
	@${AR} ${NAME} ${OBJS}

.c.o: $(HEAD)
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

clean:
	${RM} ${OBJS} $(B_OBJS)