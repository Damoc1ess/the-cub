/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathis <mathis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:46:53 by mathis            #+#    #+#             */
/*   Updated: 2025/01/27 16:46:53 by mathis           ###   ########.fr       */
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

void	parse_scene(t_cub *cub)
{
	int		i;
	char	*line;
	char	*trimmed;

	i = 0;
	while (cub->map[i])
	{
		line = skip_spaces(cub->map[i]);
		if (ft_strncmp(line, "NO", 2) == 0 && ft_isspace(line[2]))
		{
			trimmed = trim_spaces(line + 2);
			cub->scene.north_texture = strdup(trimmed);
			free(trimmed);
		}
		else if (ft_strncmp(line, "SO", 2) == 0 && ft_isspace(line[2]))
		{
			trimmed = trim_spaces(line + 2);
			cub->scene.south_texture = strdup(trimmed);
			free(trimmed);
		}
		else if (ft_strncmp(line, "WE", 2) == 0 && ft_isspace(line[2]))
		{
			trimmed = trim_spaces(line + 2);
			cub->scene.west_texture = strdup(trimmed);
			free(trimmed);
		}
		else if (ft_strncmp(line, "EA", 2) == 0 && ft_isspace(line[2]))
		{
			trimmed = trim_spaces(line + 2);
			cub->scene.east_texture = strdup(trimmed);
			free(trimmed);
		}
		else if (ft_strncmp(line, "F", 1) == 0 && ft_isspace(line[1]))
		{
			trimmed = trim_spaces(line + 1);
			cub->scene.floor_color = parse_color(trimmed);
			free(trimmed);
		}
		else if (ft_strncmp(line, "C", 1) == 0 && ft_isspace(line[1]))
		{
			trimmed = trim_spaces(line + 1);
			cub->scene.ceiling_color = parse_color(trimmed);
			free(trimmed);
		}
		else if (*line == '1') // Début de la map
			break ;
		else if (*line != '\0')
		{
			map_error("Invalid line in scene", NULL, cub);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	if (!cub->scene.north_texture || !cub->scene.south_texture
		|| !cub->scene.west_texture || !cub->scene.east_texture
		|| cub->scene.floor_color == -1 || cub->scene.ceiling_color == -1)
		map_error("Missing scene information", NULL, cub);
}
