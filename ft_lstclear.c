/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpauline <jpauline@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 18:15:51 by jpauline          #+#    #+#             */
/*   Updated: 2020/12/09 18:45:25 by jpauline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *crt;
	t_list *nxt;

	if (lst && *lst && del)
	{
		crt = *lst;
		while (crt)
		{
			nxt = crt->next;
			ft_lstdelone(crt, del);
			crt = nxt;
		}
		*lst = NULL;
	}
}
