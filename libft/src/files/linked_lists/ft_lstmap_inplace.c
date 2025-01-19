/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_inplace.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 12:29:57 by fflamion          #+#    #+#             */
/*   Updated: 2024/09/17 12:09:41 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstmap_inplace(t_list *lst, void *(*f)(void *))
{
	if (lst == NULL || f == NULL)
		return ;
	while (lst)
	{
		lst->content = (*f)(lst->content);
		lst = lst->next;
	}
}
