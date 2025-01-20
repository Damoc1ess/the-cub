/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_of_strings.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:37:49 by fflamion          #+#    #+#             */
/*   Updated: 2024/09/07 13:41:38 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARRAY_OF_STRINGS_H
# define FT_ARRAY_OF_STRINGS_H

# include "libft.h"

char	**duplicate_string_array(char **src);
void	free_array_iter_error(char **tab, int i);
int		get_2d_array_length(char **map);
void	searching_char(char **array, char character, int *row, int *col);
void	free_all_strings(char **str);

#endif