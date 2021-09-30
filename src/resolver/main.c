/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 22:43:55 by leo               #+#    #+#             */
/*   Updated: 2021/09/30 11:51:27 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <resolver.h>
#include <stdio.h>

#define SWAP 0
#define ROT 1
#define RROT 2
#define PUSH 3

#define ST_A 0
#define ST_B 1

void	add_op(const char *(*op)(t_stack *, t_stack *), t_stack *a,
	t_stack *b, t_queue *instr_queue)
{
	op(a, b);
	enqueue(instr_queue, op(NULL, NULL));
}


int	get_instruction_queue(t_queue *instr_queue, t_stack *a, t_stack *b,
	size_t size)
{
	size_t	strk_size;
	int		*ptr, *ptr2;
	int		val, val2;

	while (!stkempty(b) || !stksorted(a))
	{
		while (stksize(a) > 3 * size / 4)
		{
			if (stktop(a) > *(stkbegin(a) + 1))
				add_op(sa, a, b, instr_queue);
			strk_size = streak_size(a);
			while (strk_size--)
				add_op(pb, a, b, instr_queue);
		}
		reorderstart_a(a, b, instr_queue);
		ptr = next_streak(a);
		while (ptr != stkend(a))
		{
			val = *ptr;
			while (stktop(a) != val)
			{
				reorderpush_b(a, b, instr_queue, val);
				add_op(pb, a, b, instr_queue);
			}
			val = *next_streak(b);
			while (stktop(b) != val)
				add_op(rra, a, b, instr_queue);
		}
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_queue	*instructions;
	size_t	size;

	if (argc < 2)
		return (ft_exception(invalid_arguments));
	size = get_stack_size(argc - 1, (const char **)argv + 1);
	if (size == INVALID_INPUT)
		return (ft_exception(invalid_arguments));
	if (alloc_stacks(&a, &b, size) || alloc_queue(&instructions, INSTR_QUEUE_SIZE))
		return (ft_failure(out_of_memory, &a, &b));
	if (fill_stack(a, argc, (const char **)argv))
		return (ft_failure(duplicate_element, &a, &b));
	if (get_instruction_queue(instructions, a, b, size))
		return (ft_failure(out_of_memory, &a, &b));
	print_instructions(instructions);
	free(instructions);
	free(a);
	free(b);
	instructions = NULL;
	a = NULL;
	b = NULL;
	return (0);
}
