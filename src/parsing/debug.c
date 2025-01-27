/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathis <mathis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:46:33 by mathis            #+#    #+#             */
/*   Updated: 2025/01/27 16:46:38 by mathis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../include/cub.h"

void	print_scene(t_scene *scene)
{
	printf("Scene:\n");
	printf("North texture: %s\n", scene->north_texture);
	printf("South texture: %s\n", scene->south_texture);
	printf("West texture: %s\n", scene->west_texture);
	printf("East texture: %s\n", scene->east_texture);
	printf("Floor color: %d\n", scene->floor_color);
	printf("Ceiling color: %d\n", scene->ceiling_color);
}

void	print_map(t_cub *cub)
{
	int	i;

	i = 0;
	printf("\nMap:\n");
	while (cub->map[i])
	{
		printf("%s\n", cub->map[i]);
		i++;
	}
	printf("\nMap width: %zu\n", cub->map_width);
	printf("Map height: %zu\n", cub->map_height);
	printf("Player position: (%f, %f)\n", cub->player_x, cub->player_y);
	printf("Player angle: %f\n", cub->player_angle);
}

void	print_struct(t_cub *cub)
{
	printf("\nCub3D structure:\n");
	printf("North texture: %s\n", cub->north_texture);
	printf("South texture: %s\n", cub->south_texture);
	printf("West texture: %s\n", cub->west_texture);
	printf("East texture: %s\n", cub->east_texture);
	printf("Floor color: %d\n", cub->floor_color);
	printf("Ceiling color: %d\n", cub->ceiling_color);
	print_map(cub);
	print_scene(&cub->scene);
}
