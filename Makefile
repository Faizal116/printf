# NAME		= libftprintf.a
# INCLUDES	= include
# LIBFT		= libft
# MAIN_DIR	= $(shell pwd)
# CC			= gcc
# CFLAGS		= -Wall -Werror -Wextra -I
# RM			= rm -f
# AR			= ar rcs

# DEF_COLOR 	= \033[0;39m
# GRAY 		= \033[0;90m
# RED 		= \033[0;91m
# GREEN 		= \033[0;92m
# YELLOW 		= \033[0;93m
# BLUE 		= \033[0;94m
# MAGENTA 	= \033[0;95m
# CYAN 		= \033[0;96m
# WHITE 		= \033[0;97m

# SRCS 		= ft_hexa.c ft_pointer.c ft_printf.c ft_printstuffs.c ft_unsigned.c

# OBJS 		= $(SRCS:.c=.o)

# all:		$(NAME)

# $(NAME):	$(OBJS)
# 			@make -C $(LIBFT)
# 			@cp libft/libft.a $(MAIN_DIR)
# 			@mv libft.a $(NAME)
# 			$(AR) $(NAME) $(OBJS)
# 			@echo "$(GREEN)f$(BLUE)t$(YELLLOW)_$(CYAN)p$(WHITE)r$(MAGENTA)i$(RED)n$(GRAY)t$(GREEN)f $(DEF_COLOR)compiled!$(DEF_COLOR)"
# .c.o:
# 		$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $(<:.c=.o)
# clean:
# 		$(RM) $(OBJS)
# 		@make clean -C $(LIBFT)
# 		@echo "$(BLUE)Cleaned"

# fclean:		clean
# 			$(RM) $(NAME)
# 			$(RM) $(LIBFT)/libft.a
# 			@echo "$(BLUE)F Cleaned"

# re:			fclean all

# .PHONY:		all clean fclean re

NAME		= libftprintf.a
INCLUDES	= include
LIBFT		= libft
MAIN_DIR	= $(shell pwd)
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -I
AR			= ar -rcs
RM			= rm -f

GREEN		= \033[0;92m

SRCS		= ft_hexa.c ft_pointer.c ft_printf.c ft_printstuffs.c ft_unsigned.c

OBJS		= $(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			@make -C $(LIBFT)
			@cp libft/libft.a $(MAIN_DIR)
			@mv libft.a $(NAME)
			$(AR) $(NAME) $(OBJS)
			@echo "$(GREEN)ft_printf Complied"

.c.o:
			$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $(<:.c=.o)

clean:
			$(RM) $(OBJS)
			@make clean -C $(LIBFT)
			@echo "$(GREEN)ft_printf Object Files Cleaned"

fclean:		clean
			$(RM) $(NAME)
			$(RM) $(LIBFT)/libft.a
			@echo "$(GREEN)ft_printf Exec Files Cleaned"
			@echo "$(GREEN)Libft Exec File Cleaned"

re:			fclean all
			@echo "$(GREEN)ft_printf Cleaned and Rebuilt Everything"

.PHONY:		all clean fclean re