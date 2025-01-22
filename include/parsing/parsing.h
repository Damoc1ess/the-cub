#ifndef PARSING_H
# define PARSING_H

typedef struct s_scene
{
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	int		floor_color;
	int		ceiling_color;
}			t_scene;

typedef struct s_cub
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
}			t_cub;

// parsing
void		parsing(int argc, char **argv, t_cub *cub);

// init
void		init_struct(t_cub *cub);

// pars_arg
void		pars_arg(int argc, char **argv);

// pars_maps
void		pars_maps(char *map, t_cub *cub);
int			parse_color(char *line);

// pars_map_utils1
int			is_valid_map_char(char c);
void		validate_map_lines(t_cub *cub);
void		check_closed_map(t_cub *cub);
void		check_player(t_cub *cub);

// pars_map_utils2
void		map_error(char *message, char *info);

// pars_scene
void		parse_scene(char **map, t_scene *scene, t_cub *cub);

// init_map
void		init_map(t_cub *cub);

// debug
void		print_struct(t_cub *cub);
void		print_map(t_cub *cub);
#endif
