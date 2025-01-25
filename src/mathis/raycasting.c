/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblanc <mblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 21:56:58 by mblanc            #+#    #+#             */
/*   Updated: 2025/01/25 12:28:02 by mblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

// Function that destroy an image if it already exists and create a new one

void	create_image(t_game *game)
{
	if (game->image.img != NULL)
		mlx_destroy_image(game->mlx.mlx, game->image.img);
	game->image.img = mlx_new_image(game->mlx.mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (game->image.img == NULL)
	{
		perror("Failed to create an image");
		exit(EXIT_FAILURE);
	}
	game->image.addr = mlx_get_data_addr(game->image.img, &game->image.bpp,
			&game->image.line_length, &game->image.endian);
}

void	cast_rays(t_game *game)
{
	int		screen_width;
	int		screen_height;
	int		x;
	double	dist;
	int		side;

	screen_width = SCREEN_WIDTH;
	screen_height = SCREEN_HEIGHT;
	x = 0;
	while (x < screen_width)
	{
		dist = init_and_dda(game, x, screen_width, &side);
		draw_column(game, x, dist, side, screen_height);
		x++;
	}
}

void	draw_column(t_game *game, int x, double dist, int side, int sh)
{
	int lh, y, de, ds, c, o;
	lh = (int)(sh / dist);
	ds = -lh / 2 + sh / 2;
	if (ds < 0)
		ds = 0;
	de = lh / 2 + sh / 2;
	if (de >= sh)
		de = sh - 1;
	if (side == 0)
		c = 0xFFFFFF;
	else
		c = 0xAAAAAA;
	y = ds;
	while (y <= de)
	{
		o = y * game->image.line_length + x * (game->image.bpp / 8);
		*(unsigned int *)(game->image.addr + o) = c;
		y++;
	}
}

void	render_frame(t_game *game)
{
	draw_sky_and_floor(game, 0x87CEEB, 0x654321);
	cast_rays(game);
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->image.img, 0,
		0);
}

// void	render_frame(t_game *game)
// {
// 	// Recréer une nouvelle image
// 	if (game->image.img)
// 		mlx_destroy_image(game->mlx.mlx, game->image.img);
// 	game->image.img = mlx_new_image(game->mlx.mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
// 	if (!game->image.img)
// 	{
// 		perror("Failed to create an image");
// 		exit(EXIT_FAILURE);
// 	}
// 	game->image.addr = mlx_get_data_addr(game->image.img, &game->image.bpp,
// 			&game->image.line_length, &game->image.endian);

// 	// Redessiner le ciel et le sol
// 	draw_sky_and_floor(game, 0x87CEEB, 0x654321);

// 	// Raycasting pour afficher les murs
// 	int screen_width = SCREEN_WIDTH;
// 	int screen_height = SCREEN_HEIGHT;
// 	int x;

// 	for (x = 0; x < screen_width; x++)
// 	{
// 		double camera_x = 2 * x / (double)screen_width - 1;
// 		double ray_dir_x = game->player.dir_x + game->player.plane_x * camera_x;
// 		double ray_dir_y = game->player.dir_y + game->player.plane_y * camera_x;

// 		int map_x = (int)game->player.x;
// 		int map_y = (int)game->player.y;

// 		double side_dist_x;
// 		double side_dist_y;

// 		double delta_dist_x = fabs(1 / ray_dir_x);
// 		double delta_dist_y = fabs(1 / ray_dir_y);
// 		double perp_wall_dist;

// 		int step_x;
// 		int step_y;

// 		int hit = 0;
// 		int side;

// 		if (ray_dir_x < 0)
// 		{
// 			step_x = -1;
// 			side_dist_x = (game->player.x - map_x) * delta_dist_x;
// 		}
// 		else
// 		{
// 			step_x = 1;
// 			side_dist_x = (map_x + 1.0 - game->player.x) * delta_dist_x;
// 		}
// 		if (ray_dir_y < 0)
// 		{
// 			step_y = -1;
// 			side_dist_y = (game->player.y - map_y) * delta_dist_y;
// 		}
// 		else
// 		{
// 			step_y = 1;
// 			side_dist_y = (map_y + 1.0 - game->player.y) * delta_dist_y;
// 		}

// 		while (hit == 0)
// 		{
// 			if (side_dist_x < side_dist_y)
// 			{
// 				side_dist_x += delta_dist_x;
// 				map_x += step_x;
// 				side = 0;
// 			}
// 			else
// 			{
// 				side_dist_y += delta_dist_y;
// 				map_y += step_y;
// 				side = 1;
// 			}
// 			if (game->map[map_x][map_y] == '1')
// 				hit = 1;
// 		}

// 		if (side == 0)
// 			perp_wall_dist = (map_x - game->player.x + (1 - step_x) / 2)
// / ray_dir_x;
// 		else
// 			perp_wall_dist = (map_y - game->player.y + (1 - step_y) / 2)
// / ray_dir_y;

// 		int line_height = (int)(screen_height / perp_wall_dist);

// 		int draw_start = -line_height / 2 + screen_height / 2;
// 		if (draw_start < 0)
// 			draw_start = 0;
// 		int draw_end = line_height / 2 + screen_height / 2;
// 		if (draw_end >= screen_height)
// 			draw_end = screen_height - 1;

// 		int color = (side == 0) ? 0xFFFFFF : 0xAAAAAA;

// 		for (int y = draw_start; y <= draw_end; y++)
// 		{
// 			int offset = y * game->image.line_length + x * (game->image.bpp
// / 8);
// 			*(unsigned int *)(game->image.addr + offset) = color;
// 		}
// 	}

// 	// Afficher l'image finale dans la fenêtre
// 	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->image.img, 0,
// 0);
// }
