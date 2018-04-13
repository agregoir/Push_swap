/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agregoir <agregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 15:59:22 by agregoir          #+#    #+#             */
/*   Updated: 2017/10/21 19:53:01 by agregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./../libft/libft.h"
# include <stdio.h>

typedef struct s_op		t_op;
typedef struct s_pile	t_pile;

struct		s_op
{
	int		(*ptr)(t_pile *pile_a, t_pile *pile_b);
	char	*op;
};

struct		s_pile
{
	int		*pile;
	int		len;
};

char		*push_it_on_b(t_pile *pile_a, t_pile *pile_b, int *i, char *result);
int			*empty_pile_a(t_pile *pile_a, t_pile *pile_b, char **result,
	int *tab);

char		*push_it_on_a(t_pile *pile_b, t_pile *pile_a, int i, char *result);
void		empty_pile_b(t_pile *pile_a, t_pile *pile_b, char **result);

void		swap_elem(int *tab, int a, int b);
void		quick_sort(int *tab, int start, int end);
int			get_mediane(t_pile *pile, int start, int end);

t_pile		*init_t_pile(int nb_arg, int len_pile);

int			the_largest(t_pile *pile);
int			the_smallest(t_pile *pile, int med);

int			op_pa(t_pile *pile_a, t_pile *pile_b);
int			op_pb(t_pile *pile_a, t_pile *pile_b);

int			op_ra(t_pile *pile_a, t_pile *pile_b);
int			op_rb(t_pile *pile_a, t_pile *pile_b);
int			op_rr(t_pile *pile_a, t_pile *pile_b);

int			op_rra(t_pile *pile_a, t_pile *pile_b);
int			op_rrb(t_pile *pile_a, t_pile *pile_b);
int			op_rrr(t_pile *pile_a, t_pile *pile_b);

int			op_sa(t_pile *pile_a, t_pile *pile_b);
int			op_sb(t_pile *pile_a, t_pile *pile_b);
int			op_ss(t_pile *pile_a, t_pile *pile_b);

int			ft_atoi_mais_en_mieux(const char *str, int *i);
int			ft_get_arg(const char *str, t_pile *pile_a, int j, int nb_arg);
int			check_var(char *str);
int			count_arg(int argc, char **argv);
int			get_data(int argc, char **argv, t_pile **pile_a, t_pile **pile_b);

int			check_order_pile_a(t_pile *pile_a, t_pile *pile_b);
int			ft_error(int type);
int			same_number(t_pile *pile_a);
int			error_case(int argc, char **argv, t_pile **pile_a, t_pile **pile_b);

void		sort_three_elem_two(t_pile *pile_a, t_pile *pile_b, char **result);
void		sort_three_elem_one(t_pile *p, t_pile *pile_b, char **result);
void		sort_three_elem(t_pile *pile_a, t_pile *pile_b, char **result);

#endif
