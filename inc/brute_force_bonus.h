/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brute_force_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 01:03:55 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/12 16:14:01 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRUTE_FORCE_BONUS_H
# define BRUTE_FORCE_BONUS_H

# include "resolver_bonus.h"

# define CNT_2 2
# define CNT_3 6
# define CNT_4 24
# define CNT_5 120

typedef struct s_mlx	*t_mlxptr;
typedef const char		*t_op(t_stack *, t_stack *);

static const struct s_2combi {
	int		cnt;
	int		order[CNT_2][2];
	t_op	*op[CNT_2][2];
}	g_2combi = {
		.cnt = CNT_2,
		.order = {
			{0, 1},
			{1, 0}
		},
		.op = {
			{NULL},
			{sa, NULL}
		}
};

static const struct s_3combi {
	int		cnt;
	int		order[CNT_3][3];
	t_op	*op[CNT_3][3];
}	g_3combi = {
		.cnt = CNT_3,
		.order = {
			{0, 1, 2},
			{0, 2, 1},
			{1, 0, 2},
			{1, 2, 0},
			{2, 0, 1},
			{2, 1, 0}
		},
		.op = {
			{NULL},
			{rra, sa, NULL},
			{sa, NULL},
			{rra, NULL},
			{ra, NULL},
			{sa, rra, NULL}
		}
};

static const struct s_4combi {
	int		cnt;
	int		order[CNT_4][4];
	t_op	*op[CNT_4][7];
}	g_4combi = {
	.cnt = CNT_4,
	.order = {
		{0, 1, 2, 3},
		{0, 1, 3, 2},
		{0, 2, 1, 3},
		{0, 2, 3, 1},
		{0, 3, 1, 2},
		{0, 3, 2, 1},
		{1, 0, 2, 3},
		{1, 0, 3, 2},
		{1, 2, 0, 3},
		{1, 2, 3, 0},
		{1, 3, 0, 2},
		{1, 3, 2, 0},
		{2, 0, 1, 3},
		{2, 0, 3, 1},
		{2, 1, 0, 3},
		{2, 1, 3, 0},
		{2, 3, 0, 1},
		{2, 3, 1, 0},
		{3, 0, 1, 2},
		{3, 0, 2, 1},
		{3, 1, 0, 2},
		{3, 1, 2, 0},
		{3, 2, 0, 1},
		{3, 2, 1, 0}
	},
	.op = {
		{NULL},
		{pb, rra, sa, pa, NULL},
		{ra, sa, rra, NULL},
		{rra, sa, NULL},
		{sa, ra, NULL},
		{pb, sa, rra, pa, NULL},
		{sa, NULL},
		{pb, rra, sa, pa, sa, NULL},
		{rra, pb, rra, pa, ra, NULL},
		{rra, NULL},
		{rra, sa, rra, NULL},
		{pb, sa, pa, rra, NULL},
		{rra, sa, ra, ra, NULL},
		{sa, rra, sa, NULL},
		{pb, sa, rra, pa, ra, ra, NULL},
		{sa, rra, NULL},
		{ra, ra, NULL},
		{ra, ra, sa, NULL},
		{ra, NULL},
		{pb, sa, ra, pa, ra, NULL},
		{ra, sa, NULL},
		{pb, rra, pa, ra, NULL},
		{pb, ra, pa, ra, NULL},
		{pb, sa, rra, pa, ra, NULL}
	}
};

