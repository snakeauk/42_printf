NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rcs
LIBFT_PATH = ./srcs/libft/
LIBFT_NAME = libft.a
INCLUDES = -I ./includes
SRCS = $(wildcard ./srcs/*.c)
OBJS = $(patsubst ./srcs/%.c, ./srcs/%.o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_PATH)
	mv $(LIBFT_PATH)/$(LIBFT_NAME) $(NAME)
	$(AR) $(NAME) $(OBJS)

./srcs/%.o: ./srcs/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_PATH) clean
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re