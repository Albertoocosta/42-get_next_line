CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = get_next_line.c get_fts.c
NAME = get_next_line.a
AR = ar rcs
RM = rm -f
OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean:
	$(RM) $(NAME)

re: fclean all