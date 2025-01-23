/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 22:29:46 by fflamion          #+#    #+#             */
/*   Updated: 2025/01/23 09:11:23 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"
#include "../../libft/includes/ft_array.h"
#include "../../libft/includes/ft_array_of_strings.h"
#include "../../libft/includes/get_next_line.h"

void	mapping(char *file_path, t_map *cub)
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

void	extract_map(t_map *cub, int start_map)
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
		map_error("Allocating memory", NULL);
	j = 0;
	while (cub->map[start_map])
		map_only[j++] = ft_strdup(cub->map[start_map++]);
	map_only[j] = NULL;
	ft_free_split(cub->map);
	cub->map = map_only;
}

void	pars_maps(char *map, t_map *cub)
{
	mapping(map, cub);
	parse_scene(cub->map, &cub->scene, cub);
	extract_map(cub, cub->map_start);
	init_map(cub);
	validate_map_lines(cub);
	check_player(cub);
	check_closed_map(cub);
}
