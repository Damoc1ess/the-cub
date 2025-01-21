#include "../../include/cub.h"
#include "../../libft/includes/ft_array.h"
#include "../../libft/includes/ft_array_of_strings.h"
#include "../../libft/includes/get_next_line.h"

void	mapping(char *file_path, t_cub *cub)
{
	int		fd;
	char	*line;
	char	*map_content;
	char	*tmp;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		map_error("Error opening file", file_path);
	map_content = ft_strdup("");
	if (!map_content)
	{
		close(fd);
		map_error("Error allocating memory", NULL);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		tmp = map_content;
		map_content = ft_strjoin(map_content, line);
		free(tmp);
		free(line);
		if (!map_content)
		{
			close(fd);
			map_error("Error allocating memory", NULL);
		}
	}
	close(fd);
	if (*map_content == '\0')
	{
		printf("Error: map file is empty.\n");
		free(map_content);
		exit(EXIT_FAILURE);
	}
	cub->map = ft_split(map_content, '\n');
	free(map_content);
	if (!cub->map)
		map_error("Error allocating memory", NULL);
}

// i = 0;
// while (cub->map[i])
// 	i++;
// cub->map_height = i - 7;
// i = 0;
// while (cub->map[i])
// {
// 	line_length = ft_strlen(cub->map[i]);
// 	if (cub->map_width < line_length)
// 		cub->map_width = line_length;
// 	i++;
// }
// }

// int	parse_color(char *line)
// {
// 	char	**colors;

// 	int r, g, b;
// 	colors = ft_split(line, ',');
// 	if (!colors || get_2d_array_length(colors) != 3)
// 		map_error("EInvalid color format", line);
// 	r = ft_atoi(colors[0]);
// 	g = ft_atoi(colors[1]);
// 	b = ft_atoi(colors[2]);
// 	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
// 		map_error("Invalid color value", line);
// 	ft_free_split(colors);
// 	return (r << 16 | g << 8 | b);
// }

void	extract_map(t_cub *cub)
{
	int		i;
	int		j;
	char	**map_only;

	i = 0;
	while (cub->map[i] && (ft_strncmp(cub->map[i], "NO ", 3) == 0
			|| ft_strncmp(cub->map[i], "SO ", 3) == 0 || ft_strncmp(cub->map[i],
				"WE ", 3) == 0 || ft_strncmp(cub->map[i], "EA ", 3) == 0
			|| ft_strncmp(cub->map[i], "F ", 2) == 0 || ft_strncmp(cub->map[i],
				"C ", 2) == 0 || ft_strlen(cub->map[i]) == 0))
		i++;
	j = 0;
	printf("i + j = %d\n", i + j);
	while (cub->map[i + j])
		j++;
	map_only = malloc(sizeof(char *) * (j + 1));
	if (!map_only)
		map_error("Allocating memory", NULL);
	j = 0;
	while (cub->map[i])
		map_only[j++] = ft_strdup(cub->map[i++]);
	map_only[j] = NULL;
	ft_free_split(cub->map);
	cub->map = map_only;
}

void	pars_maps(char *map, t_cub *cub)
{
	mapping(map, cub);
	parse_scene(cub->map, &cub->scene);
	extract_map(cub);
	print_struct(cub);
	validate_map_lines(cub);
	check_player(cub);
	check_closed_map(cub);
}
