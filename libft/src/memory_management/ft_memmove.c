/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 00:08:20 by fflamion          #+#    #+#             */
/*   Updated: 2024/09/07 13:42:31 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*cpy_d;
	const unsigned char	*cpy_s;

	if (n == 0)
		return (dest);
	if (dest == NULL && src == NULL)
		return (NULL);
	cpy_d = (unsigned char *)dest;
	cpy_s = (const unsigned char *)src;
	if (cpy_d < cpy_s)
		while (n--)
			*cpy_d++ = *cpy_s++;
	else
	{
		cpy_s = cpy_s + (n - 1);
		cpy_d = cpy_d + (n - 1);
		while (n--)
			*cpy_d-- = *cpy_s--;
	}
	return (dest);
}
