/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbcount.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:32:51 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/12 22:33:41 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

int	ft_nbcount(const char *s)
{
	int	cnt;

	cnt = 0;
	while (ft_isspace(*s))
		++s;
	while (*s)
	{
		if ((*s == '+' || *s == '-') && (!*++s || !ft_isdigit(*s)))
			return (-1);
		if (ft_isdigit(*s))
			++cnt;
		else
			return (-1);
		while (ft_isdigit(*s))
			++s;
		if (*s && !ft_isspace(*s))
			return (-1);
		while (ft_isspace(*s))
			++s;
	}
	return (cnt);
}
