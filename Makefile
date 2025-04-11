NAME		= so_long_game

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I.
RM			= rm -f

# Source files
SRCS		= so_long/main.c \
			  so_long/map_parsing.c \
			  so_long/map_validation.c \
			  so_long/game_init.c \
			  so_long/game_loop.c \
			  so_long/player_movement.c \
			  so_long/graphics.c \
			  so_long/cleanup.c

# Object files
OBJS		= $(SRCS:.c=.o)

# ft_printf
PRINTF_DIR	= ft_printf
PRINTF		= $(PRINTF_DIR)/libftprintf.a

# get_next_line
GNL_DIR		= get_next_line
GNL_SRCS	= $(GNL_DIR)/get_next_line.c \
			  $(GNL_DIR)/get_next_line_utils.c
GNL_OBJS	= $(GNL_SRCS:.c=.o)

# MiniLibX
MLX_FLAGS	= -lmlx -lXext -lX11 -lm

all:		$(NAME)

# Compile ft_printf
$(PRINTF):
	@make -C $(PRINTF_DIR)

# Compile so_long
$(NAME):	$(OBJS) $(GNL_OBJS) $(PRINTF)
	@$(CC) $(CFLAGS) $(OBJS) $(GNL_OBJS) $(PRINTF) $(MLX_FLAGS) -o $(NAME)
	@echo "$(NAME) created"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS) $(GNL_OBJS)
	@make -C $(PRINTF_DIR) clean
	@echo "Objects cleaned"

fclean:		clean
	@$(RM) $(NAME)
	@make -C $(PRINTF_DIR) fclean
	@echo "$(NAME) removed"

re:			fclean all

bonus:		all

.PHONY:		all clean fclean re