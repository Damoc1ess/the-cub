/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove_at.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:55:26 by fflamion          #+#    #+#             */
/*   Updated: 2024/09/17 12:08:47 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstremove_at(t_list **lst, size_t pos)
{
	t_list	*current;
	t_list	*previous;
	size_t	i;

	if (!lst || !*lst)
		return ;
	current = *lst;
	previous = NULL;
	i = 0;
	while (current && i < pos)
	{
		previous = current;
		current = current->next;
		i++;
	}
	if (!current)
		return ;
	if (previous)
		previous->next = current->next;
	else
		*lst = current->next;
	free(current);
}
