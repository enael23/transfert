/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpauline <jpauline@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 18:29:27 by jpauline          #+#    #+#             */
/*   Updated: 2020/12/14 16:05:53 by jpauline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*dest;
	t_list	*start;

	if (!lst || !f)
		return (NULL);
	if (!(dest = ft_lstnew(f(lst->content))))
		return (NULL);
	start = dest;
	while (lst)
	{
		if (lst->next)
		{
			if (!(dest->next = ft_lstnew(f(lst->next->content))))
			{
				if (del)
					ft_lstclear(&start, del);
				return (NULL);
			}
			dest = dest->next;
		}
		lst = lst->next;
	}
	dest->next = NULL;
	return (start);
}
