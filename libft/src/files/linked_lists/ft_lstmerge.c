/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmerge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:56:39 by fflamion          #+#    #+#             */
/*   Updated: 2024/09/17 12:26:49 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstmerge(t_list **lst1, t_list *lst2)
{
	t_list	*current;

	if (!lst1 || !(*lst1))
	{
		*lst1 = lst2;
		return ;
	}
	current = *lst1;
	while (current->next)
		current = current->next;
	current->next = lst2;
}
