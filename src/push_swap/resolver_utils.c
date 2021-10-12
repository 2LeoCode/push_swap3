/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolver_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 18:00:16 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/12 10:01:52 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <resolver.h>

size_t	stack_next_index(size_t cur, size_t tot_size)
{
	return ((cur + 1) % tot_size);
}

size_t	stack_prev_index(size_t cur, size_t tot_size)
{
	if (!cur)
		return (tot_size - 1);
	return (cur - 1);
}

int	alloc_queue(t_queue **queue, size_t size)
{
	*queue = qalloc(size);
	if (!queue)
		return (-1);
	return (0);
}

void	print_instructions(t_queue *queue)
{
	while (!qempty(queue))
	{
		ft_putstr_fd(1, dequeue(queue));
		write(1, "\n", 1);
	}
}

void	add_op(const char *(*op)(t_stack *, t_stack *),
	t_stack *st[2], t_queue *instr_queue)
{
	op(st[ST_A], st[ST_B]);
	enqueue(instr_queue, op(NULL, NULL));
}
