/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agregoir <agregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 10:18:02 by agregoir          #+#    #+#             */
/*   Updated: 2017/10/29 14:47:17 by agregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./checker.h"

int		check_order_pile_a(t_pile *pile_a, t_pile *pile_b)
{
	int		i;

	if (pile_b->len != 0)
		return (0);
	i = 0;
	while (i != pile_a->len - 1)
	{
		if (pile_a->pile[i] < pile_a->pile[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}

int		ft_error(int type)
{
	ft_putstr("\nError\n\n");
	if (type == 1)
		ft_putendl("You know you have to enter argument, don't you ? \n");
	if (type == 2)
	{
		ft_putstr("You can only use number, ");
		ft_putendl("i'm sorry to break your hopes and dreams ... \n");
	}
	if (type == 3)
		ft_putendl("–2147483648 <= INT <= 2147483647, just in case ... O:) \n");
	if (type == 5)
		ft_putendl("I can't sort it if there is two identical numbers :/ \n");
	if (type == 6)
	{
		ft_putendl("You can only use sa sb ss pa pb ra rb rr rra rrb rrr");
		ft_putstr("if YOU wrote that, it's okay, try again ^^ if it's my ");
		ft_putendl("push_swap, i'm in big trouble now ... \n");
	}
	return (0);
}

int		same_number(t_pile *pile_a)
{
	int		index_a_check;
	int		len;
	int		index;

	len = pile_a->len;
	index_a_check = 0;
	index = 0;
	while (index_a_check < len)
	{
		while (index < len)
		{
			if ((index_a_check != index) &&
				(pile_a->pile[index_a_check] == pile_a->pile[index]))
				return (1);
			index++;
		}
		index = 0;
		index_a_check++;
	}
	return (0);
}

int		error_case(int argc, char **argv, t_pile **pile_a, t_pile **pile_b)
{
	int		ret;

	ret = 0;
	if (argc <= 1)
		return (ft_error(1));
	ret = get_data(argc, argv, pile_a, pile_b);
	if (ret == 0)
		return (ft_error(2));
	else if (ret == 2)
		return (ft_error(3));
	else if (same_number(*pile_a))
		return (ft_error(5));
	return (1);
}

int		main(int argc, char **argv)
{
	t_pile		*pile_a;
	t_pile		*pile_b;
	char		*line;

	if (!(error_case(argc, argv, &pile_a, &pile_b)))
		return (0);
	line = ft_strnew(2);
	while (get_next_line(0, &line) > 0)
	{
		if (!(ft_strcmp("", line)))
		{
			ft_bzero(line, ft_strlen(line));
			break ;
		}
		if (!(check_op_and_do_it(line, pile_a, pile_b)))
		{
			free(line);
			return (ft_error(6));
		}
		ft_bzero(line, ft_strlen(line));
	}
	line ? ft_strdel(&line) : 0;
	(check_order_pile_a(pile_a, pile_b)) ? ft_putendl("OK") : ft_putendl("KO");
	return (1);
}
