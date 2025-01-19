/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:33:46 by fflamion          #+#    #+#             */
/*   Updated: 2024/10/28 12:37:13 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strtok_find_sep(char *str, const char *sep)
{
	size_t	i;

	while (*str)
	{
		i = 0;
		while (sep[i])
		{
			if (*str == sep[i])
				return (str);
			i++;
		}
		str++;
	}
	return (NULL);
}

char	*ft_strtok(char *str, const char *sep)
{
	static char	*next;
	char		*start;

	if (str)
		next = str;
	if (!next || !*next)
		return (NULL);
	start = next;
	next = ft_strtok_find_sep(start, sep);
	if (next)
	{
		*next = '\0';
		next++;
	}
	if (*start != '\0')
		return (start);
	else
		return (NULL);
}
