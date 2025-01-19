/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:14:17 by fflamion          #+#    #+#             */
/*   Updated: 2024/09/17 11:14:20 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

int	get_nl(char *buf)
{
	int	i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

void	*gnl_calloc(size_t n, size_t size)
{
	void			*allocated;
	size_t			i;
	unsigned char	*location;

	i = 0;
	if (n == 0 || size == 0)
	{
		allocated = malloc(0);
		if (!allocated)
			return (NULL);
		return (allocated);
	}
	else if (n * size < size || n * size < n)
		return (NULL);
	allocated = (void *)malloc(n * size);
	if (!allocated)
		return (NULL);
	location = (unsigned char *)allocated;
	while (i < (n * size))
	{
		location[i] = 0;
		i++;
	}
	return (allocated);
}

char	*gnl_strjoin(char *old, char *tmp)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	new = malloc(sizeof(char) * (gnl_strlen(old) + gnl_strlen(tmp) + 1));
	if (!new)
		return (NULL);
	while (old && old[i])
	{
		new[i] = old[i];
		i++;
	}
	while (tmp && tmp[j])
	{
		new[i + j] = tmp[j];
		j++;
	}
	new[i + j] = '\0';
	if (old)
		free(old);
	return (new);
}

char	*gnl_substr(char *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	if (start >= i)
		len = 0;
	else if (start + len >= i)
		len = i - start;
	new_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (len && s[start + i] && i < len)
	{
		new_str[i] = s[start + i];
		i++;
	}
	new_str[i] = '\0';
	if (s)
		free(s);
	return (new_str);
}
