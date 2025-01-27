/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 22:33:44 by fflamion          #+#    #+#             */
/*   Updated: 2025/01/23 08:59:30 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

void	init_map(t_cub *cub)
{
	size_t	map_width;
	int		i;

	i = 0;
	map_width = 0;
	while (cub->map[i])
	{
		map_width = ft_strlen(cub->map[i]);
		if (map_width > cub->map_width)
			cub->map_width = map_width;
		i++;
	}
}
