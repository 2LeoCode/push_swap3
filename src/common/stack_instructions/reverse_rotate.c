/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:20:39 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/11 19:11:45 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack.h>
#include <utils.h>

const char	*rra(t_stack *a, t_stack *b)
{
	size_t		size;
	int			*begin;
	int			x;

	if (!a || !b)
		return ("rra");
	(void)b;
	size = stksize(a);
	if (size < 2)
		return (NULL);
	begin = stkbegin(a);
	x = *stkrbegin(a);
	ft_memmove(begin + 1, begin, (size - 1) * sizeof(int));
	*begin = x;
	return (NULL);
}

const char	*rrb(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return ("rrb");
	return (rra(b, a));
}

const char	*rrr(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return ("rrr");
	rra(a, b);
	rrb(a, b);
	return (NULL);
}
