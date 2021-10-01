/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 11:18:57 by lsuardi           #+#    #+#             */
/*   Updated: 2021/10/01 16:24:59 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <resolver.h>
#include <resolver_int.h>
#include <mlx.h>

int	init_mlxptr(t_mlxptr mlxvar, size_t stack_size, char *title)
{
	mlxvar->win.w = TILE_X * 2 + 6;
	mlxvar->win.h = TILE_Y * (stack_size + 1);
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
		return (0);
	free(title);
	mlx_destroy_image(mlxvar->key, mlxvar->win.img_key);
	mlx_destroy_window(mlxvar->key, mlxvar->win.key);
	mlx_destroy_display(mlxvar->key);
	return (-1);
}

void	display_head(t_mlxptr mlx)
{
	const unsigned int	white = 0x00ffffff;
	const unsigned int	black = 0x00000000;
	size_t				i;
	size_t				j;

	j = ~0;
	while (++j < TILE_Y)
	{
		i = ~0;
		while (++i < mlx->win.w)
			mlx->win.pixels[j * mlx->win.w + i] = *(t_trgb *)&white;
	}
	j = mlx->win.h - TILE_Y;
	while (++j < mlx->win.h)
	{
		i = ~0;
		while (++i < mlx->win.w)
			mlx->win.pixels[j * mlx->win.w + i] = *(t_trgb *)&white;
	}
	mlx_put_image_to_window(mlx->key, mlx->win.key, mlx->win.img_key, 0, 0);
	mlx_string_put(mlx->key, mlx->win.key, TILE_X / 3 + 2, TILE_Y / 3, black,
		"A");
	mlx_string_put(mlx->key, mlx->win.key, TILE_X + TILE_X / 3 + 4, TILE_Y / 3,
		black, "B");
}

size_t	number_size(int nb)
{
	size_t	size;

	size = (nb <= 0);
	while (nb)
	{
		++size;
		nb /= 10;
	}
	return (size);
}

void	ft_itostr(int n, char str[12])
{
	const size_t	size = number_size(n);
	static int		index = -2;

	
}

void	put_tile(t_mlxptr mlx, int val, int x, int y)
{
	char	val_str[12];

	ft_bzero(val_str, 12 * sizeof(char));
	ft_itostr(val, val_str);

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
		put_tile(mlx, a_raw[i], 2, (i + 1) * TILE_Y + 2 * i);
	while (j--)
		put_tile(mlx, b_raw[j], TILE_X + 4, (j + 1) * TILE_Y + 2 * (j + 1));
}
