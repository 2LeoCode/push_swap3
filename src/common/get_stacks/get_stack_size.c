/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:17:11 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/11 17:17:12 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <sys/types.h>
#include <utils.h>
#include <common.h>

size_t	get_stack_size(int ac, const char **av)
{
	size_t	size;
	int		cnt;

	size = 0;
	while (ac--)
	{
		cnt = ft_nbcount(*av);
		if (cnt == -1)
			return (INVALID_INPUT);
		size += cnt;
		++av;
	}
	return (size);
}
