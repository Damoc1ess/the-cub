/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 22:33:52 by fflamion          #+#    #+#             */
/*   Updated: 2025/01/22 22:33:53 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	is_good_extension(char *arg)
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

void	pars_arg(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Error.\nInvalid number of arguments.\n");
		exit(EXIT_FAILURE);
	}
	if (!is_good_extension(argv[1]))
	{
		printf("Error.\nInvalid file.\n");
		exit(EXIT_FAILURE);
	}
	if (!file_existe(argv[1]))
	{
		printf("Error.\nFile does not exist.\n");
		exit(EXIT_FAILURE);
	}
	if (!is_directory(argv[1]))
	{
		printf("Error.\nFile is a directory.\n");
		exit(EXIT_FAILURE);
	}
}
