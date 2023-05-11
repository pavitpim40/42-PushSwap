#VAR
NAME			=	push_swap
CC				=	gcc
FLAGS			=	-Wall -Wextra -Werror
RM				=	rm -rf

#HEADER
HEADER_SRCS		=	push_swap.h
HEADER_DIR		=	includes/
HEADER			=	$(addprefix $(HEADER_DIR), $(HEADER_SRCS))

#MANDATORY
MAND_SRCS		=	main.c stack/stack.c \
					action/action_s.c action/action_p.c action/action_r.c action/action_rr.c \
					input/input_validate.c input/input_fill.c\
					sort/bubble_sort.c sort/small_sort.c \
					sort/quick_sort.c sort/chunk_sort.c pre_sort/label_rank.c \
					
MAND_PATH_DIR	=	srcs/
MAND_PATH		=	$(addprefix $(MAND_PATH_DIR), $(MAND_SRCS))
MAND_OBJ		=	$(MAND_PATH:.c=.o)

#LIBFT
LIBFT_SRCS		=	ft_strlen.c ft_bzero.c  ft_calloc.c ft_split.c ft_strjoin.c \
					ft_isdigit.c ft_atoi.c ft_itoa.c
LIBFT_PATH_DIR	=	libft/
LIBFT_PATH		=	$(addprefix $(LIBFT_PATH_DIR), $(LIBFT_SRCS))
LIBFT_OBJ		=	$(LIBFT_PATH:.c=.o)

#COMMAND
%.o: %.c $(HEADER) Makefile
					@${CC} ${FLAGS} -c  $< -o $@

$(NAME):			$(LIBFT_OBJ) $(MAND_OBJ)
					@$(CC) $(LIBFT_OBJ) $(MAND_OBJ) -o $(NAME)
					@echo -e "$(GREEN)$(NAME) created!$(DEFAULT)"

all:				$(NAME)

clean:
					@$(RM) $(MAND_OBJ)
					@$(RM) $(LIBFT_OBJ)
					@echo -e "$(YELLOW)object files deleted!$(DEFAULT)"

fclean:				clean
					@$(RM) $(NAME)
					@echo -e "$(RED)all deleted!$(DEFAULT)"

re:					fclean all

.PHONY:			all clean fclean re

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m