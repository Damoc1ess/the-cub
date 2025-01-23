/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 08:53:57 by fflamion          #+#    #+#             */
/*   Updated: 2025/01/23 09:22:57 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../cub.h"

typedef struct s_scene
{
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	int		floor_color;
	int		ceiling_color;
}			t_scene;

typedef struct s_map
{
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	int		floor_color;
	int		ceiling_color;
	char	**map;
	int		map_start;
	size_t	map_width;
	size_t	map_height;
	float	player_x;
	float	player_y;
	float	player_angle;
	void	*mlx;
	void	*window;
	t_scene	scene;
}			t_map;

// parsing
void		parsing(int argc, char **argv, t_map *cub);

// init
void		init_struct(t_map *cub);

// pars_arg
void		pars_arg(int argc, char **argv);

// pars_maps
void		pars_maps(char *map, t_map *cub);
int			parse_color(char *line);

// pars_map_utils1
int			is_valid_map_char(char c);
void		validate_map_lines(t_map *cub);
void		check_closed_map(t_map *cub);
void		check_player(t_map *cub);

// pars_map_utils2
void		map_error(char *message, char *info);

// pars_scene
void		parse_scene(char **map, t_scene *scene, t_map *cub);

// init_map
void		init_map(t_map *cub);

// debug
void		print_struct(t_map *cub);
void		print_map(t_map *cub);
#endif