static const struct s_5combi {
	int		cnt;
	int		order[CNT_5][5];
	t_op	*op[CNT_5][10];
}	g_5combi = {
	.cnt = CNT_5,
	.order = {
		{0, 1, 2, 3, 4},
		{0, 1, 2, 4, 3},
		{0, 1, 3, 2, 4},
		{0, 1, 3, 4, 2},
		{0, 1, 4, 2, 3},
		{0, 1, 4, 3, 2},
		{0, 2, 1, 3, 4},
		{0, 2, 1, 4, 3},
		{0, 2, 3, 1, 4},
		{0, 2, 3, 4, 1},
		{0, 2, 4, 1, 3},
		{0, 2, 4, 3, 1},
		{0, 3, 1, 2, 4},
		{0, 3, 1, 4, 2},
		{0, 3, 2, 1, 4},
		{0, 3, 2, 4, 1},
		{0, 3, 4, 1, 2},
		{0, 3, 4, 2, 1},
		{0, 4, 1, 2, 3},
		{0, 4, 1, 3, 2},
		{0, 4, 2, 1, 3},
		{0, 4, 2, 3, 1},
		{0, 4, 3, 1, 2},
		{0, 4, 3, 2, 1},
		{1, 0, 2, 3, 4},
		{1, 0, 2, 4, 3},
		{1, 0, 3, 2, 4},
		{1, 0, 3, 4, 2},
		{1, 0, 4, 2, 3},
		{1, 0, 4, 3, 2},
		{1, 2, 0, 3, 4},
		{1, 2, 0, 4, 3},
		{1, 2, 3, 0, 4},
		{1, 2, 3, 4, 0},
		{1, 2, 4, 0, 3},
		{1, 2, 4, 3, 0},
		{1, 3, 0, 2, 4},
		{1, 3, 0, 4, 2},
		{1, 3, 2, 0, 4},
		{1, 3, 2, 4, 0},
		{1, 3, 4, 0, 2},
		{1, 3, 4, 2, 0},
		{1, 4, 0, 2, 3},
		{1, 4, 0, 3, 2},
		{1, 4, 2, 0, 3},
		{1, 4, 2, 3, 0},
		{1, 4, 3, 0, 2},
		{1, 4, 3, 2, 0},
		{2, 0, 1, 3, 4},
		{2, 0, 1, 4, 3},
		{2, 0, 3, 1, 4},
		{2, 0, 3, 4, 1},
		{2, 0, 4, 1, 3},
		{2, 0, 4, 3, 1},
		{2, 1, 0, 3, 4},
		{2, 1, 0, 4, 3},
		{2, 1, 3, 0, 4},
		{2, 1, 3, 4, 0},
		{2, 1, 4, 0, 3},
		{2, 1, 4, 3, 0},
		{2, 3, 0, 1, 4},
		{2, 3, 0, 4, 1},
		{2, 3, 1, 0, 4},
		{2, 3, 1, 4, 0},
		{2, 3, 4, 0, 1},
		{2, 3, 4, 1, 0},
		{2, 4, 0, 1, 3},
		{2, 4, 0, 3, 1},
		{2, 4, 1, 0, 3},
		{2, 4, 1, 3, 0},
		{2, 4, 3, 0, 1},
		{2, 4, 3, 1, 0},
		{3, 0, 1, 2, 4},
		{3, 0, 1, 4, 2},
		{3, 0, 2, 1, 4},
		{3, 0, 2, 4, 1},
		{3, 0, 4, 1, 2},
		{3, 0, 4, 2, 1},
		{3, 1, 0, 2, 4},
		{3, 1, 0, 4, 2},
		{3, 1, 2, 0, 4},
		{3, 1, 2, 4, 0},
		{3, 1, 4, 0, 2},
		{3, 1, 4, 2, 0},
		{3, 2, 0, 1, 4},
		{3, 2, 0, 4, 1},
		{3, 2, 1, 0, 4},
		{3, 2, 1, 4, 0},
		{3, 2, 4, 0, 1},
		{3, 2, 4, 1, 0},
		{3, 4, 0, 1, 2},
		{3, 4, 0, 2, 1},
		{3, 4, 1, 0, 2},
		{3, 4, 1, 2, 0},
		{3, 4, 2, 0, 1},
		{3, 4, 2, 1, 0},
		{4, 0, 1, 2, 3},
		{4, 0, 1, 3, 2},
		{4, 0, 2, 1, 3},
		{4, 0, 2, 3, 1},
		{4, 0, 3, 1, 2},
		{4, 0, 3, 2, 1},
		{4, 1, 0, 2, 3},
		{4, 1, 0, 3, 2},
		{4, 1, 2, 0, 3},
		{4, 1, 2, 3, 0},
		{4, 1, 3, 0, 2},
		{4, 1, 3, 2, 0},
		{4, 2, 0, 1, 3},
		{4, 2, 0, 3, 1},
		{4, 2, 1, 0, 3},
		{4, 2, 1, 3, 0},
		{4, 2, 3, 0, 1},
		{4, 2, 3, 1, 0},
		{4, 3, 0, 1, 2},
		{4, 3, 0, 2, 1},
		{4, 3, 1, 0, 2},
		{4, 3, 1, 2, 0},
		{4, 3, 2, 0, 1},
		{4, 3, 2, 1, 0}
	},
	.op = {
		{NULL},
		{rra, rra, sa, ra, ra, NULL},
		{pb, pb, sa, pa, pa, NULL},
		{pb, pb, rra, pa, pa, NULL},
		{pb, pb, ra, pa, pa, NULL},
		{pb, pb, ra, sa, pa, pa, NULL},
		{ra, sa, rra, NULL},
		{pb, sa, pb, sa, ra, pa, pa, NULL},
		{rra, rra, sa, ra, sa, NULL},
		{rra, sa, NULL},
		{pb, sa, ra, sa, pa, NULL},
		{pb, sa, rra, sa, ra, pa, NULL},
		{sa, rra, sa, ra, ra, NULL},
		{pb, sa, rra, sa, pa, NULL},
		{pb, sa, pb, sa, ra, pa, rra, pa, NULL},
		{pb, sa, rra, pa, NULL},
		{pb, rra, rra, pa, NULL},
		{pb, rra, pb, rra, pa, pa, NULL},
		{pb, ra, pa, NULL},
		{pb, pb, rra, sa, pa, ra, pa, NULL},
		{pb, pb, sa, pa, ra, pa, NULL},
		{pb, rra, pb, ra, pa, pa, NULL},
		{pb, sa, ra, ra, pa, NULL},
		{pb, rra, pb, ra, sa, pa, pa, NULL},
		{sa, NULL},
		{pb, pb, rra, ss, pa, pa, NULL},
		{pb, pb, ss, pa, pa, NULL},
		{sa, pb, pb, rra, pa, pa, NULL},
		{sa, pb, pb, ra, pa, pa, NULL},
		{pb, pb, ss, rra, pa, pa, NULL},
		{pb, pb, ra, pa, pa, rra, NULL},
		{pb, pb, sa, rra, pa, pa, rra, NULL},
		{rra, pb, rra, pa, ra, NULL},
		{rra, NULL},
		{pb, pb, ra, ra, pa, pa, rra, NULL},
		{pb, pb, sa, pa, pa, rra, NULL},
		{pb, sa, pb, ss, pa, pa, NULL},
		{pb, sa, pb, rrr, pa, pa, NULL},
		{pb, sa, pb, sa, ra, pa, pa, rra, NULL},
		{pb, sa, pa, rra, NULL},
		{pb, rra, pa, rra, NULL},
		{pb, rra, pb, rrr, pa, pa, NULL},
		{pb, ra, ra, pa, rra, NULL},
		{pb, rra, pb, rra, pa, pa, rra, NULL},
		{pb, sa, pb, rra, pa, pa, rra, NULL},
		{pb, rra, pb, rr, pa, pa, NULL},
		{pb, rra, pb, sa, pa, pa, rra, NULL},
		{pb, rra, pb, ss, rra, pa, pa, NULL},
		{sa, ra, sa, rra, NULL},
		{pb, pb, ss, rra, pa, rra, pa, NULL},
		{pb, pb, ss, ra, pa, rra, pa, NULL},
		{sa, pb, rra, pb, pa, pa, NULL},
		{pb, pb, rrr, pa, rra, pa, NULL},
		{pb, pb, ss, pa, rra, pa, NULL},
		{pb, pb, rr, pa, pa, rra, NULL},
		{pb, pb, ra, ss, pa, pa, rra, NULL},
		{sa, rra, rra, sa, ra, NULL},
		{sa, rra, NULL},
		{pb, pb, rrr, pa, pa, rra, NULL},
		{pb, pb, ss, pa, pa, rra, NULL},
		{pb, sa, pb, ss, ra, pa, rra, pa, NULL},
		{pb, pb, sa, pa, pa, rra, rra, NULL},
		{pb, pb, sa, rra, pa, pa, rra, rra, NULL},
		{pb, pb, ra, pa, pa, rra, rra, NULL},
		{rra, rra, NULL},
		{rra, rra, sa, NULL},
		{pb, rra, pa, rra, rra, NULL},
		{pb, rra, pb, rrr, pa, pa, rra, NULL},
		{pb, pb, sa, pa, rra, pa, rra, rra, NULL},
		{pb, pb, rra, pa, rra, pa, rra, rra, NULL},
		{pb, pb, ra, pa, rra, pa, rra, rra, NULL},
		{pb, pb, sa, rra, pa, rra, pa, rra, rra, NULL},
		{pb, pb, rrr, pa, ra, ra, pa, NULL},
		{pb, pb, ss, pa, ra, ra, pa, NULL},
		{pb, pb, ss, rra, pa, ra, ra, pa, NULL},
		{pb, pb, rr, pa, ra, ra, pa, NULL},
		{pb, pb, sb, pa, ra, ra, pa, NULL},
		{pb, pb, ss, ra, pa, ra, ra, pa, NULL},
		{pb, pb, rr, ra, pa, rra, pa, rra, NULL},
		{pb, pb, ss, pa, rra, pa, rra, NULL},
		{pb, pb, ss, rra, pa, rra, pa, rra, NULL},
		{pb, pb, rr, pa, rra, pa, rra, NULL},
		{ra, pb, rra, rra, pa, rra, NULL},
		{pb, pb, ss, ra, pa, rra, pa, rra, NULL},
		{pb, pb, rrr, pa, pa, rra, rra, NULL},
		{pb, pb, ss, pa, pa, rra, rra, NULL},
		{pb, pb, ss, rra, pa, pa, rra, rra, NULL},
		{pb, pb, rr, pa, pa, rra, rra, NULL},
		{sa, rra, rra, NULL},
		{pb, pb, ss, ra, pa, pa, rra, rra, NULL},
		{ra, ra, NULL},
		{rra, rra, sa, rra, NULL},
		{ra, ra, sa, NULL},
		{pb, pb, rra, pa, pa, ra, ra, NULL},
		{pb, pb, ra, pa, pa, ra, ra, NULL},
		{pb, pb, sa, rra, pa, pa, ra, ra, NULL},
		{ra, NULL},
		{pb, pb, ss, ra, pa, ra, pa, NULL},
		{pb, pb, ss, pa, ra, pa, NULL},
		{pb, pb, rrr, pa, ra, pa, NULL},
		{pb, pb, rr, pa, ra, pa, NULL},
		{pb, pb, ss, rra, pa, ra, pa, NULL},
		{ra, pb, ra, pa, rra, NULL},
		{ra, pb, pb, ss, pa, pa, NULL},
		{ra, pb, ra, pb, rrr, pa, pa, NULL},
		{ra, pb, rra, rra, pb, rr, pa, pa, NULL},
		{pb, pb, rr, pa, ra, ra, pa, rra, NULL},
		{pb, rra, pb, ss, ra, pa, ra, pa, NULL},
		{ra, pb, ra, ra, pa, rra, rra, NULL},
		{pb, pb, ss, ra, pa, rra, pa, rra, rra, NULL},
		{pb, pb, ss, pa, rra, pa, rra, rra, NULL},
		{pb, pb, rrr, pa, rra, pa, rra, rra, NULL},
		{pb, pb, rr, pa, rra, pa, rra, rra, NULL},
		{pb, pb, ss, rra, pa, rra, pa, rra, rra, NULL},
		{sa, ra, ra, NULL},
		{pb, pb, ss, ra, pa, pa, ra, ra, NULL},
		{pb, pb, ss, pa, pa, ra, ra, NULL},
		{pb, pb, rrr, pa, pa, ra, ra, NULL},
		{pb, pb, rr, pa, pa, ra, ra, NULL},
		{pb, pb, ss, rra, pa, pa, ra, ra, NULL}
	}
};

void	sort_2numbers(t_mlxptr mlx, t_stack *st[2], t_queue *instr,
			const size_t size);
void	sort_3numbers(t_mlxptr mlx, t_stack *st[2], t_queue *instr,
			const size_t size);
void	sort_4numbers(t_mlxptr mlx, t_stack *st[2], t_queue *instr,
			const size_t size);
void	sort_5numbers(t_mlxptr mlx, t_stack *st[2], t_queue *instr,
			const size_t size);
bool	same_order(const int *a, const int *b, size_t size);
void	apply_instructions(t_mlxptr mlx, t_stack *st[2], t_op *const *op,
			t_queue *instr);

#endif
