#include "../../include/cub.h"

void	print_struct(t_cub *cub)
{
	int	i;

	i = 0;
	printf("north_texture: %s\n", cub->north_texture);
	printf("south_texture: %s\n", cub->south_texture);
	printf("west_texture: %s\n", cub->west_texture);
	printf("east_texture: %s\n", cub->east_texture);
	printf("floor_color: %d\n", cub->floor_color);
	printf("ceiling_color: %d\n", cub->ceiling_color);
	while (cub->map[i])
	{
		printf("%s\n", cub->map[i]);
		i++;
	}
	printf("map_width: %ld\n", cub->map_width);
	printf("map_height: %ld\n", cub->map_height);
	printf("player_x: %f\n", cub->player_x);
	printf("player_y: %f\n", cub->player_y);
	printf("player_angle: %f\n", cub->player_angle);
}
