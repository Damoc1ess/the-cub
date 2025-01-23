/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblanc <mblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:01:36 by mblanc            #+#    #+#             */
/*   Updated: 2025/01/23 23:10:52 by mblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	init_window(t_game *game)
{
	game->mlx.mlx = mlx_init();
	if (!game->mlx.mlx)
	{
		perror("Failed to initialize mlx");
		return (1);
	}
	game->mlx.win = mlx_new_window(game->mlx.mlx, SCREEN_WIDTH, SCREEN_HEIGHT,
			"Cub3D");
	if (!game->mlx.win)
	{
		perror("Failed to create window");
		return (1);
	}
	return (0);
}

int	handle_events(t_game *game)
{
	if (game == NULL || game->mlx.win == NULL || game->mlx.mlx == NULL)
		return (1);
	render_frame(game);
	// Handle window close event
	// printf("event detected\n");
	return (0);
}

int	close_window(t_game *game)
{
	if (game == NULL || game->mlx.mlx == NULL || game->mlx.win == NULL)
		return (1);
	mlx_destroy_window(game->mlx.mlx, game->mlx.win);
	mlx_destroy_display(game->mlx.mlx);
	free(game->mlx.mlx);
	exit(0);
}

int	handle_keypress(int keycode, t_game *game)
{
	double move_speed = 0.1; // Vitesse de déplacement
	double rot_speed = 0.05; // Vitesse de rotation
	printf("Key pressed: %d\n", keycode);
	if (keycode == 119) // W
		move_forward(game, move_speed);
	else if (keycode == 115) // S
		move_backward(game, move_speed);
	else if (keycode == 97) // A
		move_left(game, move_speed);
	else if (keycode == 100) // D
		move_right(game, move_speed);
	else if (keycode == 65363) // Flèche gauche
		rotate_left(game, rot_speed);
	else if (keycode == 65361) // Flèche droite
		rotate_right(game, rot_speed);
	else if (keycode == 65307) // Échap
		close_window(game); // Quitte proprement le jeu
	// Redessiner la frame après chaque mouvement
	render_frame(game);
	return (0);
}
