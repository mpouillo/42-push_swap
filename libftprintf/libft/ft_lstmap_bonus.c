/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouillo <mpouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 13:11:25 by mpouillo          #+#    #+#             */
/*   Updated: 2025/11/19 11:02:29 by mpouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*cur;
	t_list	*head;
	void	*new_content;

	if (!lst || !f || !del)
		return (NULL);
	head = NULL;
	cur = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		cur = ft_lstnew(new_content);
		if (!cur)
		{
			del(new_content);
			ft_lstclear(&head, del);
			return (NULL);
		}
		ft_lstadd_back(&head, cur);
		lst = lst->next;
	}
	return (head);
}
