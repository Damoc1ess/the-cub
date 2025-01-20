/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:48:41 by fflamion          #+#    #+#             */
/*   Updated: 2024/09/17 12:29:18 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstinsert(t_list **lst, t_list *new, size_t pos)
{
	t_list	*current;
	t_list	*previous;
	size_t	i;

	if (!lst || !new)
		return ;
	if (pos == 0)
	{
		new->next = *lst;
		*lst = new;
		return ;
	}
	current = *lst;
	previous = NULL;
	i = 0;
	while (current && i++ < pos)
	{
		previous = current;
		current = current->next;
	}
	if (i != pos)
		return ;
	if (previous)
		previous->next = new;
	new->next = current;
}
