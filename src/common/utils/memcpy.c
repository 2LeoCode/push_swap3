/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 21:48:16 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/03 21:48:17 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <sys/types.h>

void	*ft_memcpy(void *dst, const void *src, size_t size)
{
	char			*d_ptr;
	const char		*s_ptr;
	unsigned int	i;

	i = -1;
	d_ptr = (char *)dst;
	s_ptr = (const char *)src;
	while (++i < size)
		d_ptr[i] = s_ptr[i];
	return (dst);
}
