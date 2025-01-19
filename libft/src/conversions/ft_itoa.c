/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:12:06 by fflamion          #+#    #+#             */
/*   Updated: 2024/09/07 13:42:31 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_num_len(int n)
{
	int		len;
	long	n_long;

	len = 1;
	n_long = n;
	if (n_long < 0)
	{
		n_long = -n_long;
		len++;
	}
	while (n_long / 10 != 0)
	{
		n_long /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	n_long;
	int		len;
	char	*str;

	n_long = n;
	len = get_num_len(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n_long < 0)
	{
		str[0] = '-';
		n_long = -n_long;
	}
	if (n_long == 0)
		str[0] = '0';
	while (n_long != 0)
	{
		str[--len] = (n_long % 10) + '0';
		n_long /= 10;
	}
	return (str);
}
