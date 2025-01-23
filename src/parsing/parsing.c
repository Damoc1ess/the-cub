/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 22:34:07 by fflamion          #+#    #+#             */
/*   Updated: 2025/01/23 08:59:30 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

void	parsing(int argc, char **argv, t_map *cub)
{
	pars_arg(argc, argv);
	pars_maps(argv[1], cub);
}
