/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate_string_array.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 11:41:36 by fflamion          #+#    #+#             */
/*   Updated: 2024/09/17 12:15:54 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	**duplicate_string_array(char **src)
{
	size_t	i;
	char	**dest;

	i = 0;
	dest = malloc((get_2d_array_length(src) + 1) * sizeof(char *));
	if (dest == NULL)
		return (NULL);
	while (src[i] != NULL)
	{
		dest[i] = malloc((ft_strlen(src[i]) + 1) * sizeof(char));
		if (dest[i] == NULL)
		{
			while (i > 0)
				free(dest[--i]);
			free(dest[i]);
			return (NULL);
		}
		ft_strcpy(dest[i], src[i]);
		i++;
	}
	dest[i] = NULL;
	return (dest);
}
