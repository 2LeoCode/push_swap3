/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolver_int.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 11:21:46 by lsuardi           #+#    #+#             */
/*   Updated: 2021/10/01 14:37:58 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESOLVER_INT_H
# define RESOLVER_INT_H

# include "resolver.h"

# define TILE_X 384
# define TILE_Y 128

# define LITTLE_ENDIAN 0
# define BIG_ENDIAN 1

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

#endif
