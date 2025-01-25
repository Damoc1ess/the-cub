/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblanc <mblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 21:37:48 by mblanc            #+#    #+#             */
/*   Updated: 2025/01/25 12:20:35 by mblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	put_pixel_to_image(char *data, int x, int y, int color, int line_length,
		int bpp)
{
	int	offset;

	offset = (y * line_length) + (x * (bpp / 8));
	*(unsigned int *)(data + offset) = color;
}

void	draw_sky_and_floor(t_game *game, int sky_color, int floor_color)
{
	int	offset;

	int x, y;
	// Créer une nouvelle image et récupérer ses données
	game->image.img = mlx_new_image(game->mlx.mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!game->image.img)
	{
		perror("Error: Failed to create image");
		exit(1);
	}
	game->image.addr = mlx_get_data_addr(game->image.img, &game->image.bpp,
			&game->image.line_length, &game->image.endian);
	// Dessiner le ciel
	for (y = 0; y < SCREEN_HEIGHT / 2; y++)
	{
		for (x = 0; x < SCREEN_WIDTH; x++)
		{
			offset = y * game->image.line_length + x * (game->image.bpp / 8);
			*(unsigned int *)(game->image.addr + offset) = sky_color;
		}
	}
	// Dessiner le sol
	for (y = SCREEN_HEIGHT / 2; y < SCREEN_HEIGHT; y++)
	{
		for (x = 0; x < SCREEN_WIDTH; x++)
		{
			offset = y * game->image.line_length + x * (game->image.bpp / 8);
			*(unsigned int *)(game->image.addr + offset) = floor_color;
		}
	}
	// Afficher l'image sur la fenêtre
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->image.img, 0,
		0);
}
