/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strPreppend.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:07:42 by fflamion          #+#    #+#             */
/*   Updated: 2024/11/12 15:21:00 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strpreppend(char *str, char *topreppend)
{
	char	*newstr;
	int		i;
	int		y;

	y = -1;
	i = -1;
	newstr = malloc(ft_strlen(str) + ft_strlen(topreppend) + 1);
	if (!(newstr))
		return (NULL);
	while (topreppend[++i])
		newstr[i] = topreppend[i];
	while (str[++y])
		newstr[i++] = str[y];
	newstr[i++] = '\0';
	return (newstr);
}
