/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:16:07 by fflamion          #+#    #+#             */
/*   Updated: 2024/09/07 13:42:31 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(const char *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str && *str != c)
		{
			count++;
			while (*str && *str != c)
				str++;
		}
	}
	return (count);
}

char	*malloc_word(const char *str, char c)
{
	const char	*end;
	char		*word;
	int			i;

	end = str;
	while (*end && *end != c)
		end++;
	word = malloc(end - str + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (str < end)
	{
		word[i] = *str;
		str++;
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**array;
	int		i;

	words = count_words(s, c);
	array = malloc(sizeof(char *) * (words + 1));
	if (!array || !s)
		return (NULL);
	i = 0;
	while (i < words)
	{
		while (*s == c)
			s++;
		array[i] = malloc_word(s, c);
		if (!array[i])
		{
			while (i-- > 0)
				free(array[i]);
			return (free(array), NULL);
		}
		while (*s && *s != c)
			s++;
		i++;
	}
	return (array[words] = NULL, array);
}
