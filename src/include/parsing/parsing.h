#ifndef PARSING_H
# define PARSING_H

typedef struct s_cub
{
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	int		floor_color;
	int		ceiling_color;
	char	**map;
	size_t	map_width;
	size_t	map_height;
	float	player_x;
	float	player_y;
	float	player_angle;
	void	*mlx;
	void	*window;
}			t_map;

// parsing
void		parsing(int argc, char **argv, t_map *cub);

// init
void		init_struct(t_map *cub);

// pars_arg
void		pars_arg(int argc, char **argv);

// pars_maps
void		pars_maps(char *map, t_map *cub);

// debug
void		print_struct(t_map *cub);
#endif
