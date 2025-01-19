/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:32:49 by fflamion          #+#    #+#             */
/*   Updated: 2024/09/07 13:42:31 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_itoa_base(int n, char *buffer, int *len)
{
	long	num;

	num = n;
	*len = 0;
	if (num < 0)
		num = -num;
	if (num == 0)
		buffer[(*len)++] = '0';
	while (num > 0)
	{
		buffer[(*len)++] = (num % 10) + '0';
		num /= 10;
	}
}

int	ft_putnbr(int n)
{
	char	buffer[12];
	int		len;
	int		count;

	count = 0;
	len = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		ft_putchar('-');
		count++;
	}
	ft_itoa_base(n, buffer, &len);
	count += len;
	while (len > 0)
		ft_putchar(buffer[--len]);
	return (count);
}

/*
int	ft_putnbr(int n)
{
	static int	count = 0;
	int			temp;

	if (n == -2147483648)
		return (ft_putstr("-2147483648"), 11);
	else
	{
		if (n < 0)
		{
			ft_putchar('-');
			count++;
			n = -n;
		}
		if (n >= 10)
			ft_putnbr(n / 10);
		count++;
		ft_putchar((n % 10) + '0');
	}
	if (n < 10)
	{
		temp = count;
		count = 0;
		return (temp);
	}
	return (count);
}
*/
