#include "../../include/cub.h"

void	init_struct(t_cub *cub)
{
	cub->north_texture = strdup(NORTH);
	cub->south_texture = strdup(SOUTH);
	cub->west_texture = strdup(WEST);
	cub->east_texture = strdup(EAST);
	cub->floor_color = -1;
	cub->ceiling_color = -1;
	cub->map = NULL;
	cub->map_width = 0;
	cub->map_height = 0;
	cub->player_x = -1;
	cub->player_y = -1;
	cub->player_angle = 0;
	cub->mlx = NULL;
	cub->window = NULL;
}
