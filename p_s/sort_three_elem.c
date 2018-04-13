/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_elem.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agregoir <agregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 13:03:39 by agregoir          #+#    #+#             */
/*   Updated: 2017/10/21 19:22:03 by agregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	sort_three_elem_two(t_pile *pile_a, t_pile *pile_b, char **result)
{
	if (pile_a->pile[1] < pile_a->pile[2])
	{
		op_ra(pile_a, pile_b);
		*result = ft_strjoin_free(*result, "ra\n", 1);
		return ;
	}
	else if (pile_a->pile[1] > pile_a->pile[2])
	{
		op_ra(pile_a, pile_b);
		op_sa(pile_a, pile_b);
		*result = ft_strjoin_free(*result, "ra\nsa\n", 1);
		return ;
	}
	return ;
}

void	sort_three_elem_one(t_pile *p, t_pile *pile_b, char **result)
{
	if ((p->pile[0] < p->pile[1]) && (p->pile[1] < p->pile[2]))
		return ;
	else if ((p->pile[0] < p->pile[1]) && (p->pile[0] < p->pile[2]))
	{
		op_ra(p, pile_b);
		op_sa(p, pile_b);
		op_rra(p, pile_b);
		*result = ft_strjoin_free(*result, "ra\nsa\nrra\n", 1);
		return ;
	}
	else if ((p->pile[0] > p->pile[1]) && (p->pile[0] < p->pile[2]))
	{
		op_sa(p, pile_b);
		*result = ft_strjoin_free(*result, "sa\n", 1);
		return ;
	}
	else if ((p->pile[0] < p->pile[1]) && (p->pile[0] > p->pile[2]))
	{
		op_rra(p, pile_b);
		*result = ft_strjoin_free(*result, "rra\n", 1);
		return ;
	}
	else
		sort_three_elem_two(p, pile_b, result);
	return ;
}

void	sort_three_elem(t_pile *pile_a, t_pile *pile_b, char **result)
{
	sort_three_elem_one(pile_a, pile_b, result);
	return ;
}
