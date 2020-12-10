CC		= gcc -Wall -Wextra -Werror
AR      = ar rcs

BLACK	= \033[0;30m
RED		= \033[0;31m
GREEN	= \033[0;32m
YELLOW	= \033[0;33m
BLUE	= \033[0;34m
PURPLE	= \033[0;35m
CYAN	= \033[0;36m
GRAY	= \033[0;37m
NC		= \033[0m


NAME    = libftprintf.a
HEAD    = ft_printf.h
SRCS	= ft_printf.c\
			ft_putchar.c\
			ft_putxpu.c\
			ft_collectflags.c\
			ft_putdcs.c\
			ft_itoa_base.c\
			ft_put.c\
			ft_putstr.c\
			
LIBFT_DIR = libft
OBJS    = $(SRCS:.c=.o)
LIBFT   = $(LIBFT_DIR)/libft.a


all: libft_ $(NAME)

libft_ :
	@make -C libft
	@make bonus -C libft

$(NAME): $(OBJS)
	@cp $(LIBFT) $(NAME)
	@$(AR) $(NAME) $^ libft/*.o
	@echo "$(RED)ALL$(NC)"
%.o : %.c
	@$(CC) $(FLAGS) -c $<

clean:
	@make clean -C  libft
	@rm -f  $(OBJS)
	@echo "$(YELLOW)cleen$(NC)"
	
fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)
	@echo "$(RED)fcleen$(NC)"
re: fclean all
	@rm -f $(OBJS)
	@echo "$(GREEN)ALL DONE$(NC)"