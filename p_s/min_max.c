/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agregoir <agregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 16:37:11 by agregoir          #+#    #+#             */
/*   Updated: 2017/10/21 18:02:07 by agregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int		the_largest(t_pile *pile)
{
	int		tmp;
	int		index;
	int		len;
	int		index_tmp;

	index = 0;
	tmp = 0;
	index_tmp = 0;
	len = pile->len;
	tmp = pile->pile[index];
	while (len)
	{
		if (pile->pile[index] > tmp)
		{
			tmp = pile->pile[index];
			index_tmp = index;
		}
		index++;
		len--;
	}
	return (index_tmp);
}

int		the_smallest(t_pile *pile, int med)
{
	int		tmp;
	int		index;
	int		len;
	int		index_tmp;

	index = 0;
	tmp = 0;
	index_tmp = 0;
	len = pile->len;
	tmp = pile->pile[index];
	while (len)
	{
		if ((pile->pile[index] <= med) && (pile->pile[index] < tmp))
		{
			tmp = pile->pile[index];
			index_tmp = index;
		}
		index++;
		len--;
	}
	return (index_tmp);
}
