#include "../../include/cub.h"
#include "../../libft/includes/ft_array.h"

void	free_cub(t_cub *cub)
{
	if (cub->north_texture)
		free(cub->north_texture);
	if (cub->south_texture)
		free(cub->south_texture);
	if (cub->west_texture)
		free(cub->west_texture);
	if (cub->east_texture)
		free(cub->east_texture);
	if (cub->map)
		ft_free_split(cub->map);
	if (cub->scene.north_texture)
		free(cub->scene.north_texture);
	if (cub->scene.south_texture)
		free(cub->scene.south_texture);
	if (cub->scene.west_texture)
		free(cub->scene.west_texture);
	if (cub->scene.east_texture)
		free(cub->scene.east_texture);
}
