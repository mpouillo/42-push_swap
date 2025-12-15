# ==============================================================
#							FT_PRINTF
# ==============================================================

NAME			:= libftprintf.a

CC				:= cc
CFLAGS			:= -Wall -Werror -Wextra -Iincludes

SRC_DIR			:= srcs
BUILD_DIR		:= .build
OBJ_DIR			:= $(BUILD_DIR)/objs
DEP_DIR			:= $(BUILD_DIR)/deps

SRCS :=			$(SRC_DIR)/ft_printf.c \
				$(SRC_DIR)/print_char.c \
				$(SRC_DIR)/print_hex.c \
				$(SRC_DIR)/print_int.c \
				$(SRC_DIR)/print_pointer.c \
				$(SRC_DIR)/print_string.c \
				$(SRC_DIR)/print_unsigned.c \
				$(SRC_DIR)/print_percent.c \
				$(SRC_DIR)/format_parsing.c \
				$(SRC_DIR)/utils_printing.c \
				$(SRC_DIR)/utils_padding.c \
				$(SRC_DIR)/utils_flags.c \
				$(SRC_DIR)/utils_count.c \
				$(SRC_DIR)/utils_sign.c \
				$(SRC_DIR)/utils_compare.c

LIBFT_DIR		:= libft
LIBFT			:= $(LIBFT_DIR)/libft.a

LIBFT_INCL 		:= $(LIBFT_DIR)/libft.h

LIBFT_SRCS :=	$(LIBFT_DIR)/ft_isalpha.c \
				$(LIBFT_DIR)/ft_isdigit.c \
				$(LIBFT_DIR)/ft_isalnum.c \
				$(LIBFT_DIR)/ft_isascii.c \
				$(LIBFT_DIR)/ft_isprint.c \
				$(LIBFT_DIR)/ft_strlen.c \
				$(LIBFT_DIR)/ft_memset.c \
				$(LIBFT_DIR)/ft_bzero.c \
				$(LIBFT_DIR)/ft_memcpy.c \
				$(LIBFT_DIR)/ft_memmove.c \
				$(LIBFT_DIR)/ft_strlcpy.c \
				$(LIBFT_DIR)/ft_strlcat.c \
				$(LIBFT_DIR)/ft_toupper.c \
				$(LIBFT_DIR)/ft_tolower.c \
				$(LIBFT_DIR)/ft_strchr.c \
				$(LIBFT_DIR)/ft_strrchr.c \
				$(LIBFT_DIR)/ft_strncmp.c \
				$(LIBFT_DIR)/ft_memchr.c \
				$(LIBFT_DIR)/ft_memcmp.c \
				$(LIBFT_DIR)/ft_strnstr.c \
				$(LIBFT_DIR)/ft_atoi.c \
				$(LIBFT_DIR)/ft_calloc.c \
				$(LIBFT_DIR)/ft_strdup.c \
				$(LIBFT_DIR)/ft_substr.c \
				$(LIBFT_DIR)/ft_strjoin.c \
				$(LIBFT_DIR)/ft_strtrim.c \
				$(LIBFT_DIR)/ft_split.c \
				$(LIBFT_DIR)/ft_itoa.c \
				$(LIBFT_DIR)/ft_strmapi.c \
				$(LIBFT_DIR)/ft_striteri.c \
				$(LIBFT_DIR)/ft_putchar_fd.c \
				$(LIBFT_DIR)/ft_putstr_fd.c \
				$(LIBFT_DIR)/ft_putendl_fd.c \
				$(LIBFT_DIR)/ft_putnbr_fd.c

OBJS			:= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
DEPS			:= $(patsubst $(OBJ_DIR)/%.o, $(DEP_DIR)/%.d, $(OBJS))

RED     		:= \033[1;31m
GREEN   		:= \033[1;32m
YELLOW			:= \033[1;33m
CYAN 			:= \033[1;36m
RESET			:= \033[0m

.DEFAULT_GOAL = all

all: $(NAME)

bonus: all

$(LIBFT): $(LIBFT_SRCS) $(LIBFT_INCL)
	@echo "$(YELLOW)CREATING LIBFT...$(RESET)"
	$(MAKE) -C libft all
	cp $(LIBFT) $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@echo "$(YELLOW)LINKING...$(RESET)"
	ar -q $(NAME) $(OBJS)
	@echo "$(GREEN)DONE! $(CYAN)FT_PRINTF$(GREEN) IS READY.$(RESET)"

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(DEP_DIR):
	mkdir -p $(DEP_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR) $(DEP_DIR)
	@echo "$(YELLOW)COMPILING $(GREEN)$< $(YELLOW)⮞ $(GREEN)$@$(RESET)"
	$(CC) $(CFLAGS) -c "$<" -o "$@" -MMD -MP -MF "$(DEP_DIR)/$(@F:.o=.d)"

clean:
	@echo "$(RED)CLEANING BUILD DIRECTORIES...$(RESET)"
	$(RM) -r $(BUILD_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@echo "$(RED)CLEANING ARCHIVE FILES...$(RESET)"
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

-include $(DEPS)

.PHONY: clean fclean re all bonus