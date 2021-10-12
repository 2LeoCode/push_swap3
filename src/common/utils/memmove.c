/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 21:48:26 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/03 21:48:28 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <stdint.h>
#include <utils.h>
#include <unistd.h>

void	*ft_memmove(void *dst, const void *src, size_t size)
{
	char		*d_ptr;
	const char	*s_ptr;

	if ((uintptr_t)dst < (uintptr_t)src)
		return (ft_memcpy(dst, src, size));
	s_ptr = (const char *)src;
	d_ptr = (char *)dst;
	while (size--)
		d_ptr[size] = s_ptr[size];
	return (d_ptr);
}
