/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brute_force.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 22:11:44 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/12 09:55:50 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <brute_force_bonus.h>
#include <resolver_bonus.h>

bool	same_order(const int *a, const int *b, size_t size)
{
	size_t	i;
	size_t	j;

	i = ~0;
	while (++i < size)
	{
		j = ~0;
		while (++j < size)
		{
			if (j != i && ((a[j] < a[i] && b[j] > b[i])
					|| (a[j] > a[i] && b[j] < b[i])))
				return (false);
		}
	}
	return (true);
}

void	apply_instructions(t_mlxptr mlx, t_stack *st[2], t_op *const *op,
			t_queue *instr)
{
	while (*op)
	{
		add_op(mlx, *op, st, instr);
		++op;
	}
}

int	brute_force(t_mlxptr mlx, t_stack *st[2], t_queue *instr)
{
	const size_t	size = stksize(st[ST_A]);

	if (stksorted(st[ST_A]))
		return (0);
	if (size > 5)
		return (1);
	if (size == 2)
		sort_2numbers(mlx, st, instr, size);
	else if (size == 3)
		sort_3numbers(mlx, st, instr, size);
	else if (size == 4)
		sort_4numbers(mlx, st, instr, size);
	else if (size == 5)
		sort_5numbers(mlx, st, instr, size);
	return (0);
}
