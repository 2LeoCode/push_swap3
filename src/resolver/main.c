/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 22:43:55 by leo               #+#    #+#             */
/*   Updated: 2021/09/23 18:41:24 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <resolver.h>
#include <stdio.h>

/*
** 4 3 2 1 
** 1 4 3 2 rb
** 3 2 1 4 rrb
** 3 4 2 1 sb
** 1 3 4 2 rb, sb
** 2 1 4 3 rrb, rrb
** 2 3 1 4 sb, rrb
** 4 1 3 2 sb, rb
** 4 2 1 3 rrb, sb
** 1 2 4 3 sb, rrb, rrb
** 2 1 3 4 rrb, rrb, sb
** 2 4 1 3 sb, rrb, sb
** 3 1 4 2 sb, rb, sb
** 4 2 3 1 sb, rrb, sb
** 4 3 1 2 rrb, rrb, sb
** 1 2 3 4 sb, rrb, rrb, sb
** 2 4 3 1 rrb, sb, rrb, rrb
** 3 1 2 4 rb, sb, rrb, rrb
** 1 3 2 4 sb, rrb, rrb, rrb, sb
** 2 3 4 1 rb, sb, rrb, rrb, sb
** 4 1 2 3 rb, sb, rrb, rrb, sb
** 1 4 2 3 sb, rb, sb, rrb, rrb, sb
** 3 2 4 1 sb, rb, sb, rrb, rrb, sb
** 3 4 1 2 sb, rrb, rrb, sb, rrb, rrb
*/

#define INSTR_QUEUE_SIZE 11500

#define OPCNT_4DIGITS 24

static const struct {
	const int	orders[OPCNT_4DIGITS][4];
	const char	*(*combinations[OPCNT_4DIGITS][7])();
}	g_4digits = {
	.orders = {
		{4, 3, 2, 1},
		{1, 4, 3, 2},
		{3, 2, 1, 4},
		{3, 4, 2, 1},
		{1, 3, 4, 2},
		{2, 1, 4, 3},
		{2, 3, 1, 4},
		{4, 1, 3, 2},
		{4, 2, 1, 3},
		{1, 2, 4, 3},
		{2, 1, 3, 4},
		{2, 4, 1, 3},
		{3, 1, 4, 2},
		{4, 2, 3, 1},
		{1, 2, 3, 4},
		{2, 4, 3, 1},
		{3, 1, 2, 4},
		{4, 3, 1, 2},
		{2, 3, 4, 1},
		{4, 1, 2, 3},
		{1, 3, 2, 4},
		{1, 4, 2, 3},
		{3, 2, 4, 1},
		{3, 4, 1, 2}
	},
	.combinations = {
		{NULL},
		{rb, NULL},
		{rrb, NULL},
		{sb, NULL},
		{rb, sb, NULL},
		{rb, rb, NULL},
		{sb, rrb, NULL},
		{sb, rb, NULL},
		{rrb, sb, NULL},
		{sb, rrb, rrb, NULL},
		{rrb, rrb, sb, NULL},
		{sb, rrb, sb, NULL},
		{sb, rb, sb, NULL},
		{rb, sb, rrb, NULL},
		{sb, rrb, rrb, sb, NULL},
		{rrb, sb, rrb, rrb, NULL},
		{rb, sb, rrb, rrb, NULL},
		{rrb, rrb, sb, rb, rb, NULL},
		{rb, sb, rrb, rrb, sb, NULL},
		{rb, sb, rrb, rrb, sb, NULL},
		{sb, rb, sb, rb, rb, sb, NULL},
		{sb, rb, sb, rrb, rrb, sb, NULL},
		{sb, rrb, sb, rrb, rrb, sb, NULL},
		{sb, rrb, rrb, sb, rrb, rrb, NULL}
	}
};

static __always_inline ptrdiff_t	ft_diff(void *a, void *b)
{
	ptrdiff_t	va;
	ptrdiff_t	vb;

	va = (ptrdiff_t)a;
	vb = (ptrdiff_t)b;
	if (va > vb)
		return (va - vb);
	return (vb - va);
}

