/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 10:38:57 by esimpson          #+#    #+#             */
/*   Updated: 2024/06/13 10:39:00 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_handle_clr(t_list **head, void (*del)(void *))
{
	ft_lstclear(head, del);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*nlst;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	content = f(lst->content);
	head = ft_lstnew(content);
	if (!head)
		return (del(content), ft_handle_clr(&head, del), NULL);
	nlst = head;
	lst = lst->next;
	while (lst)
	{
		content = f(lst->content);
		nlst->next = ft_lstnew(content);
		nlst = nlst->next;
		if (!nlst)
			return (del(content), ft_handle_clr(&head, del), NULL);
		lst = lst->next;
	}
	nlst->next = NULL;
	return (head);
}
