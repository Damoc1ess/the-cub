#include "../../include/cub.h"

void	parsing(int argc, char **argv, t_cub *cub)
{
	pars_arg(argc, argv);
	pars_maps(argv[1], cub);
}
