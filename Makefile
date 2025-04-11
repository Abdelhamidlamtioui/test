NAME = so_long

SRC =  map_validation.c  libft/ft_memset.c      libft/ft_strjoin.c    printf/ft_print_pointer.c\
       ft_check.c      printf/ft_print_char.c     libft/ft_strlcpy.c    printf/ft_print_hex.c\
       ft_error.c      libft/ft_putchar_fd.c  libft/ft_strlen.c     printf/ft_print_string.c\
       ft_flood.c      printf/ft_print_unsigned.c      libft/ft_strnstr.c    printf/ft_print_number.c\
       ft_key.c        libft/ft_putstr_fd.c   libft/ft_substr.c     so_long.c\
       renderer.c   libft/ft_split.c       printf/ft_printf.c\
       ft_start.c      libft/ft_strcmp.c      utils.c\
       libft/ft_strdup.c 


OBJ = $(SRC:.c=.o)

all : $(NAME)

CFLAGS = -Wall -Wextra -Werror

MLXFLAGS = -L/usr/include/minilibx-linux -lmlx -L/usr/lib -lXext -lX11 -lz

%.o : %.c
	cc $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	cc $(CFLAGS) $(OBJ)  -o $(NAME) $(MLXFLAGS)

clean : 
	@rm -fv $(OBJ)

fclean : clean
	@rm -fv $(NAME)

re : fclean all

.PHONY : clean re all fclean
