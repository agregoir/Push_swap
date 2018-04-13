/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty_pile_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agregoir <agregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 16:39:11 by agregoir          #+#    #+#             */
/*   Updated: 2017/10/21 18:01:50 by agregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

char	*push_it_on_a(t_pile *pile_b, t_pile *pile_a, int i, char *result)
{
	if ((i == 0) && (pile_b->len == 1))
	{
		result = ft_strjoin_free(result, "pa\n", 1);
		op_pa(pile_a, pile_b);
		return (result);
	}
	if (i < (pile_b->len / 2))
	{
		while (i != 0)
		{
			result = ft_strjoin_free(result, "rb\n", 1);
			op_rb(pile_a, pile_b);
			i--;
		}
	}
	else
		while (i != (pile_b->len))
		{
			result = ft_strjoin_free(result, "rrb\n", 1);
			op_rrb(pile_a, pile_b);
			i++;
		}
	result = ft_strjoin_free(result, "pa\n", 1);
	op_pa(pile_a, pile_b);
	return (result);
}

void	empty_pile_b(t_pile *pile_a, t_pile *pile_b, char **result)
{
	int		i;

	while (pile_b->len != 0)
	{
		i = the_largest(pile_b);
		*result = push_it_on_a(pile_b, pile_a, i, *result);
	}
	return ;
}