static __always_inline unsigned int	ft_int_diff(int a, int b)
{
	if (a > b)
		return ((long)a - (long)b);
	return ((long)b - (long)a);
}

static __always_inline unsigned int	ft_unsigned_min(unsigned int a, unsigned int b)
{
	if (a > b)
		return (b);
	else
		return (a);
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

void	add_op(const char *(*instr)(t_stack *, t_stack *), t_stack *a, t_stack *b, t_queue *instr_queue)
{
	(*instr)(a, b);
	enqueue(instr_queue, (*instr)(NULL, NULL));
}

void	print_stack(t_stack *st)
{
	for (t_value *it = stkbegin(st); it != stkend(st); ++it) {
		printf("%d:%d:%d\n", it->val, it->sorted, it->head);
	}
}

void	push_closest_values_to_b(t_stack *a, t_stack *b, t_queue *instr_queue)
{
	t_value			*ptr_to_closest;
	t_value			*it;
	unsigned int	diff;
	int				value_to_move;

	it = stkbegin(a);
	for (int i = 0; i < 3; ++i)
	{
		it = stkbegin(a);
		while (it != stkend(a) && it->sorted)
			++it;
		ptr_to_closest = it;
		diff = INT_MAX;
		diff = ft_unsigned_min(ft_int_diff(it->val, stktop(b).val),
			ft_int_diff(it->val, stkrbegin(b)->val));
		while (it != stkend(a))
		{
			if (!it->sorted && ((diff > ft_int_diff(it->val, stktop(b).val))
			|| (diff > ft_int_diff(it->val, stkrbegin(b)->val))))
			{
				ptr_to_closest = it;
				diff = ft_unsigned_min(ft_int_diff(it->val, stktop(b).val),
					ft_int_diff(it->val, stkrbegin(b)->val));
			}
			++it;
		}
		value_to_move = ptr_to_closest->val;
		if (ft_diff(stkbegin(a), ptr_to_closest)
		< ft_diff(stkend(a), ptr_to_closest))
		{
			while (stktop(a).val != value_to_move)
				add_op(ra, a, b, instr_queue);
		}
		else
		{
			while (stktop(a).val != value_to_move)
				add_op(rra, a, b, instr_queue);
		}
		add_op(pb, a, b, instr_queue);
	}
}

bool	is_same_order(t_stack *st, const int arr[4])
{
	t_value	*ptr;
	int		i;

	if (stksize(st) != 4)
		return (false);
	ptr = stkbegin(st);
	i = -1;
	while (++i < 4)
	{
		for (int j = 0; j < 4; ++j)
			if (j != i && ((arr[i] < arr[j] && ptr[i].val > ptr[j].val)
			|| (arr[i] > arr[j] && ptr[i].val < ptr[j].val)))
				return (false);
	}
	return (true);
}

void	sort_b(t_stack *a, t_stack *b, t_queue *instr_queue)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < OPCNT_4DIGITS && !is_same_order(b, g_4digits.orders[i]))
		++i;
	j = -1;
	while (g_4digits.combinations[i][++j])
		add_op(g_4digits.combinations[i][j], a, b, instr_queue);
}

void	push_b_to_a(t_stack *a, t_stack *b, t_queue *instr_queue)
{
	t_value *it;

	it = stkbegin(b);
	stkrbegin(b)->head = true;
	while (it != stkend(b))
		(it++)->sorted = true;
	for (int i = 0; i < 4; ++i)
		add_op(pa, a, b, instr_queue);
}

void	push_first_not_sorted(t_stack *a, t_stack *b, t_queue *instr_queue)
{
	t_value	*it;
	int		value_to_move;

	it = stkbegin(a);
	while (it->sorted)
		++it;
	value_to_move = it->val;
	if (ft_diff(stkbegin(a), it) < ft_diff(stkend(a), it))
	{
		while (stktop(a).val != value_to_move)
			add_op(ra, a, b, instr_queue);
	}
	else
	{
		while (stktop(a).val != value_to_move)
			add_op(rra, a, b, instr_queue);
	}
	add_op(pb, a, b, instr_queue);
}

