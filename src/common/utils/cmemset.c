/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmemset.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 21:43:44 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/03 21:48:19 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

void	*ft_cmemset(void *dst, const void *src, size_t size, size_t nmemb)
{
	void	*ptr;

	ptr = dst;
	while (nmemb--)
	{
		ft_memcpy(ptr, src, size);
		ptr += size;
	}
	return (dst);
}
