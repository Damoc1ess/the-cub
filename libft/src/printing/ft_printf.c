/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 10:39:45 by fflamion          #+#    #+#             */
/*   Updated: 2024/09/07 13:42:31 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	my_putstr(const char *str)
{
	int	count;

	count = 0;
	if (!str)
	{
		write(1, "(", 1);
		write(1, "n", 1);
		write(1, "u", 1);
		write(1, "l", 1);
		write(1, "l", 1);
		write(1, ")", 1);
		return (6);
	}
	while (*str)
	{
		write(1, str, 1);
		str++;
		count++;
	}
	return (count);
}

int	print_specific(char type, va_list args)
{
	int				c;
	unsigned long	memo;

	c = 0;
	if (type == 'p')
	{
		memo = (unsigned long)va_arg(args, void *);
		if (memo == 0)
			return (ft_putstr("(nil)"), 4);
		ft_putstr("0x");
		c = 2;
		c += ft_putnbr_b(memo, "0123456789abcdef");
	}
	else if (type == 'd' || type == 'i')
		c = ft_putnbr(va_arg(args, int));
	else if (type == 'u')
		c = ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (type == 'x')
		c = ft_putnbr_b(va_arg(args, unsigned int), "0123456789abcdef");
	else if (type == 'X')
		c = ft_putnbr_b(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (type == 's')
		c = my_putstr(va_arg(args, char *));
	return (c - 1);
}

int	process_format(char	*format, va_list args)
{
	int	c;

	c = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
				ft_putchar(va_arg(args, int));
			if (*format == '%')
				ft_putchar('%');
			if (*format == 'p' || *format == 'd' || *format == 'i'
				|| *format == 'u' || *format == 'x' || *format == 'X'
				|| *format == 's')
				c += print_specific(*format, args);
		}
		else
			write(1, format, 1);
		format++;
		c++;
	}
	return (c);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		output;

	if (!format)
		return (-1);
	va_start(args, format);
	output = process_format((char *)format, args);
	va_end(args);
	return (output);
}
