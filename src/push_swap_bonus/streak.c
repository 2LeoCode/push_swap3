/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   streak.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:55:33 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/12 09:56:35 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <resolver_bonus.h>

size_t	next_streak_init(t_stack *st, size_t cur, int order)
{
	const size_t		st_size = stksize(st);
	const int *const	st_raw = stkbegin(st);

	if (order * (long)st_raw[cur]
		> order * (long)st_raw[stack_next_index(cur, st_size)])
		cur = (cur + 2) % st_size;
	while (order * (long)st_raw[cur]
		< order * (long)st_raw[stack_next_index(cur, st_size)])
		cur = stack_next_index(cur, st_size);
	return (stack_next_index(cur, st_size));
}

size_t	begin_streak_init(t_stack *st, size_t cur, int order)
{
	const size_t		st_size = stksize(st);
	const int *const	st_raw = stkbegin(st);
	long				cur_value;

	if (order * (long)st_raw[cur]
		> order * (long)st_raw[stack_next_index(cur, st_size)])
		cur_value = st_raw[stack_next_index(cur, st_size)];
	else
		cur_value = st_raw[cur];
	if (order * (long)st_raw[stack_prev_index(cur, st_size)]
		> order * cur_value)
		return (cur);
	while (order * (long)st_raw[cur]
		> order * (long)st_raw[stack_prev_index(cur, st_size)])
		cur = stack_prev_index(cur, st_size);
	return (cur);
}

size_t	next_streak(t_stack *st, size_t cur, int order)
{
	const size_t		st_size = stksize(st);
	const int *const	st_raw = stkbegin(st);

	while (order * (long)st_raw[cur]
		< order * (long)st_raw[stack_next_index(cur, st_size)])
		cur = stack_next_index(cur, st_size);
	return (stack_next_index(cur, st_size));
}

size_t	begin_streak(t_stack *st, size_t cur, int order)
{
	const size_t		st_size = stksize(st);
	const int *const	st_raw = stkbegin(st);

	if (order * (long)st_raw[stack_prev_index(cur, st_size)]
		> order * (long)st_raw[cur])
		return (cur);
	while (order * (long)st_raw[cur]
		> order * (long)st_raw[stack_prev_index(cur, st_size)])
		cur = stack_prev_index(cur, st_size);
	return (cur);
}

size_t	streak_count(t_stack *st, int order, size_t (*nextfun)(), bool th_swap)
{
	const size_t	st_size = stksize(st);
	size_t			strk_cnt;
	size_t			begin_strk;
	size_t			i;

	if (!st_size)
		return (0);
	begin_strk = nextfun(st, 0, order);
	strk_cnt = 1;
	i = nextfun(st, begin_strk, order);
	while (i != begin_strk)
	{
		++strk_cnt;
		i = nextfun(st, i, order);
		if (th_swap && i == 1)
			i = 2;
	}
	return (strk_cnt);
}
