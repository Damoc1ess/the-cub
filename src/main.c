/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblanc <mblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 22:34:15 by fflamion          #+#    #+#             */
/*   Updated: 2025/01/23 22:05:37 by mblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	main(void)
{
	t_game	game;

	// Initialiser la fenêtre
	if (init_window(&game) != 0)
		return (1);

	// Charger une carte de test et initialiser le joueur
	init_test_map(&game);

	// Ajouter les hooks pour la boucle MLX
	mlx_hook(game.mlx.win, 17, 0, close_window, &game);
	mlx_loop_hook(game.mlx.mlx, handle_events, &game);

	// Lancer la boucle principale
	mlx_loop(game.mlx.mlx);

	return (0);
}

