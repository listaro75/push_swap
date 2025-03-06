/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luda-cun <luda-cun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:13:22 by luda-cun          #+#    #+#             */
/*   Updated: 2025/03/05 11:27:09 by luda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/inc/ft_printf.h"
# include "libft/inc/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_pslist
{
	int				val;
	struct s_pslist	*next;
}					t_pslist;
typedef struct s_movelist
{
	int				rb;
	int				ra;
	int				rr;
	int				rrb;
	int				rra;
	int				rrr;
	int				pa;
	int				cost;
}					t_movelist;

typedef struct s_cheaplist
{
	int				rb;
	int				ra;
	int				rr;
	int				rrb;
	int				rra;
	int				rrr;
	int				pa;
	int				cost;
}					t_cheaplist;

void				ft_sa(t_pslist **stack_a);
void				ft_sb(t_pslist **stack_b);
void				ft_ss(t_pslist **a, t_pslist **b);
int					ft_verif_digit(char **argv, int i);
int					ft_verif_doublon(char **argv, int i);
void				view(t_pslist *stack);
void				ft_pa(t_pslist **a, t_pslist **b);
void				ft_pb(t_pslist **b, t_pslist **a);
t_pslist			*ft_add_val(int val);
void				ft_ra(t_pslist **a);
void				ft_rb(t_pslist **b);
void				ft_rr(t_pslist **a, t_pslist **b);
void				ft_rra(t_pslist **a);
void				ft_rrb(t_pslist **b);
void				ft_rrr(t_pslist **a, t_pslist **b);
int					ft_verif_int_max_min(char **argv, int i);
int					ft_tab_to_stack(char **argv, t_pslist **stack_a);
void				free_tab(char **tab);
void				ft_stack_a(t_pslist **stack_a, char **argv, int i);
int					ft_mediane(t_pslist **stack);
void				ft_algo_base(t_pslist **stack_a, t_pslist **stack_b);
void				find_cheapest(t_pslist **a, t_pslist **b, t_movelist **m,
						t_cheaplist **p);
void				ft_count_move(t_pslist **stack_a, t_pslist **stack_b);
int					ft_nombre(t_pslist *stack);
void				bubble_sort(int *arr, int len);
void				ft_algo_base(t_pslist **stack_a, t_pslist **stack_b);
void				ft_top_b(int value, t_movelist **m, t_pslist **b);
int					ft_val_max_a(t_pslist *a);
void				ft_end(t_pslist **a, t_pslist **b, t_cheaplist **p);
void				ft_max_bottom(t_pslist *a, t_movelist **m, int max_a);
void				ft_good_insert(t_pslist *a, t_movelist **m, int val);
void				ft_combine_rrr(t_movelist **m);
void				ft_cheapmove(t_movelist **m, t_cheaplist **p);
int					ft_val_min_a(t_pslist *a);
int					ft_emp_min(t_pslist *a);
void				ft_end2(t_pslist **a);
int					ft_nombre(t_pslist *stack);
void				bubble_sort(int *arr, int len);
int					ft_nombre(t_pslist *stack);
void				bubble_sort(int *arr, int n);
void				ft_tri_2(t_pslist *stack_a);
int					ft_verif_ordre(t_pslist *stack_a);

#endif