/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:58:26 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/12 14:47:56 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <resolver_bonus.h>

void	kek(void)
{
	write(1, "kek\n", 4);
}

static void	push_swap_atob(t_mlxptr mlx, t_stack *st[2], t_queue *instr)
{
	const int	*a_raw;

	while (streak_count(st[ST_B], ORDER_B, next_streak, true)
		< stksize(st[ST_A]) / 4)
	{
		a_raw = stkbegin(st[ST_A]);
		if (a_raw[0] > a_raw[stack_next_index(0, stksize(st[ST_A]))])
			add_op(mlx, sa, st, instr);
		add_op(mlx, pb, st, instr);
		add_op(mlx, pb, st, instr);
	}
}

void	insert_pair_to_b(t_mlxptr mlx, t_stack *st[2], t_queue *instr)
{
	const size_t	b_size = stksize(st[ST_B]);
	size_t			rot_cnt;
	size_t			cnt;

	rot_cnt = b_size - begin_streak(st[ST_B],
			stack_prev_index(0, b_size), ORDER_B);
	cnt = 2;
	while (cnt--)
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

void	setup_streaks(t_mlxptr mlx, t_stack *st[2], t_queue *instr)
{
	const int	*a_raw;

	push_swap_atob(mlx, st, instr);
	while (!stkempty(st[ST_A]))
	{
		a_raw = stkbegin(st[ST_A]);
		if (a_raw[0] > a_raw[stack_next_index(0, stksize(st[ST_A]))])
			add_op(mlx, sa, st, instr);
		insert_pair_to_b(mlx, st, instr);
	}
}

void	sort_loop(t_mlxptr mlx, t_stack *st[2], t_queue *instr)
{
	size_t	strk_cnt;

	strk_cnt = streak_count(st[ST_B], ORDER_B, next_streak, false);
	while (strk_cnt > 2)
	{
		push_btoa(mlx, st, instr, strk_cnt / 4 + 1 - streak_count(st[ST_A],
				ORDER_A, next_streak, false));
		insert_btoa(mlx, st, instr, streak_count(st[ST_B], ORDER_B,
				next_streak, false) - 1);
		strk_cnt = streak_count(st[ST_A], ORDER_A, next_streak, false) + 1;
		if (strk_cnt == 2)
			break ;
		push_atob(mlx, st, instr, strk_cnt / 4 + 1 - streak_count(st[ST_B],
				ORDER_B, next_streak, false));
		insert_atob(mlx, st, instr, streak_count(st[ST_A], ORDER_A,
				next_streak, false) - 1);
		strk_cnt = streak_count(st[ST_B], ORDER_B, next_streak, false) + 1;
	}
}
