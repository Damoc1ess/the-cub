/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_handling.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:37:52 by fflamion          #+#    #+#             */
/*   Updated: 2024/11/12 02:17:29 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_HANDLING_H
# define FT_ERROR_HANDLING_H

# include "libft.h"

void	ft_assert(int condition, const char *msg);
void	ft_error_msg(const char *msg);

#endif