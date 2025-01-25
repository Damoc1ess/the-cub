/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblanc <mblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 12:22:46 by mblanc            #+#    #+#             */
/*   Updated: 2025/01/25 12:40:04 by mblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	compute_ray(t_game *game, t_ray *ray, int x, int screen_width)
{
	double	camera_pos;

	camera_pos = 2.0 * x / (double)screen_width - 1.0;
	ray->dir_x = game->player.dir_x + game->player.plane_x * camera_pos;
	ray->dir_y = game->player.dir_y + game->player.plane_y * camera_pos;
	ray->camera = camera_pos;
	ray->grid_x = (int)game->player.x;
	ray->grid_y = (int)game->player.y;
	ray->found_wall = 0;
}

void	init_steps_and_side_dist(t_game *game, t_ray *ray)
{
	ray->delta_x = fabs(1.0 / ray->dir_x);
	ray->delta_y = fabs(1.0 / ray->dir_y);
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_x = (game->player.x - ray->grid_x) * ray->delta_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_x = (ray->grid_x + 1.0 - game->player.x) * ray->delta_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_y = (game->player.y - ray->grid_y) * ray->delta_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_y = (ray->grid_y + 1.0 - game->player.y) * ray->delta_y;
	}
}

int	perform_dda(t_game *game, t_ray *ray, int *side_ptr)
{
	int	wall_found;

	wall_found = 0;
	while (!wall_found)
	{
		if (ray->side_x < ray->side_y)
		{
			ray->side_x += ray->delta_x;
			ray->grid_x += ray->step_x;
			*side_ptr = 0;
		}
		else
		{
			ray->side_y += ray->delta_y;
			ray->grid_y += ray->step_y;
			*side_ptr = 1;
		}
		if (game->map[ray->grid_x][ray->grid_y] == '1')
			wall_found = 1;
	}
	return (wall_found);
}

double	compute_perp_wall_dist(t_game *game, t_ray *ray, int side)
{
	if (!side)
		ray->dist = (ray->grid_x - game->player.x + (1 - ray->step_x) / 2.0)
			/ ray->dir_x;
	else
		ray->dist = (ray->grid_y - game->player.y + (1 - ray->step_y) / 2.0)
			/ ray->dir_y;
	return (ray->dist);
}

double	init_and_dda(t_game *game, int x, int screen_width, int *side_ptr)
{
	t_ray	ray;

	compute_ray(game, &ray, x, screen_width);
	init_steps_and_side_dist(game, &ray);
	perform_dda(game, &ray, side_ptr);
	compute_perp_wall_dist(game, &ray, *side_ptr);
	return (ray.dist);
}
