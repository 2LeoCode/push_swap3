/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 11:18:57 by lsuardi           #+#    #+#             */
/*   Updated: 2021/10/12 22:01:14 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <resolver_bonus.h>
#include <utils.h>

static void	flush_window(t_mlxptr mlx_ptr)
{
	mlx_put_image_to_window(mlx_ptr->key, mlx_ptr->win.key,
		mlx_ptr->win.img_key, 0, 0);
}

static void	mlx_number_put(t_mlxptr mlx, const int val, const int x,
				const int y)
{
	char	val_str[12];

	ft_bzero(val_str, 12 * sizeof(char));
	ft_itostr(val, val_str);
	mlx_string_put(mlx->key, mlx->win.key, x, y, COLOR_BLACK, val_str);
}

static void	put_global_strings(t_mlxptr mlx, const t_stack *st[2],
				const char *(*op)())
{
	const int *const	a_raw = stkcbegin(st[ST_A]);
	const int *const	b_raw = stkcbegin(st[ST_B]);
	size_t				i;

	if (op)
		mlx_string_put(mlx->key, mlx->win.key, 32, mlx->win.h - 2,
			COLOR_BLACK, (char *)op(NULL, NULL));
	mlx_string_put(mlx->key, mlx->win.key, 32, 11,
		COLOR_BLACK, "Stack A");
	mlx_string_put(mlx->key, mlx->win.key, mlx->win.w / 2 + TILE_GAP + 32, 11,
		COLOR_BLACK, "Stack B");
	i = stksize(st[ST_A]);
	while (i--)
		mlx_number_put(mlx, a_raw[i], TILE_GAP + 4,
			(i + 1) * (TILE_Y + TILE_GAP) + 11);
	i = stksize(st[ST_B]);
	while (i--)
		mlx_number_put(mlx, b_raw[i], mlx->win.w / 2 + TILE_GAP + 4,
			(i + 1) * (TILE_Y + TILE_GAP) + 11);
}

static void	setup_range(t_range *range, double max, double min)
{
	range->max = max;
	range->min = min;
	if (!(max - min))
		range->rg = TILE_X;
	else
		range->rg = (double)TILE_X / (max - min);
}

void	display_stacks(t_mlxptr mlx, const t_stack *a, const t_stack *b,
			const char *(*op)())
{
	const int *const	a_raw = stkcbegin(a);
	const int *const	b_raw = stkcbegin(b);
	const size_t		reset_size =
		mlx->win.h * mlx->win.w - 2 * TILE_Y * mlx->win.w;
	int					i;
	static t_range		range;

	if (!range.rg)
		setup_range(&range, stkmax(a), stkmin(a));
	ft_bzero(mlx->win.pixels + TILE_Y * mlx->win.w,
		reset_size * sizeof(t_trgb));
	i = stksize(a);
	while (--i >= 0)
		render_rect(mlx, (t_rect){TILE_GAP, (i + 1) * (TILE_Y + TILE_GAP),
			60 + range.rg * (a_raw[i] - range.min + (range.rg == TILE_X)),
			TILE_Y});
	i = stksize(b);
	while (--i >= 0)
		render_rect(mlx, (t_rect){mlx->win.w / 2 + TILE_GAP,
			(i + 1) * (TILE_Y + TILE_GAP),
			60 + range.rg * (b_raw[i] - range.min), TILE_Y});
	flush_window(mlx);
	put_global_strings(mlx, (const t_stack *[]){a, b}, op);
}
