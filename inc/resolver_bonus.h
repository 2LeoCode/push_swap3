/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolver_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:16:36 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/12 16:19:56 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESOLVER_BONUS_H
# define RESOLVER_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stddef.h>
# include <mlx.h>

# include "common.h"
# include "queue.h"

# define ST_A 0
# define ST_B 1

# define ORDER_A 1
# define ORDER_B -1

# define BEGIN_FUN 0
# define NEXT_FUN 1

# define INSTR_QUEUE_SIZE 128000
# define TILE_X 512
# define TILE_Y 12
# define TILE_GAP 2

# define COLOR_WHITE 0xffffffffU
# define COLOR_BLACK 0x00000000U

typedef struct s_mlx *	t_mlxptr;
typedef struct s_mlx	t_mlxvar;

typedef struct s_rect {
	int	x;
	int	y;
	int	w;
	int	h;
}	t_rect;

typedef struct s_trgb {
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;
	unsigned char	t;
}	t_trgb;

typedef struct s_window {
	void	*key;
	char	*title;
	int		w;
	int		h;
	struct {
		void	*img_key;
		int		bpp;
		int		size_line;
		int		endian;
		t_trgb	*pixels;
	};
}	t_window;

struct s_mlx {
	void		*key;
	t_window	win;
};

typedef struct s_range {
	double	max;
	double	min;
	double	rg;
}	t_range;

void	render_head(t_mlxptr mlx);
void	render_foot(t_mlxptr mlx);
void	render_rect(t_mlxptr mlx, const t_rect rect);

void	setup_streaks(t_mlxptr mlx, t_stack *st[2], t_queue *instr);
void	sort_loop(t_mlxptr mlx, t_stack *st[2], t_queue *instr);

size_t	next_streak_init(t_stack *st, size_t cur, int order);
size_t	begin_streak_init(t_stack *st, size_t cur, int order);
size_t	next_streak(t_stack *st, size_t cur, int order);
size_t	begin_streak(t_stack *st, size_t cur, int order);
size_t	streak_count(t_stack *st, int order, size_t (*nextfun)(),
			bool th_swap);

void	insert_atob(t_mlxptr mlx, t_stack *st[2], t_queue *instr,
			size_t strk_cnt);
void	push_atob(t_mlxptr mlx, t_stack *st[2], t_queue *instr,
			size_t strk_cnt);
void	insert_btoa(t_mlxptr mlx, t_stack *st[2], t_queue *instr,
			size_t strk_cnt);
void	push_btoa(t_mlxptr mlx, t_stack *st[2], t_queue *instr,
			size_t strk_cnt);

void	reorder_a(t_mlxptr mlx, t_stack *st[2], t_queue *instr,
			size_t (*strkfun[2])());

void	destroy_display(t_mlxptr mlxvar);
int		init_display(t_mlxptr mlxvar, char *title, t_stack *a, t_stack *b);
void	display_stacks(t_mlxptr mlx, const t_stack *a, const t_stack *b,
			const char *(*op)());

size_t	stack_next_index(size_t cur, size_t tot_size);
size_t	stack_prev_index(size_t cur, size_t tot_size);
int		alloc_queue(t_queue **queue, size_t size);
void	print_instructions(t_queue *queue);
void	add_op(t_mlxptr mlxptr, const char *(*op)(t_stack *, t_stack *),
			t_stack *st[2], t_queue *instr_queue);

int		brute_force(t_mlxptr mlx, t_stack *st[2], t_queue *instr);

#endif
