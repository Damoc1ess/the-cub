/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:14:12 by fflamion          #+#    #+#             */
/*   Updated: 2024/09/17 11:14:14 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*handle_read_handle(char *next_line)
{
	if (get_nl(next_line))
		next_line = gnl_substr(next_line, 0, get_nl(next_line));
	else if (!gnl_strlen(next_line))
	{
		if (next_line)
			free(next_line);
		return (NULL);
	}
	return (next_line);
}

char	*handle_read(int fd, char *buffer, char *next_line)
{
	int		b_read;

	b_read = 1;
	while (b_read > 0 && !get_nl(next_line))
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		buffer[b_read] = '\0';
		if (b_read < 0)
		{
			free(next_line);
			return (NULL);
		}
		next_line = gnl_strjoin(next_line, buffer);
		if (!next_line || gnl_strlen(next_line) == 0)
		{
			if (next_line)
				free(next_line);
			return (NULL);
		}
	}
	return (handle_read_handle(next_line));
}

void	remove_begin(char *buffer)
{
	int		i;
	int		first_nl;

	i = 0;
	first_nl = get_nl(buffer);
	while (i + first_nl < (int)gnl_strlen(buffer))
	{
		buffer[i] = buffer[i + first_nl];
		i++;
	}
	buffer[i] = '\0';
}

char	*move_buf_nl(char *buffer, char **next_line)
{
	int		i;

	i = 0;
	*next_line = gnl_calloc(sizeof(char), gnl_strlen(buffer) + 1);
	while (i < (int)gnl_strlen(buffer))
	{
		(*next_line)[i] = buffer[i];
		i++;
	}
	(*next_line)[i] = '\0';
	return (*next_line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*next_line;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	i = 0;
	next_line = move_buf_nl(buffer, &next_line);
	next_line = handle_read(fd, buffer, next_line);
	if (!next_line)
	{
		while (i < BUFFER_SIZE)
		{
			buffer[i] = '\0';
			i++;
		}
		buffer[i] = '\0';
		return (NULL);
	}
	remove_begin(buffer);
	return (next_line);
}
