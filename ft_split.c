/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpauline <jpauline@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 15:02:10 by jpauline          #+#    #+#             */
/*   Updated: 2020/12/08 15:43:44 by jpauline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_woco(const char *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str == c)
			str++;
		if (*str)
			count++;
		else
			return (count);
		while ((*str != c) && *str)
			str++;
	}
	return (count);
}

static int	ft_wolen(const char *str, char c)
{
	int	len;

	len = 0;
	while (*str != c && *str)
	{
		str++;
		len++;
	}
	return (len);
}

static void	*ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (NULL);
}

char		**ft_split(char const *s, char c)
{
	int		wc;
	int		i;
	char	**tab;

	wc = 0;
	i = 0;
	if (!s || (!(tab = (char **)malloc(sizeof(char *) * (ft_woco(s, c) + 1)))))
		return (NULL);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			if (!(tab[wc] = (char *)malloc(sizeof(*s) * (ft_wolen(s, c) + 1))))
				return (ft_free_tab(tab));
			while (*s && *s != c)
				tab[wc][i++] = (char)*s++;
			tab[wc][i] = '\0';
			wc++;
			i = 0;
		}
	}
	tab[wc] = NULL;
	return (tab);
}
