/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:37:49 by fflamion          #+#    #+#             */
/*   Updated: 2024/10/22 11:32:04 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONVERSIONS_H
# define FT_CONVERSIONS_H

# include "libft.h"

int		ft_atoi_base(char *str, char *base);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
long	ft_atol(const char *str);

#endif