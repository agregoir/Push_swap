/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ra_rb_rr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agregoir <agregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 18:23:35 by agregoir          #+#    #+#             */
/*   Updated: 2017/10/21 19:47:37 by agregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int		op_ra(t_pile *pile_a, t_pile *pile_b)
{
	int		tmp_len_a;
	int		tmp_first_elem;
	int		i;

	(void)pile_b;
	tmp_len_a = pile_a->len;
	i = 0;
	if (pile_a->len == 0)
		return (1);
	tmp_first_elem = pile_a->pile[0];
	tmp_len_a--;
	while (i != tmp_len_a)
	{
		pile_a->pile[i] = pile_a->pile[i + 1];
		i++;
	}
	pile_a->pile[i] = tmp_first_elem;
	return (1);
}

int		op_rb(t_pile *pile_a, t_pile *pile_b)
{
	int		tmp_len_b;
	int		tmp_first_elem;
	int		i;

	(void)pile_a;
	tmp_len_b = pile_b->len;
	i = 0;
	if (pile_b->len == 0)
		return (1);
	tmp_first_elem = pile_b->pile[0];
	tmp_len_b--;
	while (i != tmp_len_b)
	{
		pile_b->pile[i] = pile_b->pile[i + 1];
		i++;
	}
	pile_b->pile[i] = tmp_first_elem;
	return (1);
}

int		op_rr(t_pile *pile_a, t_pile *pile_b)
{
	op_rb(pile_a, pile_b);
	op_ra(pile_a, pile_b);
	return (1);
}
