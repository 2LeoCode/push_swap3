/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:50:28 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/12 15:17:49 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <resolver_bonus.h>

static int	init_display_failure(t_mlxptr mlxvar)
{
	destroy_display(mlxvar);
	return (-1);
}

int	init_display(t_mlxptr mlxvar, char *title, t_stack *a, t_stack *b)
{
	const int	tot_size = stksize(a) + stksize(b);


	mlxvar->win.w = 60 * 2 + TILE_X * 2 + 3 * TILE_GAP;
	mlxvar->win.h = TILE_Y * (tot_size + 2) + TILE_GAP * (tot_size + 1);
	mlxvar->win.title = ft_strdup(title);
	mlxvar->key = mlx_init();
	if (mlxvar->key)
	{
		mlxvar->win.key = mlx_new_window(mlxvar->key, mlxvar->win.w,
				mlxvar->win.h, title);
		mlxvar->win.img_key = mlx_new_image(mlxvar->key, mlxvar->win.w,
				mlxvar->win.h);
		if (mlxvar->win.img_key)
			mlxvar->win.pixels = (t_trgb *)mlx_get_data_addr(
					mlxvar->win.img_key, &mlxvar->win.bpp,
					&mlxvar->win.size_line, &mlxvar->win.endian);
	}
	if (!(mlxvar->win.title && mlxvar->key && mlxvar->win.key
			&& mlxvar->win.img_key && mlxvar->win.pixels))
		return (init_display_failure(mlxvar));
	render_head(mlxvar);
	render_foot(mlxvar);
	display_stacks(mlxvar, a, b, NULL);
	usleep(750000);
	return (0);
}

void	destroy_display(t_mlxptr mlxvar)
{
	if (mlxvar && mlxvar->key)
	{
		free(mlxvar->win.title);
		mlx_destroy_image(mlxvar->key, mlxvar->win.img_key);
		mlx_destroy_window(mlxvar->key, mlxvar->win.key);
		mlx_destroy_display(mlxvar->key);
		free(mlxvar->key);
		mlxvar->win.title = NULL;
		mlxvar->win.img_key = NULL;
		mlxvar->win.key = NULL;
		mlxvar->key = NULL;
	}
}
