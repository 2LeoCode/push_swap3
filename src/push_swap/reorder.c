/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reorder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 18:04:42 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/12 10:01:39 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <resolver.h>

static void	get_best_direction(t_stack *a, size_t *len_ptr,
				const char *(**op_ptr)(), size_t (*strkfun[2])())
{
	size_t	len_before;
	size_t	len_after;

	len_before = strkfun[BEGIN_FUN](a, 0, ORDER_A);
	if (!len_before)
	{
		*len_ptr = 0;
		*op_ptr = NULL;
	}
	else
	{
		len_before = stksize(a) - len_before;
		len_after = strkfun[NEXT_FUN](a, 0, ORDER_A);
		if (len_before < len_after)
		{
			*len_ptr = len_before;
			*op_ptr = rra;
		}
		else
		{
			*len_ptr = len_after;
			*op_ptr = ra;
		}
	}
}

void	reorder_a(t_stack *st[2], t_queue *instr,
			size_t (*strkfun[2])())
{
	const int *const	a_raw = stkbegin(st[ST_A]);
	const size_t		size = stksize(st[ST_A]);
	size_t				len;
	const char			*(*rot_op)();

	if (a_raw[0] > a_raw[stack_next_index(0, size)])
		add_op(sa, st, instr);
	get_best_direction(st[ST_A], &len, &rot_op, strkfun);
	while (len--)
		add_op(rot_op, st, instr);
}
