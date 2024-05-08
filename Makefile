# NAME		=	libftprintf.a
# LIBFT_NAME = 	libft.a
# CC			=	cc
# CFLAG		=	-Wall -Wextra -Werror
# AR			=	ar
# INCLUDES	=	includes/*.h
# SRCS		=	srcs/*.c
# LIBFT_SRCS 	=	libft/*.c
# OBJS		=	$(SRCS .c=.o)
# LIBFT_OBJS	=	$(LIBFT_SRCS .c=.o)

# .c.o:
# 	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(INCLUDES)

# $(NAME): $(OBJS)
# 	$(AR) $(NAME) $(OBJS) $(LIBFT_OBJS)

# all:
# 	$(RM) $(NAME) $(OBJS)

# clean:
# 	$(RM) $(OBJS) $(LIBFT_OBJS)

# fclean: clean
# 	$(RM) $(NAME) $(LIBFT_NAME)

# re: fclean all

# .PHONY: all clean fclean re
SRCS_NORMAL = ./srcs/*.c
SRCS_BONUS = $(SRCS_NORMAL)

OBJS_NORMAL = $(SRCS_NORMAL:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

LIBFT_PATH = ./libft
LIBFT_NAME = libft.a

INCLUDES = include

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rcs

ifdef IS_BONUS
	OBJS = $(OBJS_BONUS)
else
	OBJS = $(OBJS_NORMAL)
endif

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(INCLUDES)

$(NAME): $(LIBFT) $(OBJS) 
	@make -C $(LIBFT_PATH) all
	cp $(LIBFT_PATH)/$(LIBFT_NAME) $(NAME)
	$(AR) $(NAME) $(OBJS)
	@echo "$(GREEN)make done$(DEF_COLOR)"

all: ${NAME}
	@echo "$(GREEN)make all done$(DEF_COLOR)"

bonus: 
	@make IS_BONUS=1 $(NAME)
	@echo "$(GREEN)make bonus done$(DEF_COLOR)"

clean:
	$(RM) $(OBJS_NORMAL) $(OBJS_BONUS)
	@make -C $(LIBFT_PATH) clean
	@echo "$(MAGENTA)make clean done$(DEF_COLOR)"

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT_PATH)/$(LIBFT_NAME)
	@echo "$(MAGENTA)make fclean done$(DEF_COLOR)"

re: fclean all
	@echo "$(GREEN)make re done$(DEF_COLOR)"

norm:
	@norminette -R CheckForbiddenSourceHeader $(SRCS_BONUS) $(INCLUDES)

.PHONY: all clean fclean re bonus norm