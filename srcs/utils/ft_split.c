/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 18:11:55 by nde-koni          #+#    #+#             */
/*   Updated: 2021/05/23 13:36:09 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	ft_char(char const s, char c)
{
	if (s == c)
		return (1);
	return (0);
}

static int	ft_strl(char const *s, char c)
{
	int	i;

	i = 0;
	while (!ft_char(*s++, c) && *s)
		i++;
	return (i);
}

static int	ft_words(char const *s, char c)
{
	int	i;

	i = 0;
	while (ft_char(*s, c) && *s)
		s++;
	while (*s)
	{
		while (!ft_char(*s, c) && *s)
			s++;
		while (ft_char(*s, c) && *s)
			s++;
		i++;
	}
	return (i);
}

static int	fill_tab(char const *s, char c, char **tab)
{
	int	i;
	int	j;

	j = 0;
	while (*s)
	{
		i = 0;
		tab[j] = malloc((ft_strl(s, c) + 1) * sizeof(char *));
		if (tab[j] == NULL)
		{
			while (--j >= 0)
				free(tab[j]);
			free(tab);
			return (-1);
		}
		while (!ft_char(*s, c) && *s)
			tab[j][i++] = *s++;
		tab[j][i] = '\0';
		while (ft_char(*s, c) && *s)
			s++;
		j++;
	}
	tab[j] = 0;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;

	if (!s)
		return (NULL);
	tab = malloc((ft_words(s, c) + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	while (ft_char(*s, c) && *s)
		s++;
	if (fill_tab(s, c, tab) == -1)
		return (NULL);
	return (tab);
}
