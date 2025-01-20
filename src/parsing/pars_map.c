#include "../../include/cub.h"
#include "../../libft/includes/get_next_line.h"

void	init_map(char *file_path, t_cub *cub)
{
	int		fd;
	char	*line;
	char	*map_content;
	char	*tmp;
	int		i;
	size_t	line_length;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}
	map_content = strdup("");
	if (!map_content)
	{
		perror("Error allocating memory");
		close(fd);
		exit(EXIT_FAILURE);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		tmp = map_content;
		map_content = ft_strjoin(map_content, line);
		free(tmp);
		free(line);
		if (!map_content)
		{
			perror("Error allocating memory");
			close(fd);
			exit(EXIT_FAILURE);
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
	{
		printf("Error: Malloc failed in ft_split.\n");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (cub->map[i])
		i++;
	cub->map_height = i;
	i = 0;
	while (cub->map[i])
	{
		line_length = ft_strlen(cub->map[i]);
		if (cub->map_width < line_length)
			cub->map_width = line_length;
		i++;
	}
	print_struct(cub);
}

// void	init_map(char *map, t_cub *cub)
// {
// 	int	i;

// 	i = 0;
// 	if (!map || *map == '\0')
// 	{
// 		printf("Error: map is empty or NULL.\n");
// 		exit(EXIT_FAILURE);
// 	}
// 	cub->map = ft_split(map, '\n');
// 	if (!cub->map)
// 	{
// 		printf("Error.\nMalloc failed.\n");
// 		exit(EXIT_FAILURE);
// 	}
// 	while (cub->map[i])
// 	{
// 		printf("%s\n", cub->map[i]);
// 		i++;
// 	}
// 	cub->map_height = i;
// 	i = 0;
// 	while (cub->map[i])
// 	{
// 		if (cub->map_width < ft_strlen(cub->map[i]))
// 			cub->map_width = ft_strlen(cub->map[i]);
// 		i++;
// 	}
// 	print_struct(cub);
// }

void	pars_maps(char *map, t_cub *cub)
{
	init_map(map, cub);
}
