/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   highest_nr_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 14:00:21 by nde-koni          #+#    #+#             */
/*   Updated: 2021/05/21 14:04:36 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	highest_nr_b(t_stk stk)
{
	int	rtn;

	stk.bc--;
	rtn = INT_MIN;
	while (stk.bc >= 0)
	{
		if (stk.b[stk.bc] > rtn)
			rtn = stk.b[stk.bc];
		stk.bc--;
	}
	return (rtn);
}
