/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_array_iter_error.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 21:56:48 by fflamion          #+#    #+#             */
/*   Updated: 2024/09/17 12:16:29 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_array_iter_error(char **tab, int i)
{
	while (i > 0)
	{
		free(tab[--i]);
	}
	free(tab);
}
