/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mediane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agregoir <agregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 08:20:11 by agregoir          #+#    #+#             */
/*   Updated: 2017/10/21 18:01:25 by agregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	swap_elem(int *tab, int a, int b)
{
	int		tmp;

	tmp = tab[a];
	tab[a] = tab[b];
	tab[b] = tmp;
}

void	quick_sort(int *tab, int start, int end)
{
	int		left_to_right;
	int		right_to_left;
	int		pivot;

	left_to_right = start;
	right_to_left = end;
	if (start >= end)
		return ;
	pivot = tab[start];
	while (left_to_right < right_to_left)
	{
		while (tab[right_to_left] > pivot)
			right_to_left--;
		while (tab[left_to_right] < pivot)
			left_to_right++;
		if (left_to_right < right_to_left)
			swap_elem(tab, left_to_right, right_to_left);
		if (left_to_right == right_to_left)
			break ;
	}
	quick_sort(tab, start, right_to_left);
	quick_sort(tab, right_to_left + 1, end);
}

int		get_mediane(t_pile *pile, int start, int end)
{
	int		mediane;
	int		*copy_tab;
	int		i;

	copy_tab = (int *)malloc(sizeof(int) * pile->len + 1);
	i = 0;
	while (i < pile->len)
	{
		copy_tab[i] = pile->pile[i];
		i++;
	}
	quick_sort(copy_tab, start, end);
	mediane = copy_tab[(i / 4 + i % 4) % i];
	free(copy_tab);
	copy_tab = NULL;
	return (mediane);
}
