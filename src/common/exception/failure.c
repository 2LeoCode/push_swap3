/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   failure.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:16:59 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/12 22:07:11 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>
#include <stdlib.h>
#include <stack.h>

int	ft_failure(void (*except)(void), t_stack **sa_ptr, t_stack **sb_ptr)
{
	free(*sa_ptr);
	*sa_ptr = NULL;
	free(*sb_ptr);
	*sb_ptr = NULL;
	return (ft_exception(except));
}
