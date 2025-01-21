#include "../../include/cub.h"

// Fonction utilitaire : saute les espaces en début de ligne
char	*skip_spaces(char *line)
{
	while (*line && ft_isspace(*line))
		line++;
	return (line);
}

// Fonction utilitaire : parse une couleur (ex: "220,100,0")
int	parse_color(char *line)
{
	char	*trimmed;

	int r, g, b;
	trimmed = skip_spaces(line);
	if (sscanf(trimmed, "%d,%d,%d", &r, &g, &b) != 3)
	{
		printf("Error: Invalid color format\n");
		exit(EXIT_FAILURE);
	}
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
	{
		printf("Error: Color values must be between 0 and 255\n");
		exit(EXIT_FAILURE);
	}
	return ((r << 16) | (g << 8) | b); // Combine RGB en un int
}

// Fonction principale : parse la scène
void	parse_scene(char **map, t_scene *scene)
{
	int		i;
	char	*line;

	i = 0;
	// Initialisation de la structure
	scene->north_texture = NULL;
	scene->south_texture = NULL;
	scene->west_texture = NULL;
	scene->east_texture = NULL;
	scene->floor_color = -1;
	scene->ceiling_color = -1;
	while (map[i])
	{
		line = skip_spaces(map[i]);
		if (strncmp(line, "NO ", 3) == 0)
			scene->north_texture = strdup(line + 3);
		else if (strncmp(line, "SO ", 3) == 0)
			scene->south_texture = strdup(line + 3);
		else if (strncmp(line, "WE ", 3) == 0)
			scene->west_texture = strdup(line + 3);
		else if (strncmp(line, "EA ", 3) == 0)
			scene->east_texture = strdup(line + 3);
		else if (strncmp(line, "F ", 2) == 0)
			scene->floor_color = parse_color(line + 2);
		else if (strncmp(line, "C ", 2) == 0)
			scene->ceiling_color = parse_color(line + 2);
		else if (*line == '1') // Début de la map (lignes de murs)
			break ;
		else if (*line != '\0') // Lignes non valides
		{
			printf("Error: Invalid line in scene: %s\n", line);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	// Vérification des éléments obligatoires
	if (!scene->north_texture || !scene->south_texture || !scene->west_texture
		|| !scene->east_texture || scene->floor_color == -1
		|| scene->ceiling_color == -1)
	{
		printf("Error: Missing scene elements\n");
		exit(EXIT_FAILURE);
	}
	printf("Scene parsed successfully!\n");
}
