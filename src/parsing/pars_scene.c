/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 22:34:04 by fflamion          #+#    #+#             */
/*   Updated: 2025/01/23 08:59:30 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

char	*skip_spaces(char *line)
{
	while (*line && ft_isspace(*line))
		line++;
	return (line);
}

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

char	*trim_spaces(char *str)
{
	char	*start;
	char	*end;
	char	*result;
	size_t	len;

	if (!str)
		return (NULL);
	start = str;
	while (*start && ft_isspace(*start)) // pour les espaces au debut
		start++;
	end = start + strlen(start) - 1;
	while (end > start && ft_isspace(*end)) // pour les espaces a la fin
		end--;
	len = end - start + 1;
	result = malloc(len + 1);
	if (!result)
	{
		perror("Error: malloc failed in trim_spaces");
		exit(EXIT_FAILURE);
	}
	strncpy(result, start, len);
	result[len] = '\0';
	return (result);
}

void	parse_scene(char **map, t_scene *scene, t_map *cub)
{
	int		i;
	char	*line;
	char	*trimmed;

	i = 0;
	while (map[i])
	{
		line = skip_spaces(map[i]);
		if (ft_strncmp(line, "NO", 2) == 0 && ft_isspace(line[2]))
		{
			trimmed = trim_spaces(line + 2);
			scene->north_texture = strdup(trimmed);
			free(trimmed);
		}
		else if (ft_strncmp(line, "SO", 2) == 0 && ft_isspace(line[2]))
		{
			trimmed = trim_spaces(line + 2);
			scene->south_texture = strdup(trimmed);
			free(trimmed);
		}
		else if (ft_strncmp(line, "WE", 2) == 0 && ft_isspace(line[2]))
		{
			trimmed = trim_spaces(line + 2);
			scene->west_texture = strdup(trimmed);
			free(trimmed);
		}
		else if (ft_strncmp(line, "EA", 2) == 0 && ft_isspace(line[2]))
		{
			trimmed = trim_spaces(line + 2);
			scene->east_texture = strdup(trimmed);
			free(trimmed);
		}
		else if (ft_strncmp(line, "F", 1) == 0 && ft_isspace(line[1]))
		{
			trimmed = trim_spaces(line + 1);
			scene->floor_color = parse_color(trimmed);
			free(trimmed);
		}
		else if (ft_strncmp(line, "C", 1) == 0 && ft_isspace(line[1]))
		{
			trimmed = trim_spaces(line + 1);
			scene->ceiling_color = parse_color(trimmed);
			free(trimmed);
		}
		else if (*line == '1') // Début de la map
		{
			cub->map_start = i;
			break ;
		}
		else if (*line != '\0')
		{
			printf("Error: Invalid line in scene: %s\n", line);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	if (!scene->north_texture || !scene->south_texture || !scene->west_texture
		|| !scene->east_texture || scene->floor_color == -1
		|| scene->ceiling_color == -1)
		map_error("Missing scene information", NULL);
}