t_value	*next_head(t_value *it, t_stack *st)
{
	if (it == stkend(st))
		return (NULL);
	while (++it != stkend(st))
		if (it->head)
			break;
	return (it);
}

bool	last_head(t_value *it, t_stack *st)
{
	return (next_head(it, st) == stkend(st));
}

t_value	*ptr_to_min(t_stack *st)
{
	t_value	*min_ptr;
	t_value	*it;

	if (stkempty(st))
		return (NULL);
	it = stkbegin(st);
	min_ptr = it;
	while (++it != stkend(st))
	{
		if (it->val < min_ptr->val)
			min_ptr = it;
	}
	return (min_ptr);
}

void	sort_last_values(t_stack *a, t_stack *b, t_queue *instr_queue)
{
	t_value	*it = stkbegin(a);
	int		value_to_move;

	while (42) {
		while (it != stkend(a) && !it->head && !last_head(it, a) && next_head(it, a)->val > it->val)
			++it;
		if (it == stkend(a) || last_head(it, a)) break ;
		value_to_move = it->val;
		if (ft_diff(it, stkbegin(a)) < ft_diff(it, stkend(a)))
		{
			while (stktop(a).val != value_to_move)
				add_op(ra, a, b, instr_queue);
		}
		else
		{
			while (stktop(a).val != value_to_move)
				add_op(rra, a, b, instr_queue);
		}
		for (int i = 0; i < 4; ++i)
			add_op(pb, a, b, instr_queue);
		it = stkbegin(a);
	}
	while (42)
	{
		it = stkbegin(a);
		while (it != stkend(a) && it->sorted)
			++it;
		if (it == stkend(a))
			break ;
		if (it == stkrbegin(a))
			add_op(rra, a, b, instr_queue);
		if (it->val > (it + 1)->val
		|| (it != stkbegin(a) && it->val < (it - 1)->val))
		{
			value_to_move = it->val;
			if (ft_diff(it, stkbegin(a)) < ft_diff(it, stkend(a)))
			{
				while (stktop(a).val != value_to_move)
					add_op(ra, a, b, instr_queue);
			}
			else
			{
				while (stktop(a).val != value_to_move)
					add_op(rra, a, b, instr_queue);
			}
		}
		add_op(pb, a, b, instr_queue);
	}
	while (!stkempty(b))
	{
		it = stkbegin(a);
		while (it != stkend(a) && it->val < stktop(b).val)
			it = next_head(it, a);
		if (it == stkend(a))
		{
			add_op(pa, a, b, instr_queue);
			add_op(ra, a, b, instr_queue);
		}
		else
		{
			value_to_move = it->val;
			if (ft_diff(it, stkbegin(a)) < ft_diff(it, stkend(a)))
			{
				while (stktop(a).val != value_to_move)
					add_op(ra, a, b, instr_queue);
			}
			else
			{
				while (stktop(a).val != value_to_move)
					add_op(rra, a, b, instr_queue);
			}
			add_op(pa, a, b, instr_queue);
		}
	}
	it = ptr_to_min(a);
	value_to_move = it->val;
	if (ft_diff(it, stkbegin(a)) < ft_diff(it, stkend(a)))
	{
		while (stktop(a).val != value_to_move)
			add_op(ra, a, b, instr_queue);
	}
	else
	{
		while (stktop(a).val != value_to_move)
			add_op(rra, a, b, instr_queue);
	}
}

int	get_instruction_queue(t_queue *instr_queue, t_stack *a, t_stack *b, size_t size)
{
	size_t	sorted_cnt;

	sorted_cnt = 0;
	while (size - sorted_cnt >= 4)
	{
		push_first_not_sorted(a, b, instr_queue);
		push_closest_values_to_b(a, b, instr_queue);
		sort_b(a, b, instr_queue);
		push_b_to_a(a, b, instr_queue);
		sorted_cnt += 4;
	}
	if (size - sorted_cnt)
		sort_last_values(a, b, instr_queue);
	return (0);
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
