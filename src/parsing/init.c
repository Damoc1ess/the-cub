/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 22:33:47 by fflamion          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/01/23 08:59:30 by fflamion         ###   ########.fr       */
=======
/*   Updated: 2025/01/23 17:13:45 by fflamion         ###   ########.fr       */
>>>>>>> flo
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

void	init_struct(t_map *cub)
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
	cub->scene.north_texture = NULL;
	cub->scene.south_texture = NULL;
	cub->scene.west_texture = NULL;
	cub->scene.east_texture = NULL;
	cub->scene.floor_color = -1;
	cub->scene.ceiling_color = -1;
}
