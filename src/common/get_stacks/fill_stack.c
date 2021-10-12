/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:13:09 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/11 19:14:42 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <stdint.h>
#include <stack.h>
#include <utils.h>
#include <common.h>

#include <stdio.h>

static t_errfun	check_and_push(const char *ptr, t_stack *a)
{
	int		nb;
	char	testnb[12];

	nb = ft_atoi(ptr);
	ft_itostr(nb, testnb);
	if (ft_memcmp(testnb, ptr, ft_strlen(testnb)))
		return (invalid_arguments);
	if (stkpush(a, nb) == STACK_DUPLICATE)
		return (duplicate_element);
	return (NULL);
}

t_errfun	fill_stack(t_stack *a, int ac, const char **av)
{
	const char	*ptr;
	const char	*begin;
	t_errfun	ret;

	while (--ac)
	{
		begin = av[ac];
		ptr = av[ac] + ft_strlen(av[ac]);
		while (ptr != begin)
		{
			while (ptr != begin && ft_isspace(*(ptr - 1)))
				--ptr;
			while (ptr != begin && ft_isdigit(*(ptr - 1)))
				--ptr;
			if (ft_isdigit(*ptr))
			{
				if (ptr != begin)
					ptr -= (*(ptr - 1) == '+' || *(ptr - 1) == '-');
				ret = check_and_push(ptr, a);
				if (ret)
					return (ret);
			}
		}
	}
	return (NULL);
}
