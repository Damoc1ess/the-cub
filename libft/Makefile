# # Variables
# NAME = libft.a
# CC = cc
# CFLAGS = -Wall -Wextra -Werror -Iincludes -fPIC
# SRC_DIR = src
# SRCS = $(wildcard $(SRC_DIR)/*/*.c)
# OBJS = $(SRCS:.c=.o)
# AR = ar rcs

# # Rules
# all: $(NAME)

# $(NAME): $(OBJS)
# 	$(AR) $(NAME) $(OBJS)

# bonus: $(OBJS)
# 	$(AR) $(NAME) $(OBJS)

# clean:
# 	rm -f $(OBJS)

# fclean: clean
# 	rm -f $(NAME)

# re: fclean all

# # Compilation
# %.o: %.c
# 	$(CC) $(CFLAGS) -c $< -o $@

# .PHONY: all clean fclean re bonus
# .SILENC:
# Variables
NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes -fPIC
AR = ar rcs
SRC_DIR = src

# Colors and formatting
GREEN = \033[32m
YELLOW = \033[33m
RESET = \033[0m
CLEAR = \033[2K\r

# Progress bar variables
TOTAL_FILES = $(words $(SRCS))
CURRENT_FILE = 0
BAR_WIDTH = 40

# Function to update progress bar
define progress_bar
	$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE) + 1))))
	@printf "$(CLEAR)$(YELLOW)Compiling: [$(RESET)"
	@progress=$$(echo "$(CURRENT_FILE) * $(BAR_WIDTH) / $(TOTAL_FILES)" | bc -l); \
	filled=$$(printf "%.0f" $$progress); \
	remaining=$$(echo "$(BAR_WIDTH) - $$filled" | bc); \
	for i in $$(seq 1 $$filled); do printf "█"; done; \
	for i in $$(seq 1 $$remaining); do printf "░"; done; \
	printf "$(YELLOW)]$(RESET) $(CURRENT_FILE)/$(TOTAL_FILES) files"
endef

# Fichiers sources par catégorie
ARRAY_SRCS = $(SRC_DIR)/array/ft_free_split.c $(SRC_DIR)/array/ft_replaceSubStr.c \
	$(SRC_DIR)/array/ft_split.c $(SRC_DIR)/array/ft_strchr.c $(SRC_DIR)/array/ft_strcmp.c \
	$(SRC_DIR)/array/ft_strcpy.c $(SRC_DIR)/array/ft_strdup.c $(SRC_DIR)/array/ft_striteri.c \
	$(SRC_DIR)/array/ft_strjoin.c $(SRC_DIR)/array/ft_strjoin_free.c $(SRC_DIR)/array/ft_strlcat.c \
	$(SRC_DIR)/array/ft_strlcpy.c $(SRC_DIR)/array/ft_strlen.c $(SRC_DIR)/array/ft_strmapi.c \
	$(SRC_DIR)/array/ft_strncmp.c $(SRC_DIR)/array/ft_strnstr.c $(SRC_DIR)/array/ft_strPreppend.c \
	$(SRC_DIR)/array/ft_strrchr.c $(SRC_DIR)/array/ft_strtok.c $(SRC_DIR)/array/ft_strtrim.c \
	$(SRC_DIR)/array/ft_substr.c

ARRAY_OF_STRINGS_SRCS = $(SRC_DIR)/array_of_strings/duplicate_string_array.c \
	$(SRC_DIR)/array_of_strings/free_all_strings.c $(SRC_DIR)/array_of_strings/free_array_iter_error.c \
	$(SRC_DIR)/array_of_strings/get_2d_array_length.c $(SRC_DIR)/array_of_strings/searching_char.c

CONVERSIONS_SRCS = $(SRC_DIR)/conversions/ft_atoi_base.c $(SRC_DIR)/conversions/ft_atoi.c \
	$(SRC_DIR)/conversions/ft_atol.c $(SRC_DIR)/conversions/ft_itoa.c

ERROR_HANDLING_SRCS = $(SRC_DIR)/error_handling/ft_assert.c \
	$(SRC_DIR)/error_handling/ft_error_msg.c

FILES_SRCS = $(SRC_DIR)/files/get_next_line.c $(SRC_DIR)/files/get_next_line_utils.c

