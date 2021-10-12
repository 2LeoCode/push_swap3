/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brute_force_cases.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:29:24 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/12 09:56:43 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <brute_force_bonus.h>

void	sort_2numbers(t_mlxptr mlx, t_stack *st[2], t_queue *instr,
			const size_t size)
{
	const int *const	a_raw = stkcbegin(st[ST_A]);
	int					i;

	i = -1;
	while (++i < g_2combi.cnt)
	{
		if (same_order(g_2combi.order[i], a_raw, size))
		{
			apply_instructions(mlx, st, g_2combi.op[i], instr);
			break ;
		}
	}
}

void	sort_3numbers(t_mlxptr mlx, t_stack *st[2], t_queue *instr,
			const size_t size)
{
	const int *const	a_raw = stkcbegin(st[ST_A]);
	int					i;

	i = -1;
	while (++i < g_3combi.cnt)
	{
		if (same_order(g_3combi.order[i], a_raw, size))
		{
			apply_instructions(mlx, st, g_3combi.op[i], instr);
			break ;
		}
	}
}

void	sort_4numbers(t_mlxptr mlx, t_stack *st[2], t_queue *instr,
			const size_t size)
{
	const int *const	a_raw = stkcbegin(st[ST_A]);
	int					i;

	i = -1;
	while (++i < g_4combi.cnt)
	{
		if (same_order(g_4combi.order[i], a_raw, size))
		{
			apply_instructions(mlx, st, g_4combi.op[i], instr);
			break ;
		}
	}
}

void	sort_5numbers(t_mlxptr mlx, t_stack *st[2], t_queue *instr,
			const size_t size)
{
	const int *const	a_raw = stkcbegin(st[ST_A]);
	int					i;

	i = -1;
	while (++i < g_5combi.cnt)
	{
		if (same_order(g_5combi.order[i], a_raw, size))
		{
			apply_instructions(mlx, st, g_5combi.op[i], instr);
			break ;
		}
	}
}
