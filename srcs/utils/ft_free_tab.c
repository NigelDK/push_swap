/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 15:46:35 by nde-koni          #+#    #+#             */
/*   Updated: 2021/05/23 11:46:52 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_free_tab(char **tab, int j)
{
	while (--j >= 0)
	{
		free(tab[j]);
		tab[j] = NULL;
	}
	free(tab);
	tab = NULL;
}

void	ft_free_tab_int(int **tab, int j)
{
	while (--j >= 0)
	{
		free(tab[j]);
		tab[j] = NULL;
	}
	free(tab);
	tab = NULL;
}
