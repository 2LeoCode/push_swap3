/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolver.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:16:36 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/12 16:20:07 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESOLVER_H
# define RESOLVER_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stddef.h>

# include "common.h"
# include "queue.h"

# define ST_A 0
# define ST_B 1

# define ORDER_A 1
# define ORDER_B -1

# define BEGIN_FUN 0
# define NEXT_FUN 1

# define INSTR_QUEUE_SIZE 128000

void	setup_streaks(t_stack *st[2], t_queue *instr);
void	sort_loop(t_stack *st[2], t_queue *instr);

size_t	next_streak_init(t_stack *st, size_t cur, int order);
size_t	begin_streak_init(t_stack *st, size_t cur, int order);
size_t	next_streak(t_stack *st, size_t cur, int order);
size_t	begin_streak(t_stack *st, size_t cur, int order);
size_t	streak_count(t_stack *st, int order, size_t (*nextfun)(),
			bool th_swap);

void	insert_atob(t_stack *st[2], t_queue *instr, size_t strk_cnt);
void	push_atob( t_stack *st[2], t_queue *instr, size_t strk_cnt);
void	insert_btoa(t_stack *st[2], t_queue *instr, size_t strk_cnt);
void	push_btoa(t_stack *st[2], t_queue *instr, size_t strk_cnt);

void	reorder_a(t_stack *st[2], t_queue *instr, size_t (*strkfun[2])());

size_t	stack_next_index(size_t cur, size_t tot_size);
size_t	stack_prev_index(size_t cur, size_t tot_size);
int		alloc_queue(t_queue **queue, size_t size);
void	print_instructions(t_queue *queue);
void	add_op(const char *(*op)(t_stack *, t_stack *),
			t_stack *st[2], t_queue *instr_queue);

int		brute_force(t_stack *st[2], t_queue *instr);

#endif
