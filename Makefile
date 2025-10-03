CC     = cc
CFLAGS = -Wall -Wextra -Werror -g
NAME   = push_swap

SRCS = ./stack/stack.c \
       ./stack/stack_utils.c \
       ./stack/helpers.c \
       ./validation/input_validation.c \
       ./sorting/index.c \
       ./sorting/push_swap_utils.c \
       ./sorting/push_swap.c \
       ./sorting/hudaib.c \
       ./sorting/hudaib_utils.c \
       ./sorting/push_chunk_to_b.c \
       main.c

LIBS = ./libs/libft/libft.a \
       ./libs/ft_printf/libftprintf.a



all: $(NAME)

$(NAME): $(SRCS) $(LIBS)
	$(CC) $(CFLAGS) $(SRCS) $(LIBS) -o $(NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re do
