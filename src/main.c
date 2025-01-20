#include "../include/cub.h"

int	main(int argc, char **argv)
{
	t_cub	cub;

	init_struct(&cub);
	parsing(argc, argv, &cub);
	return (0);
}
