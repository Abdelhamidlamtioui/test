NAME = libftprintf.a

SRCS = ft_printf.c ft_print_char.c ft_print_string.c \
       ft_print_number.c ft_print_unsigned.c ft_print_hex.c \
       ft_print_pointer.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
