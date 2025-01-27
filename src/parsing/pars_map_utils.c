/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 22:32:24 by fflamion          #+#    #+#             */
/*   Updated: 2025/01/25 19:05:58 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

int	is_valid_map_char(char c)
{
	if (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E' || c == 'W'
		|| c == ' ')
		return (1);
	return (0);
}

void	validate_map_lines(t_cub *cub)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j])
		{
			if (!is_valid_map_char(cub->map[i][j]))
				map_error("Invalid character in map", NULL, cub);
			j++;
		}
		i++;
	}
}

int	check_around(t_cub *cub, size_t i, size_t j)
{
	if (cub->map[i - 1][j] == ' ' || cub->map[i + 1][j] == ' ' || cub->map[i][j
		- 1] == ' ' || cub->map[i][j + 1] == ' ' || cub->map[i - 1][j] == '\0'
		|| cub->map[i + 1][j] == '\0' || cub->map[i][j - 1] == '\0'
		|| cub->map[i][j + 1] == '\0')
		return (1);
	return (0);
}

void	check_closed_map(t_cub *cub)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < cub->map_height)
	{
		j = 0;
		while (j < cub->map_width)
		{
			if (cub->map[i][j] == '0')
			{
				if (i == 0 || i == cub->map_height - 1 || j == 0
					|| j == cub->map_width - 1)
					map_error("Error: Map is not closed.", NULL, cub);
				if (check_around(cub, i, j))
				{
					printf("x = %zu, y = %zu\n", i, j);
					map_error("Error: Map is not closed.", NULL, cub);
				}
			}
			j++;
		}
		i++;
	}
}

void	check_player(t_cub *cub)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < cub->map_height)
	{
		j = 0;
		while (j < cub->map_width)
		{
			if (cub->map[i][j] == 'N' || cub->map[i][j] == 'S'
				|| cub->map[i][j] == 'E' || cub->map[i][j] == 'W')
			{
				cub->player_x = j + 0.5;
				cub->player_y = i + 0.5;
			}
			j++;
		}
		i++;
	}
}
