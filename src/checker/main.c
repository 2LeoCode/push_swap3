/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 22:47:47 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/09/23 17:34:08 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include <checker.h>

#define INSTRUCTION_CNT 11

static const char	*(*g_instruction[INSTRUCTION_CNT])() = {
	pa,
	pb,
	sa,
	sb,
	ss,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr
};

static int	checker_judge(t_stack **a_ptr, t_stack **b_ptr)
{
	t_value	x;

	if (!stkempty(*b_ptr))
		return (checker_ko(a_ptr, b_ptr));
	x = stkpop(*a_ptr);
	while (!stkempty(*a_ptr))
	{
		if (x.val > stktop(*a_ptr).val)
			return (checker_ko(a_ptr, b_ptr));
		x = stkpop(*a_ptr);
	}
	return (checker_ok(a_ptr, b_ptr));
}

static int	apply_instructions(t_stack **sa_ptr, t_stack **sb_ptr)
{
	char			*instruction;
	unsigned int	i;
	int				rd_ret;

	rd_ret = get_next_line(0, &instruction);
	while (rd_ret)
	{
		if (rd_ret == -1)
			return (ft_failure(out_of_memory, sa_ptr, sb_ptr));
		i = 0;
		while (i < INSTRUCTION_CNT
				&& ft_strcmp(g_instruction[i](NULL, NULL), instruction))
			++i;
		free(instruction);
		if (i == INSTRUCTION_CNT)
			return (checker_ko(sa_ptr, sb_ptr));
		g_instruction[i](*sa_ptr, *sb_ptr);
		rd_ret = get_next_line(0, &instruction);
	}
	free(instruction);
	instruction = NULL;
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack		*sa;
	t_stack		*sb;
	size_t		size;

	if (argc < 2)
		return (ft_exception(invalid_arguments));
	size = get_stack_size(argc - 1, (const char **)argv + 1);
	if (size == INVALID_INPUT)
		return (ft_exception(invalid_arguments));
	if (alloc_stacks(&sa, &sb, size))
		return (ft_exception(out_of_memory));
	if (fill_stack(sa, argc, (const char **)argv))
		return (ft_failure(duplicate_element, &sa, &sb));
	if (apply_instructions(&sa, &sb))
		return (-1);
	return (checker_judge(&sa, &sb));
}
