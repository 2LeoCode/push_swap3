/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 11:18:57 by lsuardi           #+#    #+#             */
/*   Updated: 2021/10/01 18:40:47 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <resolver.h>
#include <resolver_int.h>
#include <mlx.h>
#include <utils.h>

void	display_head(t_mlxptr mlx)
{
	const unsigned int	white = 0x00ffffff;
	const unsigned int	black = 0x00000000;
	int					i;
	int					j;

	i = ~0;
	while (++i < TILE_Y)
	{
		j = -1;
		while (++j < mlx->win.w)
			mlx->win.pixels[i * mlx->win.w + j] = *(t_trgb *)&white;
	}
	mlx_put_image_to_window(mlx->key, mlx->win.key, mlx->win.img_key, 0, 0);
	mlx_string_put(mlx->key, mlx->win.key, TILE_X / 3 + 2, TILE_Y / 3, black,
		"A");
	mlx_string_put(mlx->key, mlx->win.key, TILE_X + TILE_X / 3 + 4, TILE_Y / 3,
		black, "B");
}

void	display_foot(t_mlxptr mlx)
{
	const unsigned int	white = 0x00ffffff;
	const unsigned int	black = 0x00000000;
	int					i;
	int					j;

	i = mlx->win.h - TILE_Y;
	while (++i < mlx->win.h)
	{
		j = -1;
		while (++j < mlx->win.w)
			mlx->win.pixels[i * mlx->win.w + j] = *(t_trgb *)&white;
	}
	mlx_put_image_to_window(mlx->key, mlx->win.key, mlx->win.img_key, 0, 0);
}

int	init_display(t_mlxptr mlxvar, char *title, t_stack *a, t_stack *b)
{
	const int	tot_size = stksize(a) + stksize(b);

	mlxvar->win.w = TILE_X * 2 + 6;
	mlxvar->win.h = TILE_Y * (tot_size + 2) + 2 * tot_size + 4;
	mlxvar->win.title = ft_strdup(title);
	mlxvar->key = mlx_init();
	mlxvar->win.key = mlx_new_window(mlxvar->key, mlxvar->win.w,
		mlxvar->win.h, title);
	mlxvar->win.img_key = mlx_new_image(mlxvar->key, mlxvar->win.w,
		mlxvar->win.h);
	if (mlxvar->win.img_key)
		mlxvar->win.pixels = mlx_get_data_addr(mlxvar->win.img_key,
			&mlxvar->win.bpp, &mlxvar->win.size_line, &mlxvar->win.endian);
	if (mlxvar->win.title && mlxvar->key && mlxvar->win.key
			&& mlxvar->win.img_key && mlxvar->win.pixels)
	{
		free(title);
		mlx_destroy_image(mlxvar->key, mlxvar->win.img_key);
		mlx_destroy_window(mlxvar->key, mlxvar->win.key);
		mlx_destroy_display(mlxvar->key);
		return (-1);
	}
	display_head(mlxvar);
	display_foot(mlxvar);
	display_stacks(mlxvar, a, b, NULL);
	return (0);
}

void	put_tile(t_mlxptr mlx, const int val, const int x, const int y)
{
	const unsigned int	white = 0x00ffffff;
	const unsigned int	black = 0x00000000;
	char				val_str[12];
	int					end_x;
	int					end_y;
	int					i;
	int					j;

	end_x = x + TILE_X;
	end_y = y + TILE_Y;
	if (end_x > mlx->win.w)
		end_x = mlx->win.w;
	if (end_y > mlx->win.h)
		end_y = mlx->win.h;
	ft_bzero(val_str, 12 * sizeof(char));
	ft_itostr(val, val_str);
	i = y;
	while (++i <= end_y)
	{
		j = x + 1;
		while (++i < end_x)
			mlx->win.pixels[end_y * mlx->win.w + end_x] = *(t_trgb *)&white;
	}
	mlx_put_image_to_window(mlx->key, mlx->win.img_key, mlx->win.key, 0, 0);
	mlx_string_put(mlx->key, mlx->win.key, x + TILE_X / 3, y + TILE_Y / 3, black, val_str);
}

void	display_stacks(t_mlxptr mlx, const t_stack *a, const t_stack *b,
	const char *(*op)())
{
	const int *const	a_raw = stkbegin(a);
	const int *const	b_raw = stkbegin(b);
	const size_t		reset_size =
		mlx->win.h * mlx->win.w - 2 * TILE_Y * mlx->win.w;
	int					i;
	int					j;

	ft_bzero(mlx->win.pixels + TILE_Y * mlx->win.w, reset_size);
	i = stksize(a);
	j = stksize(b);
	while (i--)
		put_tile(mlx, a_raw[i], 2, (i + 1) * TILE_Y + 2 * (i + 1));
	while (j--)
		put_tile(mlx, b_raw[j], TILE_X + 4, (j + 1) * TILE_Y + 2 * (j + 1));
	if (op)
		mlx_string_put(mlx->key, mlx->win.key, 64, mlx->win.h - 2 * TILE_Y / 3, black, op(NULL, NULL));
	usleep(500000);
}
