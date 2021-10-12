/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbcount.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:32:51 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/12 10:40:16 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

int	ft_nbcount(const char *s)
{
	int	cnt;

	cnt = 0;
	while (*s)
	{
		while (ft_isspace(*s))
			++s;
		if (*s == '+' || *s == '-')
		{
			if (!ft_isdigit(s[1]))
				return (-1);
			++s;
		}
		if (*s)
		{
			if (!ft_isdigit(*s) && !ft_isspace(*s))
				return (-1);
			++cnt;
		}
		while (ft_isdigit(*s))
			++s;
		while (ft_isspace(*s))
			++s;
	}
	return (cnt);
}
