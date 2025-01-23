/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mathis.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblanc <mblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 09:55:00 by mblanc            #+#    #+#             */
/*   Updated: 2025/01/23 22:05:48 by mblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATHIS_H
# define MATHIS_H

/* Libs standard */
# include "cub.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
/* Définitions des touches (codes pour clavier AZERTY ou QWERTY) */
# define KEY_ESC 53
# define KEY_UP 13
# define KEY_DOWN 1
# define KEY_LEFT 0
# define KEY_RIGHT 2
# define ARROW_LEFT 123
# define ARROW_RIGHT 124

/* Paramètres généraux */
# define SCREEN_WIDTH 1024
# define SCREEN_HEIGHT 768
# define FOV 60
# define TEXTURE_SIZE 64

/* Structures */

/* Structure pour une image dans MinilibX */
typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}			t_image;

/* Structure pour les données de la fenêtre et de la minilibX */
typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}			t_mlx;

/* Structure pour stocker les textures */
typedef struct s_textures
{
	t_image	north;
	t_image	south;
	t_image	west;
	t_image	east;
	int		floor_color;
	int		ceiling_color;
}			t_textures;

/* Structure pour le joueur */
typedef struct s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	move_speed;
	double	rot_speed;
}			t_player;

/* Structure principale */
typedef struct s_game
{
	t_mlx mlx;           // Connexion MLX et fenêtre
	t_textures textures; // Textures et couleurs
	t_player player;     // Données sur le joueur
	char **map;          // Carte du jeu
	int map_width;       // Largeur de la carte
	int map_height;      // Hauteur de la carte
	t_image image;       // Image principale pour le dessin (ciel/sol)
}			t_game;

int			close_window(t_game *game);
int			handle_events(t_game *game);
int			init_window(t_game *game);
void	render_frame(t_game *game);
void	draw_sky_and_floor(t_game *game, int sky_color, int floor_color);
void	init_test_map(t_game *game);

#endif