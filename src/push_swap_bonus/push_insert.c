/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 18:02:37 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/12 09:56:13 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <resolver_bonus.h>

void	insert_atob(t_mlxptr mlx, t_stack *st[2], t_queue *instr,
			size_t strk_cnt)
{
	size_t	b_size;
	size_t	rot_cnt;
	size_t	push_cnt;

	while (strk_cnt--)
	{
		push_cnt = next_streak(st[ST_A], 0, ORDER_A);
		if (!push_cnt)
			push_cnt = stksize(st[ST_A]);
		b_size = stksize(st[ST_B]);
		rot_cnt = b_size - begin_streak(st[ST_B], stack_prev_index(0, b_size),
				ORDER_B);
		while (push_cnt--)
		{
			while (rot_cnt && *stkrbegin(st[ST_B]) < stktop(st[ST_A]))
			{
				--rot_cnt;
				add_op(mlx, rrb, st, instr);
			}
			add_op(mlx, pb, st, instr);
		}
		while (rot_cnt--)
			add_op(mlx, rrb, st, instr);
	}
}

void	push_atob(t_mlxptr mlx, t_stack *st[2], t_queue *instr,
			size_t strk_cnt)
{
	size_t	push_cnt;

	while (strk_cnt--)
	{
		push_cnt = next_streak(st[ST_A], 0, ORDER_A);
		while (push_cnt--)
			add_op(mlx, pb, st, instr);
	}
}

void	insert_btoa(t_mlxptr mlx, t_stack *st[2], t_queue *instr,
			size_t strk_cnt)
{
	size_t			a_size;
	size_t			rot_cnt;
	size_t			push_cnt;

	while (strk_cnt--)
	{
		push_cnt = next_streak(st[ST_B], 0, ORDER_B);
		if (!push_cnt)
			push_cnt = stksize(st[ST_B]);
		a_size = stksize(st[ST_A]);
		rot_cnt = a_size - begin_streak(st[ST_A],
				stack_prev_index(0, a_size), ORDER_A);
		while (push_cnt--)
		{
			while (rot_cnt && *stkrbegin(st[ST_A]) > stktop(st[ST_B]))
			{
				--rot_cnt;
				add_op(mlx, rra, st, instr);
			}
			add_op(mlx, pa, st, instr);
		}
		while (rot_cnt--)
			add_op(mlx, rra, st, instr);
	}
}

void	push_btoa(t_mlxptr mlx, t_stack *st[2], t_queue *instr,
			size_t strk_cnt)
{
	size_t	push_cnt;

	while (strk_cnt--)
	{
		push_cnt = next_streak(st[ST_B], 0, ORDER_B);
		while (push_cnt--)
			add_op(mlx, pa, st, instr);
	}
}
