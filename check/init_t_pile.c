/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_t_pile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agregoir <agregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 15:30:23 by agregoir          #+#    #+#             */
/*   Updated: 2017/10/21 18:39:49 by agregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./checker.h"

t_pile		*init_t_pile(int nb_arg, int len_pile)
{
	t_pile	*ret;

	ret = (t_pile *)ft_memalloc(sizeof(t_pile));
	ret->pile = (int *)ft_memalloc(sizeof(int) * (nb_arg * 4));
	ret->len = len_pile;
	return (ret);
}
