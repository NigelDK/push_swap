/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   highest_nr_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 08:10:19 by nde-koni          #+#    #+#             */
/*   Updated: 2021/05/22 15:08:23 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	highest_nr_a(t_stk stk)
{
	int	rtn;

	stk.ac--;
	rtn = INT_MIN;
	while (stk.ac >= 0)
	{
		if (stk.a[stk.ac] > rtn)
			rtn = stk.a[stk.ac];
		stk.ac--;
	}
	return (rtn);
}
