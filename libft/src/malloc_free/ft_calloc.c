/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 00:08:36 by fflamion          #+#    #+#             */
/*   Updated: 2024/09/07 13:42:31 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*output;
	char	*initializing_chain;
	size_t	i;
	size_t	total_size;

	total_size = num * size;
	output = malloc(total_size);
	if (!output && total_size != 0)
		return (NULL);
	initializing_chain = (char *)output;
	i = 0;
	while (i < total_size)
		initializing_chain[i++] = 0;
	return (output);
}
