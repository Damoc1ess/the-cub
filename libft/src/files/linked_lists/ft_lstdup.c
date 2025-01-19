/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:28:56 by fflamion          #+#    #+#             */
/*   Updated: 2024/09/07 13:42:31 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstdup(t_list *lst)
{
	t_list	*new_list;
	t_list	*temp;
	t_list	*new_node;

	if (!lst)
		return (NULL);
	new_list = ft_lstnew(lst->content);
	if (!new_list)
		return (NULL);
	temp = new_list;
	lst = lst->next;
	while (lst)
	{
		new_node = ft_lstnew(lst->content);
		if (!new_node)
		{
			ft_lstclear(&new_list);
			return (NULL);
		}
		temp->next = new_node;
		temp = temp->next;
		lst = lst->next;
	}
	return (new_list);
}
