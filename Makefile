NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rcs
INCLUDES = -I ./includes

SRCS_DIR = ./srcs
SRCS	=	$(SRCS_DIR)/ft_fputi.c $(SRCS_DIR)/ft_fputu.c $(SRCS_DIR)/ft_itoa_base.c $(SRCS_DIR)/ft_ullsize.c \
			$(SRCS_DIR)/ft_fputp.c $(SRCS_DIR)/ft_fputx.c $(SRCS_DIR)/ft_printf.c $(SRCS_DIR)/ft_ulltoa_base.c \
			$(SRCS_DIR)/ft_uisize.c $(SRCS_DIR)/ft_uitoa.c $(SRCS_DIR)/ft_fputs.c $(SRCS_DIR)/ft_isize.c \
			$(SRCS_DIR)/ft_putc.c $(SRCS_DIR)/ft_vprintf.c

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

.PHONY: all clean fclean re