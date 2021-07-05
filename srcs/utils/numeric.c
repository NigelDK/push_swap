/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numeric.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 17:29:58 by nde-koni          #+#    #+#             */
/*   Updated: 2021/05/23 14:59:50 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	only_num(char *s, int argc)
{
	while (*s)
	{
		if (argc == 2)
			if (*s != 32 && *s != 43 && *s != 45 && (*s < 48 || *s > 57))
				return (0);
		if (argc > 2)
			if (*s != 43 && *s != 45 && (*s < 48 || *s > 57))
				return (0);
		s++;
	}
	return (1);
}

int	numeric(int argc, char **argv)
{
	int	i;

	i = argc;
	while (--i > 0)
	{
		if (!only_num(argv[i], argc))
		{
			write(2, "Error\n", 6);
			return (0);
		}
	}
	return (1);
}
