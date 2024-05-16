NAME = libftprintf.a
SRCS = ft_printf.c ft_printf_utils.c ft_printf_conversions.c
OBJS = $(SRC:.c=.o)
LIBFT_PATH = ./srcs/libft/
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	make bonus $(LIBFT_PATH)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(OBJS_BONUS)
	ar rcs $(NAME) $(OBJS) $(OBJS_BONUS)

.PHONY: all clean fclean re bonus
