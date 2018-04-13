/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agregoir <agregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 18:54:07 by agregoir          #+#    #+#             */
/*   Updated: 2017/10/21 20:32:45 by agregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "libft.h"
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

int			check_op(char *str);
const t_op	*init_tab_op(void);
int			check_op_and_do_it(char *str, t_pile *pile_a, t_pile *pile_b);

int			check_order_pile_a(t_pile *pile_a, t_pile *pile_b);
int			ft_error(int type);
int			same_number(t_pile *pile_a);
int			error_case(int argc, char **argv, t_pile **pile_a, t_pile **pile_b);

t_pile		*init_t_pile(int nb_arg, int len_pile);

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

#endif
