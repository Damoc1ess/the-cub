/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblanc <mblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 21:56:58 by mblanc            #+#    #+#             */
/*   Updated: 2025/01/23 22:02:55 by mblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	render_frame(t_game *game)
{
	int screen_width = SCREEN_WIDTH;
	int screen_height = SCREEN_HEIGHT;
	int x;

	for (x = 0; x < screen_width; x++)
	{
		// Calcul de la position et direction du rayon
		double camera_x = 2 * x / (double)screen_width - 1; // Position du rayon sur l'axe caméra
		double ray_dir_x = game->player.dir_x + game->player.plane_x * camera_x;
		double ray_dir_y = game->player.dir_y + game->player.plane_y * camera_x;

		// Position initiale sur la carte
		int map_x = (int)game->player.x;
		int map_y = (int)game->player.y;

		// Longueur du rayon à partir de sa position initiale
		double side_dist_x;
		double side_dist_y;

		// Longueur entre deux intersections avec une ligne de la grille
		double delta_dist_x = fabs(1 / ray_dir_x);
		double delta_dist_y = fabs(1 / ray_dir_y);
		double perp_wall_dist;

		// Direction à prendre (+1 ou -1) et quelle case vérifier
		int step_x;
		int step_y;

		// Indique si on a touché un mur ou non
		int hit = 0;
		int side;

		// Calcul des distances initiales
		if (ray_dir_x < 0)
		{
			step_x = -1;
			side_dist_x = (game->player.x - map_x) * delta_dist_x;
		}
		else
		{
			step_x = 1;
			side_dist_x = (map_x + 1.0 - game->player.x) * delta_dist_x;
		}
		if (ray_dir_y < 0)
		{
			step_y = -1;
			side_dist_y = (game->player.y - map_y) * delta_dist_y;
		}
		else
		{
			step_y = 1;
			side_dist_y = (map_y + 1.0 - game->player.y) * delta_dist_y;
		}

		// DDA : Digital Differential Analysis
		while (hit == 0)
		{
			// Avance au prochain carré
			if (side_dist_x < side_dist_y)
			{
				side_dist_x += delta_dist_x;
				map_x += step_x;
				side = 0;
			}
			else
			{
				side_dist_y += delta_dist_y;
				map_y += step_y;
				side = 1;
			}
			// Vérifie si le rayon a touché un mur
			if (game->map[map_x][map_y] == '1') hit = 1;
		}

		// Calcul de la distance projetée sur la caméra
		if (side == 0)
			perp_wall_dist = (map_x - game->player.x + (1 - step_x) / 2) / ray_dir_x;
		else
			perp_wall_dist = (map_y - game->player.y + (1 - step_y) / 2) / ray_dir_y;

		// Calcul de la hauteur de la ligne à dessiner
		int line_height = (int)(screen_height / perp_wall_dist);

		// Calcul des positions de début et de fin de la ligne
		int draw_start = -line_height / 2 + screen_height / 2;
		if (draw_start < 0) draw_start = 0;
		int draw_end = line_height / 2 + screen_height / 2;
		if (draw_end >= screen_height) draw_end = screen_height - 1;

		// Couleur du mur (modifiez en fonction du côté)
		int color = (side == 0) ? 0xFFFFFF : 0xAAAAAA;

		// Dessine la ligne (mur) sur l'écran
		for (int y = draw_start; y <= draw_end; y++)
		{
			int offset = y * game->image.line_length + x * (game->image.bpp / 8);
			*(unsigned int *)(game->image.addr + offset) = color;
		}
	}

	// Affiche l'image dans la fenêtre
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->image.img, 0, 0);
}
