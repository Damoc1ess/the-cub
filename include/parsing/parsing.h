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
	int		map_width;
	int		map_height;
	float	player_x;
	float	player_y;
	float	player_angle;
	void	*mlx;
	void	*window;
}			t_cub;

// Parsing
void		parsing(int argc, char **argv, t_cub *cub);

// init
void		init_struct(t_cub *cub);

// Parsing_utils_1
int			is_good_extension(char *arg, char *extension);
int			file_existe(char *file);
int			is_directory(const char *file);

// Parsing_utils_2

#endif
