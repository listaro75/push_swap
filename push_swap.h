/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luda-cun <luda-cun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:13:22 by luda-cun          #+#    #+#             */
/*   Updated: 2025/02/13 10:03:37 by luda-cun         ###   ########.fr       */
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

struct				s_pslist
{
	int				val;
	struct s_pslist	next;
}					t_pslist;

void				ft_swap_a(int *b);
void				ft_swap_b(int *b);
void				ft_swap_a_b(int *a, int *b);

#endif