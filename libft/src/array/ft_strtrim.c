/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 00:15:06 by fflamion          #+#    #+#             */
/*   Updated: 2024/09/07 13:42:31 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_in_set(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		end;
	int		i;
	char	*trimmed;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && is_in_set(*s1, set))
		s1++;
	end = ft_strlen(s1);
	while (end > 0 && is_in_set(s1[end - 1], set))
		end--;
	trimmed = (char *)malloc(sizeof(char) * (end + 1));
	if (!trimmed)
		return (NULL);
	i = 0;
	while (i < end)
	{
		trimmed[i] = s1[i];
		i++;
	}
	trimmed[end] = '\0';
	return (trimmed);
}
