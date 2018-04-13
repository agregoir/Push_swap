/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rra_rrb_rrr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agregoir <agregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 18:23:47 by agregoir          #+#    #+#             */
/*   Updated: 2017/10/21 19:47:39 by agregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int		op_rra(t_pile *pile_a, t_pile *pile_b)
{
	int		tmp_len_a;

	if (pile_a->len == 0)
		return (1);
	tmp_len_a = pile_a->len;
	tmp_len_a--;
	while (tmp_len_a)
	{
		op_ra(pile_a, pile_b);
		tmp_len_a--;
	}
	return (1);
}

int		op_rrb(t_pile *pile_a, t_pile *pile_b)
{
	int		tmp_len_b;

	if (pile_b->len == 0)
		return (1);
	tmp_len_b = pile_b->len;
	tmp_len_b--;
	while (tmp_len_b)
	{
		op_rb(pile_a, pile_b);
		tmp_len_b--;
	}
	return (1);
}

int		op_rrr(t_pile *pile_a, t_pile *pile_b)
{
	op_rra(pile_a, pile_b);
	op_rrb(pile_a, pile_b);
	return (1);
}
