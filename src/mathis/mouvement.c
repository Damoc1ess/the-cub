/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblanc <mblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 22:21:35 by mblanc            #+#    #+#             */
/*   Updated: 2025/01/23 22:25:56 by mblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	move_forward(t_game *game, double move_speed)
{
	double new_x = game->player.x + game->player.dir_x * move_speed;
	double new_y = game->player.y + game->player.dir_y * move_speed;

	// Vérifie si le joueur peut avancer sans heurter un mur
	if (game->map[(int)new_x][(int)game->player.y] != '1')
		game->player.x = new_x;
	if (game->map[(int)game->player.x][(int)new_y] != '1')
		game->player.y = new_y;
}
void	move_backward(t_game *game, double move_speed)
{
	double new_x = game->player.x - game->player.dir_x * move_speed;
	double new_y = game->player.y - game->player.dir_y * move_speed;

	// Vérifie si le joueur peut reculer sans heurter un mur
	if (game->map[(int)new_x][(int)game->player.y] != '1')
		game->player.x = new_x;
	if (game->map[(int)game->player.x][(int)new_y] != '1')
		game->player.y = new_y;
}
void	move_left(t_game *game, double move_speed)
{
	double new_x = game->player.x - game->player.plane_x * move_speed;
	double new_y = game->player.y - game->player.plane_y * move_speed;

	// Vérifie si le joueur peut se déplacer sans heurter un mur
	if (game->map[(int)new_x][(int)game->player.y] != '1')
		game->player.x = new_x;
	if (game->map[(int)game->player.x][(int)new_y] != '1')
		game->player.y = new_y;
}
void	move_right(t_game *game, double move_speed)
{
	double new_x = game->player.x + game->player.plane_x * move_speed;
	double new_y = game->player.y + game->player.plane_y * move_speed;

	// Vérifie si le joueur peut se déplacer sans heurter un mur
	if (game->map[(int)new_x][(int)game->player.y] != '1')
		game->player.x = new_x;
	if (game->map[(int)game->player.x][(int)new_y] != '1')
		game->player.y = new_y;
}

void	rotate_left(t_game *game, double rot_speed)
{
	double old_dir_x = game->player.dir_x;
	double old_plane_x = game->player.plane_x;

	// Mise à jour de la direction
	game->player.dir_x = game->player.dir_x * cos(rot_speed) - game->player.dir_y * sin(rot_speed);
	game->player.dir_y = old_dir_x * sin(rot_speed) + game->player.dir_y * cos(rot_speed);

	// Mise à jour du plan caméra
	game->player.plane_x = game->player.plane_x * cos(rot_speed) - game->player.plane_y * sin(rot_speed);
	game->player.plane_y = old_plane_x * sin(rot_speed) + game->player.plane_y * cos(rot_speed);
}

void	rotate_right(t_game *game, double rot_speed)
{
	double old_dir_x = game->player.dir_x;
	double old_plane_x = game->player.plane_x;

	// Mise à jour de la direction
	game->player.dir_x = game->player.dir_x * cos(-rot_speed) - game->player.dir_y * sin(-rot_speed);
	game->player.dir_y = old_dir_x * sin(-rot_speed) + game->player.dir_y * cos(-rot_speed);

	// Mise à jour du plan caméra
	game->player.plane_x = game->player.plane_x * cos(-rot_speed) - game->player.plane_y * sin(-rot_speed);
	game->player.plane_y = old_plane_x * sin(-rot_speed) + game->player.plane_y * cos(-rot_speed);
}
