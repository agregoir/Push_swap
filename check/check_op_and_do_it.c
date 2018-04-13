/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_op_and_do_it.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agregoir <agregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 12:53:00 by agregoir          #+#    #+#             */
/*   Updated: 2017/10/21 19:03:35 by agregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./checker.h"

int			check_op(char *str)
{
	if (ft_strstr(str, "sa") || ft_strstr(str, "sb") || ft_strstr(str, "ss")
		|| ft_strstr(str, "pa") || ft_strstr(str, "pb") || ft_strstr(str, "ra")
		|| ft_strstr(str, "rb") || ft_strstr(str, "rr") || ft_strstr(str, "rra")
		|| ft_strstr(str, "rrb") || ft_strstr(str, "rrr"))
		return (1);
	else
		return (0);
}

const t_op	*init_tab_op(void)
{
	static const t_op	tab_op[12] = {{&op_sa, "sa"}, {&op_sb, "sb"},
	{&op_ss, "ss"}, {&op_pa, "pa"}, {&op_pb, "pb"}, {&op_ra, "ra"},
	{&op_rb, "rb"}, {&op_rr, "rr"}, {&op_rra, "rra"}, {&op_rrb, "rrb"},
	{&op_rrr, "rrr"}, {NULL, ""}};

	return (tab_op);
}

int			check_op_and_do_it(char *str, t_pile *pile_a, t_pile *pile_b)
{
	int			i;
	int			ret;
	const t_op	*tab_op;

	tab_op = init_tab_op();
	i = 0;
	ret = 0;
	if (check_op(str))
	{
		while ((ret = ft_strcmp(str, tab_op[i].op)) != 0)
		{
			i++;
			if (!(ft_strcmp(tab_op[i].op, "")))
				return (0);
		}
		tab_op[i].ptr(pile_a, pile_b);
		return (1);
	}
	else
		return (0);
}
