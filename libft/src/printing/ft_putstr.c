/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:29:31 by fflamion          #+#    #+#             */
/*   Updated: 2024/09/17 12:02:20 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(const char *str)
{
	int	count;

	count = 0;
	if (!str)
		return (0);
	while (*str)
	{
		write(1, str, 1);
		str++;
		count++;
	}
	return (count);
}
