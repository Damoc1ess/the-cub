/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathis <mathis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:47:00 by mathis            #+#    #+#             */
/*   Updated: 2025/01/27 16:47:02 by mathis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		map_error("Error opening file", file_path, cub);
	map_content = ft_strdup("");
	if (!map_content)
	{
		close(fd);
		map_error("Error allocating memory", NULL, cub);
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
			map_error("Error allocating memory", NULL, cub);
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
		map_error("Error allocating memory", NULL, cub);
}

void	extract_map(t_cub *cub, int start_map)
{
	size_t	j;
	char	**map_only;

	printf("start_map: %d\n", start_map);
	j = 0;
	while (cub->map[start_map + j])
		j++;
	cub->map_height = j;
	map_only = malloc(sizeof(char *) * (j + 1));
	if (!map_only)
		map_error("Allocating memory", NULL, cub);
	j = 0;
	while (cub->map[start_map])
		map_only[j++] = ft_strdup(cub->map[start_map++]);
	map_only[j] = NULL;
	ft_free_split(cub->map);
	cub->map = map_only;
}

void	pars_maps(char *map, t_cub *cub)
{
	mapping(map, cub);
	parse_scene(cub);
	extract_map(cub, 6);
	init_map(cub);
	validate_map_lines(cub);
	check_player(cub);
	check_closed_map(cub);
	validate_scene_textures(&cub->scene);
}
