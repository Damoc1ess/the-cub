/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 08:53:57 by fflamion          #+#    #+#             */
/*   Updated: 2025/01/23 09:22:57 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

void	init_scene(t_scene *scene)
{
	scene->north_texture = NULL;
	scene->south_texture = NULL;
	scene->west_texture = NULL;
	scene->east_texture = NULL;
	scene->floor_color = -1;
	scene->ceiling_color = -1;
}

void	init_struct(t_cub *cub)
{
	cub->north_texture = ft_strdup(NORTH);
	cub->south_texture = ft_strdup(SOUTH);
	cub->west_texture = ft_strdup(WEST);
	cub->east_texture = ft_strdup(EAST);
	cub->floor_color = -1;
	cub->ceiling_color = -1;
	cub->map = NULL;
	cub->map_width = 0;
	cub->map_height = 0;
	cub->player_x = -1;
	cub->player_y = -1;
	cub->player_angle = 0;
	cub->mlx = NULL;
	cub->window = NULL;
	init_scene(&cub->scene);
}
