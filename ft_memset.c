/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpauline <jpauline@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 13:20:24 by jpauline          #+#    #+#             */
/*   Updated: 2020/12/04 16:59:04 by jpauline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t n)
{
	size_t	i;

	if (!b)
		return (NULL);
	i = 0;
	while (i < n)
	{
		*(unsigned char*)(b + i) = (unsigned char)c;
		i++;
	}
	return (b);
}
