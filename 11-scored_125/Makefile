#VAR
NAME			=	push_swap
NAME_CHECKER	=	checker
CC				=	gcc
FLAGS			=	-Wall -Wextra -Werror
RM				=	rm -rf

#HEADER
HEADER_SRCS		=	push_swap.h
HEADER_DIR		=	includes/
HEADER			=	$(addprefix $(HEADER_DIR), $(HEADER_SRCS))

#MANDATORY
SRCS			=	stack/stack.c stack/stack_utils.c\
					action/action_s.c action/action_p.c action/action_r.c action/action_rr.c \
					input/input_validate.c input/input_fill.c\
					pre_sort/label_rank.c \
					sort/utils.c sort/small_sort.c  sort/chunk_sort.c \
					sort/is_sorted.c sort/turk_sort.c sort/turk_utils_1.c sort/turk_utils_2.c \
					sort/turk_utils_3.c sort/turk_utils_4.c
					
					
PATH_DIR	=	srcs/
PATH		=	$(addprefix $(PATH_DIR), $(SRCS))
OBJ		=	$(PATH:.c=.o)

# MANDATORY 
MAND_SRCS		=	main.c
					
MAND_PATH_DIR	=	srcs/
MAND_PATH		=	$(addprefix $(MAND_PATH_DIR), $(MAND_SRCS))
MAND_OBJ		=	$(MAND_PATH:.c=.o)

#BONUS
BONUS_SRCS		=	checker.c get_next_line.c get_next_line_utils.c 
					
BONUS_PATH_DIR	=	bonus_checker/
BONUS_PATH		=	$(addprefix $(BONUS_PATH_DIR), $(BONUS_SRCS))
BONUS_OBJ		=	$(BONUS_PATH:.c=.o)

#LIBFT
LIBFT_SRCS		=	ft_strlen.c ft_bzero.c  ft_calloc.c ft_split.c ft_strjoin.c \
					ft_isdigit.c ft_atoi.c ft_itoa.c ft_strncmp.c ft_putstr_fd.c
LIBFT_PATH_DIR	=	libft/
LIBFT_PATH		=	$(addprefix $(LIBFT_PATH_DIR), $(LIBFT_SRCS))
LIBFT_OBJ		=	$(LIBFT_PATH:.c=.o)

#COMMAND
%.o: %.c $(HEADER) Makefile
					@${CC} ${FLAGS} -c  $< -o $@

$(NAME):			$(LIBFT_OBJ) ${OBJ} $(MAND_OBJ)
					@$(CC) ${FLAGS} $(LIBFT_OBJ) ${OBJ} $(MAND_OBJ) -o $(NAME)
					@echo -e "$(GREEN)$(NAME) created!$(DEFAULT)"

$(NAME_CHECKER):	$(LIBFT_OBJ) ${OBJ} $(BONUS_OBJ)
					@$(CC)  ${FLAGS} $(LIBFT_OBJ) $(OBJ)  $(BONUS_OBJ) -o $(NAME_CHECKER)
					@echo -e "$(GREEN)$(NAME) bonus created!$(DEFAULT)"

all:				$(NAME)

bonus:				$(NAME_CHECKER)	
clean:
					@$(RM) $(MAND_OBJ) 
					@$(RM) $(OBJ) 
					@$(RM) $(BONUS_OBJ) 
					@$(RM) $(LIBFT_OBJ)
					@echo -e "$(YELLOW)object files deleted!$(DEFAULT)"

fclean:				clean
					@$(RM) $(NAME)
					@$(RM) $(NAME_CHECKER)
					@echo -e "$(RED)all deleted!$(DEFAULT)"

re:					fclean all
rebonus:			fclean all bonus

.PHONY:			all clean fclean re rebonus

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m