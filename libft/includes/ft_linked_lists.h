/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linked_lists.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:36:42 by fflamion          #+#    #+#             */
/*   Updated: 2024/09/07 13:42:31 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LINKED_LISTS_H
# define FT_LINKED_LISTS_H

# include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **alst, t_list *new);
void	ft_lstclear(t_list **lst);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
t_list	*ft_lstdup(t_list *lst);
t_list	*ft_lstfind(t_list *lst, void *key);
void	ft_lstinsert(t_list **lst, t_list *new, size_t pos);
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *));
void	ft_lstmerge(t_list **lst1, t_list *lst2);
t_list	*ft_lstnew(void *content);
void	ft_lstremove_at(t_list **lst, size_t pos);
void	ft_lstreverse(t_list **lst);
int		ft_lstsize(t_list *lst);
void	ft_lstmap_inplace(t_list *lst, void *(*f)(void *));

#endif