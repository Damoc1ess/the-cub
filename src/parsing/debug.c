/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 22:33:40 by fflamion          #+#    #+#             */
/*   Updated: 2025/01/23 13:13:57 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

void	print_map(t_cub *cub)
{
	int	i;

	i = 0;
	while (cub->map[i])
	{
		printf("%s\n", cub->map[i]);
		i++;
	}
	printf("map_width: %ld\n", cub->map_width);
	printf("map_height: %ld\n", cub->map_height);
}

void	print_scene(t_scene *scene)
{
	printf("north_texture: %s\n", scene->north_texture);
	printf("south_texture: %s\n", scene->south_texture);
	printf("west_texture: %s\n", scene->west_texture);
	printf("east_texture: %s\n", scene->east_texture);
	printf("floor_color: %d\n", scene->floor_color);
	printf("ceiling_color: %d\n", scene->ceiling_color);
}

void	print_struct(t_cub *cub)
{
	printf("north_texture: %s\n", cub->north_texture);
	printf("south_texture: %s\n", cub->south_texture);
	printf("west_texture: %s\n", cub->west_texture);
	printf("east_texture: %s\n", cub->east_texture);
	printf("floor_color: %d\n", cub->floor_color);
	printf("ceiling_color: %d\n", cub->ceiling_color);
	print_map(cub);
	printf("map_width: %ld\n", cub->map_width);
	printf("map_height: %ld\n", cub->map_height);
	printf("player_x: %f\n", cub->player_x);
	printf("player_y: %f\n", cub->player_y);
	printf("player_angle: %f\n", cub->player_angle);
	print_scene(&cub->scene);
}
