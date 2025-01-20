/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:47:08 by fflamion          #+#    #+#             */
/*   Updated: 2024/09/07 13:42:31 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	antierrorbase(char *base)
{
	int	i;
	int	j;

	j = 0;
	while (base[j])
	{
		i = j + 1;
		if (base[j] == '+' || base[j] == '-')
			return (0);
		if (base[j] < 32 || base[j] >= 127)
			return (0);
		while (base[i])
		{
			if (base[i] == base[j])
				return (0);
			i ++;
		}
		j ++;
	}
	if (j <= 1)
		return (0);
	return (j);
}

int	ft_putnbr_b(unsigned long nbr, char *base)
{
	int		base_size;
	char	buffer[33];
	int		i;
	int		count;

	i = 0;
	base_size = antierrorbase(base);
	if (base_size == 0)
		return (0);
	if (nbr == 0)
	{
		ft_putchar(base[0]);
		return (1);
	}
	while (nbr > 0)
	{
		buffer[i++] = base[nbr % base_size];
		nbr /= base_size;
	}
	count = i;
	while (i > 0)
		ft_putchar(buffer[--i]);
	return (count);
}

/*
int	ft_putnbr_b(unsigned long nbr, char *base)
{
	unsigned long	size_base;
	static int		count = 0;
	int				temp;

	size_base = antierrorbase(base);
	if (size_base == 0)
		return (-1);
	else
	{
		if (nbr >= size_base)
			ft_putnbr_b(nbr / size_base, base);
		write(1, &base[nbr % size_base], 1);
		count++;
	}
	return (count);
}
*/

/*
void	ft_putnbr_base(int nbr, char *base)
{
	int	size_base;

	size_base = antierrorbase(base);
	if (size_base == 0)
		return ;
	if (nbr == -2147483648)
	{
		ft_putnbr_base(nbr / size_base, base);
		write(1, base + -(nbr % size_base), 1);
	}
	else if (nbr < 0)
	{
		write(1, "-", 1);
		ft_putnbr_base(-nbr, base);
	}
	else
	{
		if (nbr >= size_base)
			ft_putnbr_base(nbr / size_base, base);
		write(1, &base[nbr % size_base], 1);
	}
}
*/