/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lowest_nr_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 11:47:22 by nde-koni          #+#    #+#             */
/*   Updated: 2021/05/22 15:01:48 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	lowest_nr_a(t_stk stk)
{
	int	rtn;

	stk.ac--;
	rtn = INT_MAX;
	while (stk.ac >= 0)
	{
		if (stk.a[stk.ac] < rtn)
			rtn = stk.a[stk.ac];
		stk.ac--;
	}
	return (rtn);
}
