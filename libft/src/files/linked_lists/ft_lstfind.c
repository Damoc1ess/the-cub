/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:17:58 by fflamion          #+#    #+#             */
/*   Updated: 2024/09/17 12:34:12 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfind(t_list *lst, void *key)
{
	while (lst)
	{
		if (ft_memcmp(lst->content, key, ft_strlen(key)) == 0)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
