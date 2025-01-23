/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblanc <mblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 22:04:39 by mblanc            #+#    #+#             */
/*   Updated: 2025/01/23 23:03:02 by mblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include <stdlib.h>

void	init_test_map(t_game *game)
{
	static char	*test_map[] = {
		"111111111",
		"100000001",
		"111111111",
		"100000001",
		"110000011",
		"100000001",
		"100011101",
		"111111111",
		NULL
	};

	game->map = test_map;
	game->map_width = 9;  // Largeur de la carte
	game->map_height = 8; // Hauteur de la carte

	// Position du joueur dans une case vide
	game->player.x = 4.5; // Au centre d'une case vide
	game->player.y = 4.5; // Au centre d'une case vide

	// Initialisation des directions et du champ de vision
	game->player.dir_x = 1.0;   // Direction horizontale (droite)
	game->player.dir_y = 0.0;   // Pas de composante verticale
	game->player.plane_x = 0.0; // Plan caméra horizontal
	game->player.plane_y = 0.66; // Plan caméra vertical

	// Création de l'image
	game->image.img = mlx_new_image(game->mlx.mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!game->image.img)
	{
		perror("Failed to create an image");
		exit(EXIT_FAILURE);
	}
	game->image.addr = mlx_get_data_addr(game->image.img, &game->image.bpp,
			&game->image.line_length, &game->image.endian);

	// Dessiner le premier cadre
	render_frame(game);
}

