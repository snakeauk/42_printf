NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rcs
INCLUDES = -I ./includes

SRCS_DIR = ./srcs
SRCS =	$(SRCS_DIR)/ft_outchar.c $(SRCS_DIR)/ft_outstr.c \
		$(SRCS_DIR)/ft_printf_c.c $(SRCS_DIR)/ft_printf.c \
		$(SRCS_DIR)/ft_printf_d.c $(SRCS_DIR)/ft_printf_large_x.c \
		$(SRCS_DIR)/ft_printf_s.c $(SRCS_DIR)/ft_printf_x.c	\
		$(SRCS_DIR)/ft_putunbr_base.c $(SRCS_DIR)/ft_printf_i.c \
		$(SRCS_DIR)/ft_printf_p.c $(SRCS_DIR)/ft_printf_u.c \
		$(SRCS_DIR)/ft_putnbr_base.c

OBJS = $(SRCS:.c=.o)

LIBFT_PATH = ./srcs/libft/
LIBFT_NAME = libft.a

RESET = \033[0m
BOLD = \033[1m
DIM = \033[2m
UNDERLINE = \033[4m
BLINK = \033[5m
INVERT = \033[7m
LIGHT_BLUE = \033[94m
YELLOW = \033[93m

all: $(NAME)

.c.o:
	@echo "$(BOLD)$(YELLOW)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	
$(NAME): $(OBJS)
	@echo "$(BOLD)$(LIGHT_BLUE)Linking objects...$(RESET)"
	@$(MAKE) -C $(LIBFT_PATH)
	@mv $(LIBFT_PATH)/$(LIBFT_NAME) $(NAME)
	@$(AR) $(NAME) $(OBJS)
	@echo "$(BOLD)$(LIGHT_BLUE)$(NAME) created successfully!$(RESET)"

clean:
	@echo "$(BOLD)$(LIGHT_BLUE)Cleaning objects...$(RESET)"
	@$(MAKE) -C $(LIBFT_PATH) clean
	@$(RM) $(OBJS)
	@echo "$(BOLD)$(LIGHT_BLUE)Complete clean!$(RESET)"

fclean:
	@echo "$(BOLD)$(LIGHT_BLUE)Cleaning objects...$(RESET)"
	@$(MAKE) -C $(LIBFT_PATH) clean
	@$(RM) $(OBJS)
	@echo "$(BOLD)$(LIGHT_BLUE)Cleaning $(NAME)...$(RESET)"
	@$(RM) $(NAME)
	@echo "$(BOLD)$(LIGHT_BLUE)Complete fclean!$(RESET)"

re: fclean all

.PHONY: clean fclean re