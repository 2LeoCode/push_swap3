/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 21:48:37 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/03 21:48:39 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

size_t	ft_strlen(const char *s)
{
	const char	*ptr = s;

	while (*ptr)
		++ptr;
	return ((uintptr_t)ptr - (uintptr_t)s);
}
