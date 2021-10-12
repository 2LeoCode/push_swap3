/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 13:24:29 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/10 13:24:30 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTIONS_H
# define INSTRUCTIONS_H

# include "stack.h"

const char	*pa(t_stack *a, t_stack *b);
const char	*pb(t_stack *a, t_stack *b);
const char	*sa(t_stack *a, t_stack *b);
const char	*sb(t_stack *a, t_stack *b);
const char	*ss(t_stack *a, t_stack *b);
const char	*ra(t_stack *a, t_stack *b);
const char	*rb(t_stack *a, t_stack *b);
const char	*rr(t_stack *a, t_stack *b);
const char	*rra(t_stack *a, t_stack *b);
const char	*rrb(t_stack *a, t_stack *b);
const char	*rrr(t_stack *a, t_stack *b);

#endif
