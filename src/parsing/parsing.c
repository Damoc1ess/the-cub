/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 22:34:07 by fflamion          #+#    #+#             */
/*   Updated: 2025/01/22 22:34:08 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

void	parsing(int argc, char **argv, t_cub *cub)
{
	pars_arg(argc, argv);
	pars_maps(argv[1], cub);
}
