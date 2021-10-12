/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_pixels.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:51:40 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/12 15:18:26 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <resolver_bonus.h>

void	render_head(t_mlxptr mlx)
{
	int	i;

	i = -1;
	while (++i < TILE_Y)
		ft_cmemset(mlx->win.pixels + mlx->win.w * i,
			(unsigned int []){COLOR_WHITE}, sizeof(t_trgb), mlx->win.w);
}

void	render_foot(t_mlxptr mlx)
{
	int	i;

	i = mlx->win.h - TILE_Y - 1;
	while (++i < mlx->win.h)
		ft_cmemset(mlx->win.pixels + mlx->win.w * i,
			(unsigned int []){COLOR_WHITE}, sizeof(t_trgb), mlx->win.w);
}

void	render_rect(t_mlxptr mlx, const t_rect rect)
{
	int	end_x;
	int	end_y;
	int	i;

	end_x = rect.x + rect.w;
	end_y = rect.y + rect.h;
	if (end_x > mlx->win.w)
		end_x = mlx->win.w;
	if (end_y > mlx->win.h)
		end_y = mlx->win.h;
	i = rect.y - 1;
	while (++i <= end_y)
		ft_cmemset(mlx->win.pixels + i * mlx->win.w + rect.x,
			(unsigned int []){COLOR_WHITE}, sizeof(t_trgb), end_x - rect.x);
}
