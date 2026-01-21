# ==============================================================
#							PUSH_SWAP
# ==============================================================

NAME			:= push_swap
B_NAME			:= checker

SRC_DIR			:= srcs
INCL_DIR		:= includes
BUILD_DIR		:= .build
OBJ_DIR			:= $(BUILD_DIR)/objs
DEP_DIR			:= $(BUILD_DIR)/deps
B_SRC_DIR		:= srcs_bonus
B_INCL_DIR		:= includes_bonus
B_BUILD_DIR		:= .build_bonus
B_OBJ_DIR		:= $(B_BUILD_DIR)/objs
B_DEP_DIR		:= $(B_BUILD_DIR)/deps

CC				:= cc
CFLAGS			= -g -Wall -Werror -Wextra -I$(INCL_DIR)

SRCS :=			benchmark_utils.c \
				bubble_sort.c \
				compute_disorder.c \
				data_handling.c \
				error_handling.c \
				input_parsing.c \
				insertion_sort.c \
				node_utils.c \
				parsing_handling.c \
				push_swap.c \
				pushswap_operations_p.c \
				pushswap_operations_r.c \
				pushswap_operations_rr.c \
				pushswap_operations_s.c \
				selection_sort.c \
				stack_operations.c \
				stack_utils.c \
				butterfly_sort.c \
				array_utils.c \
				radix_sort.c

B_SRCS :=		checker.c \
				get_next_line.c \
				get_next_line_utils.c \
				silent_pushswap_operations_p.c \
				silent_pushswap_operations_r.c \
				silent_pushswap_operations_rr.c \
				silent_pushswap_operations_s.c

SRCS_PATH		:= $(addprefix $(SRC_DIR)/,$(SRCS))
OBJS			:= $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS_PATH))
DEPS			:= $(patsubst $(OBJ_DIR)/%.o,$(DEP_DIR)/%.d,$(OBJS))

B_SRCS_PATH		:= $(addprefix $(B_SRC_DIR)/,$(B_SRCS))
B_OBJS			:= $(patsubst $(B_SRC_DIR)/%.c,$(B_OBJ_DIR)/%.o,$(B_SRCS_PATH))
B_DEPS			:= $(patsubst $(B_OBJ_DIR)/%.o,$(B_DEP_DIR)/%.d,$(B_OBJS))

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
	gdb -tui ./$(NAME)

$(NAME): $(LIBFTPRINTF) $(OBJS)
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

bonus: $(B_NAME)

b_debug: fclean all
	@$(MAKE) bonus
	gdb -tui ./$(B_NAME)

COMMON_OBJS := $(filter-out $(OBJ_DIR)/push_swap.o, $(OBJS))

$(B_NAME): $(LIBFTPRINTF) $(COMMON_OBJS) $(B_OBJS)
	@echo "$(YELLOW)LINKING $(B_NAME)...$(RESET)"
	$(CC) $(CFLAGS) -o $(B_NAME) $(COMMON_OBJS) $(B_OBJS) -L$(LIBFTPRINTF_DIR) -lftprintf
	@echo "$(GREEN)DONE! $(CYAN)CHECKER$(GREEN) IS READY.$(RESET)"

$(B_OBJ_DIR):
	mkdir -p $(B_OBJ_DIR)

$(B_DEP_DIR):
	mkdir -p $(B_DEP_DIR)

$(B_OBJ_DIR)/%.o: $(B_SRC_DIR)/%.c | $(B_OBJ_DIR) $(B_DEP_DIR)
	@echo "$(YELLOW)COMPILING BONUS $(GREEN)$< $(YELLOW)⮞ $(GREEN)$@$(RESET)"
	$(CC) $(CFLAGS) -o "$@" -c "$<" -MMD -MP -MF "$(B_DEP_DIR)/$(@F:.o=.d)"

clean:
	@echo "$(RED)CLEANING PUSH_SWAP AND CHECKER BUILD DIRECTORIES...$(RESET)"
	$(RM) -r $(BUILD_DIR) $(B_BUILD_DIR)
	$(MAKE) -C $(LIBFTPRINTF_DIR) clean

fclean: clean
	@echo "$(RED)CLEANING ARCHIVE FILE...$(RESET)"
	$(RM) $(NAME) $(B_NAME)
	$(MAKE) -C $(LIBFTPRINTF_DIR) fclean

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re libftprintf debug bonus
