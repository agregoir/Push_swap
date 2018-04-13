/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_pa_pb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agregoir <agregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 18:24:18 by agregoir          #+#    #+#             */
/*   Updated: 2017/10/21 19:47:34 by agregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int		op_pa(t_pile *pile_a, t_pile *pile_b)
{
	int		tmp_len_a;
	int		tmp_len_b;
	int		i;

	tmp_len_a = pile_a->len;
	tmp_len_b = pile_b->len;
	i = 0;
	if (pile_b->len == 0)
		return (1);
	while (tmp_len_a != -1)
	{
		pile_a->pile[tmp_len_a + 1] = pile_a->pile[tmp_len_a];
		tmp_len_a--;
	}
	pile_a->pile[0] = pile_b->pile[0];
	tmp_len_b--;
	while (i != tmp_len_b)
	{
		pile_b->pile[i] = pile_b->pile[i + 1];
		i++;
	}
	pile_b->pile[i] = 0;
	pile_b->len = tmp_len_b;
	pile_a->len += 1;
	return (1);
}

int		op_pb(t_pile *pile_a, t_pile *pile_b)
{
	int		tmp_len_a;
	int		tmp_len_b;
	int		i;

	tmp_len_a = pile_a->len;
	tmp_len_b = pile_b->len;
	i = 0;
	if (pile_a->len == 0)
		return (1);
	while (tmp_len_b != -1)
	{
		pile_b->pile[tmp_len_b + 1] = pile_b->pile[tmp_len_b];
		tmp_len_b--;
	}
	pile_b->pile[0] = pile_a->pile[0];
	tmp_len_a--;
	while (i != tmp_len_a)
	{
		pile_a->pile[i] = pile_a->pile[i + 1];
		i++;
	}
	pile_a->pile[i] = 0;
	pile_a->len = tmp_len_a;
	pile_b->len += 1;
	return (1);
}
