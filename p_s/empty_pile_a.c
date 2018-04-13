/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty_pile_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agregoir <agregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 08:17:09 by agregoir          #+#    #+#             */
/*   Updated: 2017/10/21 19:55:12 by agregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

char	*push_it_on_b(t_pile *pile_a, t_pile *pile_b, int *i, char *result)
{
	(void)pile_b;
	if (*i <= (pile_a->len / 2))
	{
		while (*i != 0)
		{
			result = ft_strjoin_free(result, "ra\n", 1);
			op_ra(pile_a, pile_b);
			(*i)--;
		}
	}
	else
	{
		while (*i != (pile_a->len))
		{
			result = ft_strjoin_free(result, "rra\n", 1);
			op_rra(pile_a, pile_b);
			(*i)++;
		}
	}
	result = ft_strjoin_free(result, "pb\n", 1);
	op_pb(pile_a, pile_b);
	*i = 0;
	return (result);
}

int		*empty_pile_a(t_pile *pile_a, t_pile *pile_b, char **result, int *tab)
{
	int		i;
	int		index_med;

	index_med = 0;
	while (pile_a->len > 3)
	{
		i = 0;
		tab[index_med] = get_mediane(pile_a, 0, pile_a->len - 1);
		while (i <= pile_a->len - 1)
		{
			if ((pile_a->len == 4) && (pile_a->pile[i] <= tab[index_med]))
				i = the_smallest(pile_a, tab[index_med]);
			if (pile_a->pile[i] < tab[index_med])
				*result = push_it_on_b(pile_a, pile_b, &i, *result);
			else
				i++;
			if (pile_a->len <= 3)
				break ;
		}
		if (pile_a->len <= 3)
			break ;
		index_med++;
	}
	return (tab);
}
