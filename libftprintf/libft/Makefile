# ==============================================================
#							LIBFT
# ==============================================================

NAME	:= libft.a

CC		:= cc
CFLAGS	:= -Wall -Werror -Wextra -I.

BUILD_DIR	:= .build
OBJ_DIR		:= $(BUILD_DIR)/objs
DEP_DIR		:= $(BUILD_DIR)/deps

SRCS =			ft_isalpha.c \
				ft_isdigit.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_isprint.c \
				ft_strlen.c \
				ft_memset.c \
				ft_bzero.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_strlcpy.c \
				ft_strlcat.c \
				ft_toupper.c \
				ft_tolower.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_strncmp.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_strnstr.c \
				ft_atoi.c \
				ft_calloc.c \
				ft_strdup.c \
				ft_substr.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_split.c \
				ft_itoa.c \
				ft_strmapi.c \
				ft_striteri.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c

SRCS_BONUS =	ft_lstnew_bonus.c \
				ft_lstadd_front_bonus.c \
				ft_lstsize_bonus.c \
				ft_lstlast_bonus.c \
				ft_lstadd_back_bonus.c \
				ft_lstdelone_bonus.c \
				ft_lstclear_bonus.c \
				ft_lstiter_bonus.c \
				ft_lstmap_bonus.c

OBJS		=	$(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))
OBJS_BONUS	=	$(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS_BONUS))

DEPS	= $(patsubst $(OBJ_DIR)/%.o, $(DEP_DIR)/%.d, $(OBJS) $(OBJS_BONUS))

RED     := \033[1;31m
GREEN   := \033[1;32m
YELLOW  := \033[1;33m
CYAN    := \033[1;36m
RESET   := \033[0m

.DEFAULT_GOAL = all

all: $(NAME)

BONUS = .bonus

bonus: $(BONUS)

$(NAME): $(OBJS)
	@echo "$(YELLOW)LINKING...$(RESET)"
	ar -rcs $(NAME) $^
	@echo "$(GREEN)DONE! $(CYAN)LIBFT$(GREEN) IS READY.$(RESET)"

$(BONUS): $(OBJS) $(OBJS_BONUS)
	@echo "$(YELLOW)LINKING...$(RESET)"
	ar -rcs $(NAME) $^
	touch .bonus
	@echo "$(GREEN)DONE! $(CYAN)LIBFT (BONUS)$(GREEN) IS READY.$(RESET)"

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(DEP_DIR):
	mkdir -p $(DEP_DIR)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR) $(DEP_DIR)
	@echo "$(YELLOW)COMPILING $(GREEN)$< $(YELLOW)-> $(GREEN)$@$(RESET)"
	$(CC) $(CFLAGS) -c "$<" -o "$@" -MMD -MP -MF "$(DEP_DIR)/$(@F:.o=.d)"

clean:
	@echo "$(RED)CLEANING LIBFT BUILD DIRECTORIES...$(RESET)"
	$(RM) -r $(BUILD_DIR)

fclean: clean
	@echo "$(RED)CLEANING ARCHIVE FILE...$(RESET)"
	$(RM) $(NAME) $(BONUS)

re: fclean all

-include $(DEPS)

.PHONY: clean fclean re all bonus