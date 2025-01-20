/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replaceSubStr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:44:38 by fflamion          #+#    #+#             */
/*   Updated: 2024/11/12 15:21:00 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"

static void	copy_newval(char *new_s, int *y, char *newval)
{
	int	z;

	z = 0;
	while (newval[z])
	{
		new_s[*y] = newval[z];
		(*y)++;
		z++;
	}
}

char	*ft_replacesubstr(char *s, char *torep, char *newval)
{
	char	*new_s;
	int		i;
	int		y;

	i = 0;
	y = 0;
	if (!s || !torep || !newval || !ft_strlen(torep) || !ft_strlen(newval))
		return (NULL);
	new_s = (char *)malloc(ft_strlen(s) + ft_strlen(newval) + 1);
	if (!new_s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == torep[0] && !ft_strncmp(s + i, torep, ft_strlen(torep)))
		{
			copy_newval(new_s, &y, newval);
			i += ft_strlen(torep);
		}
		else
			new_s[y++] = s[i++];
	}
	new_s[y] = '\0';
	return (new_s);
}
