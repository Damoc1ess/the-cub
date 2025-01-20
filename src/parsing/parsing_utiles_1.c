#include "../../include/cub.h"

void	check_cub(char *arg)
{
	int	len;

	len = ft_strlen(arg);
	if (arg[len - 1] != 'b' || arg[len - 2] != 'u' || arg[len - 3] != 'c'
		|| arg[len - 4] != '.')
	{
		printf("Error.\nInvalid extension.\n");
		exit(EXIT_FAILURE);
	}
}

int	is_good_extension(char *arg, char *extension)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (arg[i])
	{
		if (arg[i] == '.')
			count++;
		i++;
	}
	if (count != 1)
		return (0);
	check_cub(arg);
	return (1);
}

int	file_existe(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}

int	is_directory(const char *file)
{
	int		fd;
	char	buffer[1];

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		if (errno == EISDIR)
		{
			return (0);
		}
		perror("open");
		return (0);
	}
	if (read(fd, buffer, 1) < 0)
	{
		if (errno == EISDIR)
		{
			close(fd);
			return (0);
		}
	}
	close(fd);
	return (1);
}
