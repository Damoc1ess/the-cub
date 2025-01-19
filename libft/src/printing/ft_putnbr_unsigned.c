/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:59:47 by fflamion          #+#    #+#             */
/*   Updated: 2024/09/07 13:42:31 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_unsigned(unsigned long n)
{
	char	buffer[20];
	int		count;
	int		i;

	i = 0;
	count = 0;
	if (n == 0)
	{
		ft_putchar('0');
		return (1);
	}
	while (n > 0)
	{
		buffer[i++] = (n % 10) + '0';
		n /= 10;
	}
	count = i;
	while (i > 0)
	{
		ft_putchar(buffer[--i]);
	}
	return (count);
}

/*
int	ft_putnbr_unsigned(unsigned long n)
{
	static int	count = 0;
	int			temp;

	if (n >= 10)
	{
		ft_putnbr_unsigned(n / 10);
	}
	ft_putchar((n % 10) + '0');
	count++;
	if (n < 10)
	{
		temp = count;
		count = 0;
		return (temp);
	}
	return (count);
}
*/
