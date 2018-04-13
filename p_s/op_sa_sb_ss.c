/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sa_sb_ss.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agregoir <agregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 18:23:58 by agregoir          #+#    #+#             */
/*   Updated: 2017/10/21 19:47:40 by agregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int		op_sa(t_pile *pile_a, t_pile *pile_b)
{
	int		tmp;

	(void)pile_b;
	if (pile_a->len == 1 || pile_a->len == 0)
		return (1);
	else
		tmp = pile_a->pile[0];
	pile_a->pile[0] = pile_a->pile[1];
	pile_a->pile[1] = tmp;
	return (1);
}

int		op_sb(t_pile *pile_a, t_pile *pile_b)
{
	int		tmp;

	(void)pile_a;
	if (pile_b->len == 1 || pile_b->len == 0)
		return (1);
	else
		tmp = pile_b->pile[0];
	pile_b->pile[0] = pile_b->pile[1];
	pile_b->pile[1] = tmp;
	return (1);
}

int		op_ss(t_pile *pile_a, t_pile *pile_b)
{
	op_sa(pile_a, pile_b);
	op_sb(pile_a, pile_b);
	return (1);
}
