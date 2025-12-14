# ==============================================================
#							PUSH_SWAP
# ==============================================================

NAME			:= push_swap

SRC_DIR			:= srcs
INCL_DIR		:= includes
BUILD_DIR		:= .build
OBJ_DIR			:= $(BUILD_DIR)/objs
DEP_DIR			:= $(BUILD_DIR)/deps

CC				:= cc
CFLAGS			= -Wall -Werror -Wextra -I$(INCL_DIR)

SRCS :=			push_swap.c \
				stack_utils.c \
				compute_disorder.c \
				validate_args.c

SRCS_PATH		:= $(addprefix $(SRC_DIR)/,$(SRCS))
OBJS			:= $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS_PATH))
DEPS			:= $(patsubst $(OBJ_DIR)/%.o,$(DEP_DIR)/%.d,$(OBJS))

LIBFTPRINTF_DIR	:= libftprintf
LIBFTPRINTF		:= $(LIBFTPRINTF_DIR)/libftprintf.a

RED				:= \033[1;31m
GREEN			:= \033[1;32m
YELLOW			:= \033[1;33m
CYAN			:= \033[1;36m
RESET			:= \033[0m

.DEFAULT_GOAL = all

all: libftprintf $(NAME)

libftprintf:
	$(MAKE) -C $(LIBFTPRINTF_DIR) all

debug:
	@$(MAKE) CFLAGS+="-g" re
	gdb ./$(NAME)
	
$(NAME):  $(LIBFTPRINTF) $(OBJS)
	@echo "$(YELLOW)LINKING...$(RESET)"
	$(CC) $(CFLAGS) -o $(NAME) -L$(LIBFTPRINTF_DIR) $(OBJS) -lftprintf
	@echo "$(GREEN)DONE! $(CYAN)PUSH_SWAP$(GREEN) IS READY.$(RESET)"

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(DEP_DIR):
	mkdir -p $(DEP_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR) $(DEP_DIR)
	@echo "$(YELLOW)COMPILING $(GREEN)$< $(YELLOW)⮞ $(GREEN)$@$(RESET)"
	$(CC) $(CFLAGS) -o "$@" -c "$<" -MMD -MP -MF "$(DEP_DIR)/$(@F:.o=.d)"

clean:
	@echo "$(RED)CLEANING PUSH_SWAP BUILD DIRECTORIES...$(RESET)"
	$(RM) -r $(BUILD_DIR)
	$(MAKE) -C $(LIBFTPRINTF_DIR) clean

fclean: clean
	@echo "$(RED)CLEANING ARCHIVE FILE...$(RESET)"
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFTPRINTF_DIR) fclean

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re libftprintf debug