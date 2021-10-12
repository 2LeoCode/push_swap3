/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:17:59 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/11 17:20:33 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack.h>
#include <utils.h>

const char	*ra(t_stack *a, t_stack *b)
{
	size_t	size;
	int		*begin;
	int		x;

	if (!a || !b)
		return ("ra");
	(void)b;
	size = stksize(a);
	if (size < 2)
		return (NULL);
	begin = stkbegin(a);
	x = *begin;
	ft_memmove(begin, begin + 1, (size - 1) * sizeof(int));
	*stkrbegin(a) = x;
	return (NULL);
}

const char	*rb(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return ("rb");
	return (ra(b, a));
}

const char	*rr(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return ("rr");
	ra(a, b);
	rb(a, b);
	return (NULL);
}
