#include "../../include/cub.h"

void	pars_arg(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Error.\nInvalid number of arguments.\n");
		exit(EXIT_FAILURE);
	}
	if (!is_good_extension(argv[1], ".cub"))
	{
		printf("Error.\nInvalid file.\n");
		exit(EXIT_FAILURE);
	}
	if (!file_existe(argv[1]))
	{
		printf("Error.\nFile does not exist.\n");
		exit(EXIT_FAILURE);
	}
	if (!is_directory(argv[1]))
	{
		printf("Error.\nFile is a directory.\n");
		exit(EXIT_FAILURE);
	}
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	is_map_char_valid(char c)
{
	return (c == '0' || c == '1' || c == '2' || c == 'N' || c == 'S' || c == 'E'
		|| c == 'W' || c == ' ');
}

char	**parse_map(int fd, t_cub *cub)
{
	char	*line;
	char	**map;
	int		rows;
	int		max_width;
	int		len;

	map = NULL;
	rows = 0;
	max_width = 0;
	while ((line = get_next_line(fd)))
	{
		if (line[0] == '\n' || line[0] == '\0')
		{ // Ignorez les lignes vides
			free(line);
			continue ;
		}
		// Vérifiez que les caractères de la ligne sont valides
		for (int i = 0; line[i]; i++)
		{
			if (!is_map_char_valid(line[i]))
			{
				printf("Error.\nInvalid character '%c' in map.\n", line[i]);
				free(line);
				return (NULL);
			}
		}
		// Trouvez la largeur maximale
		len = strlen(line);
		if (len > max_width)
			max_width = len;
		// Stockez la ligne dans le tableau
		map = realloc(map, sizeof(char *) * (rows + 1));
		map[rows] = strdup(line);
		rows++;
		free(line);
	}
	// Ajoutez une ligne NULL à la fin pour marquer la fin du tableau
	map = realloc(map, sizeof(char *) * (rows + 1));
	map[rows] = NULL;
	cub->map = map;
	cub->map_height = rows;
	cub->map_width = max_width;
	return (map);
}

void	parsing(int argc, char **argv, t_cub *cub)
{
	pars_arg(argc, argv);
	pars_maps(argv[1], cub);
}
