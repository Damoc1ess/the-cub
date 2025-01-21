#include "../../include/cub.h"

void	map_error(char *message, char *info)
{
	printf("Error.\n%s %s\n", message, info);
	exit(EXIT_FAILURE);
}
