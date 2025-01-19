/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_2d_array_length.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 11:42:05 by fflamion          #+#    #+#             */
/*   Updated: 2024/09/17 12:33:48 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	get_2d_array_length(char **map)
{
	int	len;

	len = 0;
	while (map[len] != NULL)
		len++;
	return (len);
}
