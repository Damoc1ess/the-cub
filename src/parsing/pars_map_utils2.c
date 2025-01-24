/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 22:33:16 by fflamion          #+#    #+#             */
/*   Updated: 2025/01/24 09:19:28 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

void	map_error(char *message, char *info, t_cub *cub)
{
	if (cub)
		free_cub(cub);
	printf("Error.\n%s %s\n", message, info);
	exit(EXIT_FAILURE);
}
