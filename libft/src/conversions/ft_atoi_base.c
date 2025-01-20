/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:41:17 by fflamion          #+#    #+#             */
/*   Updated: 2024/09/07 13:42:31 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			validate_base(char *base);
long int	calculate_power_of_base(char *str, char	*base);
long int	calcul_value(char chiffre, char *base);
int			ft_atoi_base(char *str, char *base);
long int	ft_recursive_power(long int nb, long int power);
//int	verifinbase(char ctotest, char *base);
/*
int	verifinbase(char ctotest, char *base)
{
	while (*base)
	{
		if (ctotest == *base)
			return (1);
		base ++;
	}
	return (0);
}
*/

long int	ft_recursive_power(long int nb, long int power)
{
	if (power < 0)
	{
		return (0);
	}
	if (power == 0)
	{
		return (1);
	}
	return (nb *= ft_recursive_power(nb, power - 1));
}

int	validate_base(char *base)
{
	int	i;
	int	j;

	j = 0;
	while (base[j])
	{
		i = j + 1;
		if (base[j] == '+' || base[j] == '-')
			return (0);
		if ((9 <= base[j] && base[j] <= 13) || base[j] == 32)
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

long int	calculate_power_of_base(char *str, char	*base)
{
	long int	power;

	power = -1;
	while ((9 <= *str && *str <= 13) || *str == 32)
		str ++;
	while (*str == '-' || *str == '+')
	{
		str ++;
	}
	while (calcul_value(*str, base) >= 0)
	{
		power ++;
		str ++;
	}
	return (power);
}

long int	calcul_value(char chiffre, char *base)
{
	long int	i;

	i = 0;
	while (*base)
	{
		if (chiffre == *base)
			return (i);
		i ++;
		base ++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int			sign;
	long int	result;
	long int	power;
	int			size;

	result = 0;
	sign = 1;
	power = calculate_power_of_base(str, base);
	size = validate_base(base);
	while ((9 <= *str && *str <= 13) || *str == 32)
		str ++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str ++;
	}
	while (calcul_value(*str, base) && size != 0)
	{
		result += calcul_value(*str, base) * ft_recursive_power(size, power);
		str ++;
		power --;
	}
	return (result * sign);
}
