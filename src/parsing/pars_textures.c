#include "../../include/map.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// int	is_xpm_file(const char *filename)
// {
// 	size_t	len;

// 	if (!filename)
// 		return (0);
// 	len = strlen(filename);
// 	if (len < 4)
// 		return (0);
// 	return (strcmp(filename + len - 4, ".xpm") == 0);
// }

// Vérifie si le fichier existe et est accessible
void	validate_texture(const char *texture_path, const char *identifier)
{
	int	fd;

	if (!texture_path || *texture_path == '\0')
	{
		printf("Error: %s texture path is missing or invalid.\n", identifier);
		exit(EXIT_FAILURE);
	}
	// if (!is_xpm_file(texture_path))
	// {
	// 	printf("Error: %s texture file '%s' is not an .xpm file.\n", identifier,
	// 		texture_path);
	// 	exit(EXIT_FAILURE);
	// }
	fd = open(texture_path, O_RDONLY);
	if (fd < 0)
	{
		printf("Error: Failed to open texture file %s", texture_path);
		exit(EXIT_FAILURE);
	}
	close(fd);
}

void	validate_scene_textures(t_scene *scene)
{
	validate_texture(scene->north_texture, "North");
	validate_texture(scene->south_texture, "South");
	validate_texture(scene->west_texture, "West");
	validate_texture(scene->east_texture, "East");
}
