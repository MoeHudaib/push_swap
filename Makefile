CC= cc
CFLAGS= -g
NAME= push_swap
SRCS= ./DataStructure/stack.c \
      ./DataStructure/stack_utils.c \
      main.c
LIBS= ./DataStructure/libft/libft.a \
      ./DataStructure/ft_printf/libftprintf.a


all: $(SRCS) $(LIBS)
	$(CC) $(CFLAGS) $(SRCS) $(LIBS) -o $(NAME)

clean:
	ls
fclean: clean
	rm -f $(NAME)
re: fclean $(NAME)
