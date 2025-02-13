/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luda-cun <luda-cun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:13:22 by luda-cun          #+#    #+#             */
/*   Updated: 2025/02/13 14:45:10 by luda-cun         ###   ########.fr       */
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

void				ft_sa(t_pslist **stack_a);
void				ft_sb(t_pslist **stack_b);
void				ft_ss(t_pslist **a, t_pslist **b);
int					ft_verif_digit(char **argv);
int					ft_verif_doublon(char **argv);
void				view(t_pslist *stack);
void				ft_pa(t_pslist **a, t_pslist **b);
void				ft_pb(t_pslist **b, t_pslist **a);
t_pslist			*ft_add_val(int val);

#endif