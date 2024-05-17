NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rcs
LIBFT_PATH = ./srcs/libft/
LIBFT_NAME = libft.a
SRCS = ft_printf.c ft_printf_bonus.c ft_printf_utils.c ft_printf_flags.c
OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_PATH)
	mv $(LIBFT_PATH)/$(LIBFT_NAME) $(NAME)
	$(AR) $(NAME) $@ $^

clean:
	make -C $(LIBFT_PATH) clean
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) $(LIBFT_PATH)/$(LIBFT_NAME)

re: fclean all
