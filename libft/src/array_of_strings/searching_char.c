/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searching_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:50:21 by fflamion          #+#    #+#             */
/*   Updated: 2024/09/17 12:17:40 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	searching_char(char **array, char character, int *row, int *col)
{
	int		i;
	char	*str;
	char	*found;

	i = 0;
	while (array[i] != NULL)
	{
		str = array[i];
		found = ft_strchr (str, character);
		if (found != NULL)
		{
			*row = i;
			*col = found - str;
			return ;
		}
		i++;
	}
	*row = -1;
	*col = -1;
}
