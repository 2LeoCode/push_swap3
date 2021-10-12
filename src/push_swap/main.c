/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 19:46:39 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/12 10:41:53 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <resolver.h>
#include <stdio.h>
#include <stddef.h>

void	get_instruction_queue(t_stack *st[2], t_queue *instr)
{
	if (!brute_force(st, instr))
		return ;
	reorder_a(st, instr, (size_t (*[])()){begin_streak_init,
		next_streak_init});
	setup_streaks(st, instr);
	sort_loop(st, instr);
	if (!stkempty(st[ST_B]))
		while (*stkrbegin(st[ST_B]) > stktop(st[ST_B]))
			add_op(rrb, st, instr);
	while (!stkempty(st[ST_B]))
		insert_btoa(st, instr, 1);
	reorder_a(st, instr, (size_t (*[])()){begin_streak,
		next_streak_init});
}

static int	ft_resolver_failure(void (*except), t_stack **st_a, t_stack **st_b,
		t_queue **instr_q)
{
	free(*instr_q);
	*instr_q = NULL;
	return (ft_failure(except, st_a, st_b));
}

static int	clear_left_memory(t_queue *instr, t_stack *a,
				t_stack *b)
{
	free(instr);
	free(a);
	free(b);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack		*st[2];
	t_queue		*instructions;
	size_t		size;
	void		(*errfun)(void);

	size = get_stack_size(argc - 1, (const char **)argv + 1);
	if (size == INVALID_INPUT)
		return (ft_exception(invalid_arguments));
	if (alloc_stacks(&st[ST_A], &st[ST_B], size) || alloc_queue(&instructions,
			INSTR_QUEUE_SIZE))
		return (ft_resolver_failure(out_of_memory, &st[ST_A], &st[ST_B],
				&instructions));
	errfun = fill_stack(st[ST_A], argc, (const char **)argv);
	if (errfun)
		return (ft_resolver_failure(errfun, &st[ST_A], &st[ST_B],
				&instructions));
	get_instruction_queue(st, instructions);
	print_instructions(instructions);
	return (clear_left_memory(instructions, st[ST_A], st[ST_B]));
}
