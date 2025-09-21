CC     = cc
CFLAGS = -Wall -Wextra -Werror -g
NAME   = push_swap

SRCS = ./DataStructure/stack.c \
       ./DataStructure/stack_utils.c \
       main.c

LIBS = ./DataStructure/libft/libft.a \
       ./DataStructure/ft_printf/libftprintf.a

INC = -I./DataStructure/libft -I./DataStructure/ft_printf -I./DataStructure

all: $(NAME)

$(NAME): $(SRCS) $(LIBS)
	$(CC) $(CFLAGS) $(SRCS) $(INC) $(LIBS) -o $(NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re do
