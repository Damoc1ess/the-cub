/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_newline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:31:29 by fflamion          #+#    #+#             */
/*   Updated: 2024/09/17 12:00:24 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*remove_newline(void *content)
{
	char	*str;
	size_t	len;

	str = (char *)content;
	len = ft_strlen (str);
	if (len > 0 && str[len - 1] == '\n')
		str[len - 1] = '\0';
	return (content);
}
