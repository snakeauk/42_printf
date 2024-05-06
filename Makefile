NAME		=	libftprintf.a
CC			=	cc
CFLAG		=	-Wall -Wextra -Werror
AR			=	ar
INCLUDES	=	includes/*.h
SRCS		=	srcs/*.c
OBJS		=	$(SRCS .c=.o)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<: .c=.o) -I $(INCLUDES)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS) $(INCLUDES)

all:
	$(RM) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) $(OBJS)

re: fclean all

.PHONY: all clean fclean re