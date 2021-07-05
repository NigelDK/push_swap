/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_sorted.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 14:41:01 by nde-koni          #+#    #+#             */
/*   Updated: 2021/05/23 11:48:33 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	a_sorted(t_stk stk)
{
	int	low;
	int	i;

	i = stk.ac;
	while (stk.ac > 0)
	{
		low = lowest_nr_a(stk);
		if (low != stk.a[--stk.ac])
			break ;
		i--;
	}
	if (i == 0)
		return (1);
	return (0);
}
