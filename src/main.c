/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblanc <mblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 22:34:15 by fflamion          #+#    #+#             */
/*   Updated: 2025/01/23 22:36:23 by mblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	main(void)
{
	t_game	game;
	int sky_color = 0x87CEEB;  // Bleu ciel
	int floor_color = 0x654321; // Brun (terre)
	// Initialiser la fenêtre
	if (init_window(&game) != 0)
		return (1);

	// Charger une carte de test et initialiser le joueur
	init_test_map(&game);
	draw_sky_and_floor(&game, sky_color, floor_color);

	// Ajouter les hooks pour la boucle MLX
	mlx_hook(game.mlx.win, 17, 0, close_window, &game);
	mlx_hook(game.mlx.win, 2, 1L << 0, handle_keypress, &game);
	mlx_loop_hook(game.mlx.mlx, handle_events, &game);

	// Lancer la boucle principale
	mlx_loop(game.mlx.mlx);

	return (0);
}

