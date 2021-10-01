/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 22:43:55 by leo               #+#    #+#             */
/*   Updated: 2021/10/01 00:51:23 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <resolver.h>
#include <stdio.h>
#include <stddef.h>

#define SWAP 0
#define ROT 1
#define RROT 2
#define PUSH 3

#define ST_A 0
#define ST_B 1

void kek(void)
{
	write(1, "kek\n", 4);
}

void	print_stack(t_stack *st)
{
	printf("=====\n");
	for (int *ptr = stkbegin(st); ptr != stkend(st); ++ptr)
		printf("%d\n", *ptr);
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

void	add_op(const char *(*op)(t_stack *, t_stack *), t_stack *a,
	t_stack *b, t_queue *instr_queue)
{
	op(a, b);
	printf("=====\n");
	printf("Op: %s\n", op(NULL, NULL));
	enqueue(instr_queue, op(NULL, NULL));
	print_stack(a);
	print_stack(b);
	usleep(500000);
}

void	reorderstart(t_stack *cur, t_stack *st[2], const char *(*moveset[4])(),
			t_queue *instr_queue)
{
	const int	*rbegin;

	rbegin = stkrcbegin(cur);
	if (cur == st[ST_A])
	{
		while (*rbegin < stktop(cur))
			add_op(moveset[RROT], st[ST_A], st[ST_B], instr_queue);
	}
	else
	{
		while (*rbegin > stktop(cur))
			add_op(moveset[RROT], st[ST_A], st[ST_B], instr_queue);
	}
}

ptrdiff_t	ft_ptrdiff(void *a, void *b)
{
	if (a < b)
		return (b - a);
	return (a - b);
}

int	*next_streak(t_stack *cur, t_stack *st[2])
{
	int	*begin;

	begin = stkbegin(cur) + 1;
	if (cur == st[ST_A])
	{
		while (begin != stkrbegin(cur) && *begin < *(begin + 1))
			++begin;
	}
	else
	{
		while (begin != stkrbegin(cur) && *begin > *(begin + 1))
			++begin;
	}
	if (begin != stkrbegin(cur))
		return (begin);
	++begin;
	return (begin);
}

void	reorderend(t_stack *a, t_stack *b, t_queue *instr_queue)
{
	int	*ptr;
	int	topvalue;

	ptr = stkbegin(a);
	while (++ptr != stkend(a) && *ptr > *(ptr - 1))
		continue ;
	if (ptr != stkend(a))
	{
		topvalue = *ptr;
		if (ft_ptrdiff(stkbegin(a), ptr) > ft_ptrdiff(stkend(a), ptr))
		{
			while (stktop(a) != topvalue)
				add_op(ra, a, b, instr_queue);
		}
		else
		{
			while (stktop(a) != topvalue)
				add_op(rra, a, b, instr_queue);
		}
	}
}

void	reorderpush(t_stack *cur, t_stack *st[2], const char *(*moveset[4])(),
			t_queue *instr_queue)
{
	int	opposite_topval;
	int	*ptr;
	int	val;

	if (cur == st[ST_A])
	{
		opposite_topval = stktop(st[ST_B]);
		printf("%d, %d\n", opposite_topval, stktop(cur));
		if (opposite_topval > stktop(cur))
		{
			ptr = stkbegin(cur);
			while (ptr != stkrbegin(cur) && *ptr < opposite_topval && *(ptr + 1) > *ptr)
				++ptr;
			val = *ptr;
			while (stktop(cur) != val)
				add_op(moveset[ROT], st[ST_A], st[ST_B], instr_queue);
		}
		else
		{
			ptr = stkrbegin(cur);
			if (*ptr < stktop(cur))
			{
				while (ptr != stkbegin(cur) && *ptr < opposite_topval && *ptr > *(ptr - 1))
					--ptr;
				val = *ptr;
				while (stktop(cur) != val)
					add_op(moveset[RROT], st[ST_A], st[ST_B], instr_queue);
			}
		}
	}
	else
	{
		opposite_topval = stktop(st[ST_A]);
		printf("%d, %d\n", opposite_topval, stktop(cur));
		if (opposite_topval < stktop(cur))
		{
			ptr = stkbegin(cur);
			while (ptr != stkrbegin(cur) && *ptr > opposite_topval && *(ptr + 1) < *ptr)
				++ptr;
			if (ptr != stkrbegin(cur))
			{
				val = *ptr;
				while (stktop(cur) != val)
					add_op(moveset[ROT], st[ST_A], st[ST_B], instr_queue);
			}
		}
		else
		{
			ptr = stkrbegin(cur);
			if (*ptr > stktop(cur))
			{
				while (ptr != stkbegin(cur) && *ptr > opposite_topval && *ptr < *(ptr - 1))
					--ptr;
				val = *ptr;
				while (stktop(cur) != val)
					add_op(moveset[RROT], st[ST_A], st[ST_B], instr_queue);
			}
		}
	}
	add_op(moveset[PUSH], st[ST_A], st[ST_B], instr_queue);
}

size_t	streak_size(t_stack *cur, t_stack *st[2])
{
	size_t		size;
	const int	*cbegin;
	const int	*crbegin;

	cbegin = stkcbegin(cur);
	crbegin = stkrcbegin(cur);
	size = 1;
	if (cur == st[ST_A])
	{
		if (*crbegin < *cbegin)
		{
			while (crbegin != cbegin && *(crbegin - 1) < *crbegin)
			{
				--crbegin;
				++size;
			}
		}
		while (cbegin != crbegin && *cbegin < *(cbegin + 1))
		{
			++cbegin;
			++size;
		}
	}
	else
	{
		if (*crbegin > *cbegin)
		{
			while (crbegin != cbegin && *(crbegin - 1) > *crbegin)
			{
				--crbegin;
				++size;
			}
		}
		while (cbegin != crbegin && *cbegin > *(cbegin + 1))
		{
			++cbegin;
			++size;
		}
	}
	return (size);
}

int	get_instruction_queue(t_queue *instr_queue, t_stack *a, t_stack *b,
	size_t size)
{
	size_t	strk_size;
	int		*ptr;
	int		val;

	print_stack(a);
	print_stack(b);

	reorderstart(a, (t_stack *[2]){a, b}, (const char *(*[4])()){sa, ra, rra,
		pb}, instr_queue);
	while (stksize(a) > 3 * size / 4)
	{
		if (stktop(a) > *(stkbegin(a) + 1))
			add_op(sa, a, b, instr_queue);
		strk_size = streak_size(a, (t_stack *[2]){a, b});
		while (strk_size--)
			add_op(pb, a, b, instr_queue);
	}
	kek();
	while (streak_size(a, (t_stack *[2]){a, b}) != stksize(a) || streak_size(b, (t_stack *[2]){a, b}) != stksize(b))
	{
		printf("%zu :: %zu\n", streak_size(a, (t_stack *[2]){a, b}), streak_size(b, (t_stack *[2]){a, b}));
		ptr = next_streak(a, (t_stack *[2]){a, b});
		while (ptr != stkend(a))
		{
			val = *ptr;
			while (stktop(a) != val)
				reorderpush(b, (t_stack *[2]){a, b},
					(const char *(*[4])()){sb, rb, rrb, pb}, instr_queue);
			ptr = next_streak(a, (t_stack *[2]){a, b});
		}
		reorderstart(b, (t_stack *[2]){a, b}, (const char *(*[4])()){sb, rb,
			rrb, pa}, instr_queue);
		ptr = next_streak(b, (t_stack *[2]){a, b});
		while (ptr != stkend(b))
		{
			val = *ptr;
			while (stktop(b) != val)
				reorderpush(a, (t_stack *[2]){a, b}, (const char *(*[4])()){sa,
					ra, rra, pa}, instr_queue);
			kek();
			ptr = next_streak(b, (t_stack *[2]){a, b});
		}
		reorderstart(a, (t_stack *[2]){a, b}, (const char *(*[4])()){sa, ra,
			rra, pb}, instr_queue);
	}
	while (!stkempty(b))
		reorderpush(a, (t_stack *[2]){a, b}, (const char *(*[4])()){sa,
			ra, rra, pa}, instr_queue);
	reorderend(a, b, instr_queue);
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
