/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 14:21:02 by lsuardi           #+#    #+#             */
/*   Updated: 2021/10/01 14:32:18 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>

typedef struct s_trgb {
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;
	unsigned char	t;
}	t_trgb;

int	main(void)
{
	t_trgb			rgbval = {
		.t = 0,
		.r = 255,
		.g = 0,
		.b = 255
	};
	unsigned int	intval = *(unsigned int *)&rgbval;

	printf("0x%x\n0x%x", intval, (0 << 24) | (255 << 16) | (0 << 8) | 255);
	return (0);
}