LINKED_LISTS_SRCS = $(SRC_DIR)/files/linked_lists/ft_lstadd_back_bonus.c \
	$(SRC_DIR)/files/linked_lists/ft_lstadd_front_bonus.c $(SRC_DIR)/files/linked_lists/ft_lstclear_bonus.c \
	$(SRC_DIR)/files/linked_lists/ft_lstdelone_bonus.c $(SRC_DIR)/files/linked_lists/ft_lstdup.c \
	$(SRC_DIR)/files/linked_lists/ft_lstfind.c $(SRC_DIR)/files/linked_lists/ft_lstinsert.c \
	$(SRC_DIR)/files/linked_lists/ft_lstiter_bonus.c $(SRC_DIR)/files/linked_lists/ft_lstlast_bonus.c \
	$(SRC_DIR)/files/linked_lists/ft_lstmap_bonus.c $(SRC_DIR)/files/linked_lists/ft_lstmap_inplace.c \
	$(SRC_DIR)/files/linked_lists/ft_lstmerge.c \
	$(SRC_DIR)/files/linked_lists/ft_lstnew_bonus.c $(SRC_DIR)/files/linked_lists/ft_lstremove_at.c \
	$(SRC_DIR)/files/linked_lists/ft_lstreverse.c $(SRC_DIR)/files/linked_lists/ft_lstsize_bonus.c

MALLOC_FREE_SRCS = $(SRC_DIR)/malloc_free/ft_2dclear.c $(SRC_DIR)/malloc_free/ft_calloc.c \
	$(SRC_DIR)/malloc_free/ft_check_malloc.c $(SRC_DIR)/malloc_free/ft_malloc_array.c \
	$(SRC_DIR)/malloc_free/ft_realloc.c $(SRC_DIR)/malloc_free/ft_safe_calloc.c \
	$(SRC_DIR)/malloc_free/ft_safe_free.c $(SRC_DIR)/malloc_free/ft_safe_malloc.c

MEMORY_MANAGEMENT_SRCS = $(SRC_DIR)/memory_management/ft_bzero.c \
	$(SRC_DIR)/memory_management/ft_memchr.c $(SRC_DIR)/memory_management/ft_memcmp.c \
	$(SRC_DIR)/memory_management/ft_memcpy.c $(SRC_DIR)/memory_management/ft_memdup.c \
	$(SRC_DIR)/memory_management/ft_memmove.c $(SRC_DIR)/memory_management/ft_memset.c

PRINTING_SRCS = $(SRC_DIR)/printing/ft_print_array.c $(SRC_DIR)/printing/ft_printf.c \
	$(SRC_DIR)/printing/ft_putchar.c $(SRC_DIR)/printing/ft_putchar_fd.c $(SRC_DIR)/printing/ft_putendl_fd.c \
	$(SRC_DIR)/printing/ft_putint.c $(SRC_DIR)/printing/ft_putnbr_base.c $(SRC_DIR)/printing/ft_putnbr.c \
	$(SRC_DIR)/printing/ft_putnbr_fd.c $(SRC_DIR)/printing/ft_putnbr_unsigned.c \
	$(SRC_DIR)/printing/ft_putstr.c $(SRC_DIR)/printing/ft_putstr_fd.c $(SRC_DIR)/printing/ft_putstr_red.c

UTILS_SRCS = $(SRC_DIR)/utils/ft_isalnum.c $(SRC_DIR)/utils/ft_isalpha.c \
	$(SRC_DIR)/utils/ft_isascii.c $(SRC_DIR)/utils/ft_isdigit.c $(SRC_DIR)/utils/ft_isprint.c \
	$(SRC_DIR)/utils/ft_isspace.c $(SRC_DIR)/utils/ft_tolower.c $(SRC_DIR)/utils/ft_toupper.c \
	$(SRC_DIR)/utils/remove_newline.c

SRCS = $(ARRAY_SRCS) $(ARRAY_OF_STRINGS_SRCS) $(CONVERSIONS_SRCS) $(ERROR_HANDLING_SRCS) \
	$(FILES_SRCS) $(LINKED_LISTS_SRCS) $(MALLOC_FREE_SRCS) $(MEMORY_MANAGEMENT_SRCS) \
	$(PRINTING_SRCS) $(UTILS_SRCS)

OBJS = $(SRCS:.c=.o)

# Règles
all: $(NAME)
	@printf "$(CLEAR)$(GREEN)✓ Compilation complete: $(NAME)$(RESET)\n"

$(NAME): $(OBJS)
	@printf "$(CLEAR)$(GREEN)► Creating library archive$(RESET)\n"
	@$(AR) $(NAME) $(OBJS)

bonus: $(NAME)

clean:
	@printf "$(YELLOW)► Cleaning object files...$(RESET)\n"
	@rm -f $(OBJS)
	@printf "$(GREEN)✓ Clean complete$(RESET)\n"

fclean: clean
	@printf "$(YELLOW)► Removing $(NAME)...$(RESET)\n"
	@rm -f $(NAME)
	@printf "$(GREEN)✓ Full clean complete$(RESET)\n"

re: fclean all

# Compilation des objets avec barre de progression
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@$(call progress_bar)

.PHONY: all clean fclean re bonus
