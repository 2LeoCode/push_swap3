/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 22:19:12 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/03 22:22:36 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <utils.h>

char	*ft_strdup(const char *s)
{
	const size_t	size = ft_strlen(s);
	char			*ptr;

	ptr = malloc(sizeof(char) * (size + 1));
	if (ptr)
		ft_memcpy(ptr, s, size + 1);
	return (ptr);
}
