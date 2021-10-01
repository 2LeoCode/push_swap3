/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 11:11:32 by lsuardi           #+#    #+#             */
/*   Updated: 2021/10/01 11:17:59 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <resolver.h>
#include <stdio.h>
#include <stddef.h>

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

size_t	get_streak_count(t_stack *a)
{
	
}

int	get_instruction_queue(t_queue *instr, t_stack *a, t_stack *b, size_t size)
{
	size_t	strk_cnt = get_streak_count(a);

	
}

void	add_op(const char *(*op)(t_stack *, t_stack *), t_stack *a,
	t_stack *b, t_queue *instr_queue)
{
	op(a, b);
	enqueue(instr_queue, op(NULL, NULL));
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
	if (alloc_stacks(&a, &b, size) || alloc_queue(&instructions,
			INSTR_QUEUE_SIZE))
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
