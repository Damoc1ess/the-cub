# Compilation flags
CFLAGS = -Wall -Wextra -Werror -g -I include -I libft
# CFLAGS =-g -I include -I libft

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
	@mkdir -p $(@D) # Crée le répertoire parent pour l'objet
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

# Marque les règles comme "phonie"
.PHONY: all clean fclean re
