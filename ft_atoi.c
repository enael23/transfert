/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpauline <jpauline@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 12:54:45 by jpauline          #+#    #+#             */
/*   Updated: 2020/12/07 13:00:06 by jpauline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int	rslt;
	int	sign;

	while ((*str >= '\t' && *str <= '\r') || (*str == ' '))
		str++;
	sign = 1;
	if ((*str == '+') || (*str == '-'))
	{
		if (*str == '-')
			sign = sign * (-1);
		str++;
	}
	rslt = 0;
	while ((*str >= '0') && (*str <= '9'))
	{
		rslt = (rslt * 10) + (*str - '0');
		str++;
	}
	return (rslt * sign);
}
