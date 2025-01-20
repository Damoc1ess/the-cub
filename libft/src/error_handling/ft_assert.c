/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:34:18 by fflamion          #+#    #+#             */
/*   Updated: 2024/09/17 12:33:09 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_assert(int condition, const char *msg)
{
	if (!condition && msg)
	{
		while (*msg)
		{
			write(2, msg, 1);
			msg++;
		}
		write(2, "\n", 1);
		_exit (1);
	}
}
