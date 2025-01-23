/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblanc <mblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 22:04:39 by mblanc            #+#    #+#             */
/*   Updated: 2025/01/23 22:07:43 by mblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include <stdlib.h>

void	init_test_map(t_game *game)
{
	static char	*test_map_2[] = {"111111", "100001", "100001", "100001",
			"111111", NULL};
	static char	*test_map[] = {"111111111", "100000001", "100100001",
			"100000001", "111011111", "100000001", "100000001", "111111111",
			NULL};

	(void)test_map_2;
	// Exemple de carte minimaliste
	// Charger la carte dans le jeu
	game->map = test_map;
	game->map_width = 6;  // Largeur de la carte
	game->map_height = 5; // Hauteur de la carte
	// Initialiser la position du joueur
	game->player.x = 2.5; // Position X du joueur (centre d'une case)
	game->player.y = 2.5; // Position Y du joueur (centre d'une case)
	game->player.dir_x = 1.0;
	// Direction initiale du joueur (vers la droite)
	game->player.dir_y = 0.0;    // Pas de composante verticale
	game->player.plane_x = 0.0;  // Plan caméra pour le champ de vision
	game->player.plane_y = 0.66; // Largeur du champ de vision (~FOV 66 degrés)
	// Initialiser l'image pour dessiner
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
