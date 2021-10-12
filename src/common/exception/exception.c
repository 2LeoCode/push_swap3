/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:16:57 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/11 17:16:57 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <utils.h>

#define FAILURE -1

int	ft_exception(void (*except)())
{
	write(1, "Error\n", 6);
	if (except)
		except();
	return (FAILURE);
}

void	invalid_arguments(void)
{
	write(2, "invalid arguments\n", 18);
}

void	out_of_memory(void)
{
	write(2, "out of memory\n", 14);
}

void	duplicate_element(void)
{
	write(2, "duplicate element\n", 18);
}
