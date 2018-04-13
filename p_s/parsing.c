/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agregoir <agregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 12:50:50 by agregoir          #+#    #+#             */
/*   Updated: 2017/10/21 19:55:32 by agregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int		ft_atoi_mais_en_mieux(const char *str, int *i)
{
	int		number;
	int		num_sign;

	num_sign = 1;
	number = 0;
	while (str[(*i)] != '\0' && str[(*i)] <= 32 && str[(*i)] != '\200')
		(*i)++;
	while (str[(*i)] == '-' || str[(*i)] == '+')
	{
		if (str[(*i)] == '-')
			num_sign = num_sign * -1;
		(*i)++;
	}
	while (str[(*i)] >= '0' && str[(*i)] <= '9')
	{
		number *= 10;
		number += str[(*i)] - '0';
		if (number < 0 && number != -2147483648)
		{
			*i = 666;
			return (666);
		}
		(*i)++;
	}
	return (number * num_sign);
}

int		ft_get_arg(const char *str, t_pile *pile_a, int j, int nb_arg)
{
	int		index;

	index = 0;
	while (nb_arg != 0)
	{
		pile_a->pile[j] = ft_atoi_mais_en_mieux(str, &index);
		if ((index == 666) && (pile_a->pile[j] == 666))
			return (0);
		j++;
		nb_arg--;
	}
	return (1);
}

int		check_var(char *str)
{
	int		i;
	int		minus_plus_on_number;
	int		nb_arg;

	i = 0;
	nb_arg = 0;
	minus_plus_on_number = 0;
	while (str[i] != '\0')
	{
		while (str[i] == ' ')
		{
			i++;
			minus_plus_on_number = 0;
		}
		while ((str[i] == '-' || str[i] == '+')
			&& minus_plus_on_number == 0)
			i++;
		if (ft_isdigit(str[i]) && minus_plus_on_number == 0)
			nb_arg++;
		minus_plus_on_number = 1;
		if ((!(ft_isdigit(str[i]))) || (str[i] == '\0'))
			return (0);
		i++;
	}
	return (nb_arg);
}

int		count_arg(int argc, char **argv)
{
	int		index;
	int		nb_arg;

	nb_arg = 0;
	index = 1;
	while (index < argc)
	{
		if (check_var(argv[index]) == 0)
			break ;
		nb_arg += check_var(argv[index]);
		index++;
	}
	if (index != argc)
		return (0);
	else
		return (nb_arg);
}

int		get_data(int argc, char **argv, t_pile **pile_a, t_pile **pile_b)
{
	int		index;
	int		j;
	int		nb_arg;

	j = 0;
	nb_arg = count_arg(argc, argv);
	if (nb_arg == 0)
		return (0);
	*pile_a = init_t_pile(nb_arg, nb_arg);
	*pile_b = init_t_pile(nb_arg, 0);
	index = 1;
	while (argv[index])
	{
		nb_arg = check_var(argv[index]);
		if (ft_get_arg(argv[index], *pile_a, j, nb_arg))
			j += nb_arg;
		else
			return (2);
		index++;
	}
	return (1);
}
