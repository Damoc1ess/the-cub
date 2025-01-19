
# # CFLAGS = -Wall -Werror -Wextra  -Ilibft -g
# CGLAGS = -g -I includes -g3 -I libft

# LIBFT_TARGET = libft/libft.a

# SRC_DIR = src
# SRC_FILES = $(shell find src -name '*.c')
# OBJS = $(SRC_FILES:.c=.o)

# NAME = cub3d

# all: $(NAME)

# $(NAME): $(OBJS) $(LIBFT_TARGET)
# 	gcc $(CFLAGS) $(OBJS) -L libft -l ft -l -o $(NAME)

# %.o: %.c
# 	gcc $(CFLAGS) -c $< -o $@

# $(LIBFT_TARGET):
# 	make -C libft

# clean:
# 	make clean -C libft
# 	rm -f $(OBJS)

# fclean: clean
# 	make fclean -C libft
# 	rm -f $(NAME)

# re: fclean all


# .PHONY: all clean fclean re leak
# Compilation flags
CFLAGS = -Wall -Wextra -Werror -g -I includes -I libft

# Nom de l'exécutable
NAME = cub3d

# Répertoires
SRC_DIR = src
OBJ_DIR = obj
LIBFT_DIR = libft

# Fichiers sources et objets
SRC_FILES = $(shell find $(SRC_DIR) -name '*.c')
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

# Librairie Libft
LIBFT_TARGET = $(LIBFT_DIR)/libft.a

# Règle principale
all: $(NAME)

# Compilation de l'exécutable
$(NAME): $(OBJS) $(LIBFT_TARGET)
	@echo "🔧 Linking $(NAME)..."
	gcc $(CFLAGS) $(OBJS) -L $(LIBFT_DIR) -lft -o $(NAME)
	@echo "✅ Build complete: $(NAME)"

# Compilation des fichiers objets
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@echo "🔨 Compiling $<..."
	gcc $(CFLAGS) -c $< -o $@

# Création du répertoire obj
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Compilation de Libft
$(LIBFT_TARGET):
	@echo "🔧 Building libft..."
	make -C $(LIBFT_DIR)

# Nettoyage des fichiers objets
clean:
	@echo "🧹 Cleaning object files..."
	make clean -C $(LIBFT_DIR)
	rm -rf $(OBJ_DIR)

# Nettoyage complet
fclean: clean
	@echo "🧹 Cleaning executable and libft..."
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

# Rebuild complet
re: fclean all

# Test pour vérifier les fuites mémoire
leak: all
	@valgrind --leak-check=full --track-origins=yes ./$(NAME)

# Marque les règles comme "phonie"
.PHONY: all clean fclean re leak
