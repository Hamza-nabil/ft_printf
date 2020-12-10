/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collectflags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 21:49:36 by hnabil            #+#    #+#             */
/*   Updated: 2019/12/25 21:49:39 by hnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		flags(char c)
{
	if (c == '-')
	{
		g_info.flags &= (~ZERO);
		g_info.flags |= MIN;
	}
	if (c == '0' && !(g_info.flags & MIN))
		g_info.flags |= ZERO;
	if (c == '.')
		g_info.flags |= POINT;
}

static void		ft_collect(char *str, va_list pa, size_t *index, size_t i)
{
	while ((ft_strchr("-0.*lh# +", str[i]) || ft_isdigit(str[i])))
	{
		flags(str[i]);
		if (ft_isdigit(str[i]))
			g_info.widh = ft_atoi(str + i);
		if (str[i] == '*')
			g_info.widh = (int)va_arg(pa, int);
		if (str[i] == '.')
		{
			if (ft_isdigit(str[i + 1]))
				g_info.preci = ft_atoi(str + i + 1);
			if (str[i + 1] == '*')
				g_info.preci = (int)va_arg(pa, int);
			i++;
		}
		if (ft_isdigit(str[i]))
			while (ft_isdigit(str[i]) && str[i])
				i++;
		else if (ft_strchr("-0.*lh# +", str[i]))
			i++;
		if (g_info.flags & ZERO)
			g_zero = 1;
	}
	g_info.spf = str[i];
	*index += i + 1;
}

void			ft_collectflags(char *str, va_list pa, size_t *index)
{
	size_t i;

	i = 1;
	ft_collect(str, pa, index, i);
	if (g_info.preci < 0)
	{
		g_info.preci = 0;
		g_info.flags ^= POINT;
	}
	if (g_info.widh < 0)
	{
		g_info.widh *= (-1);
		g_info.flags |= MIN;
	}
	if ((g_info.flags & POINT) && g_info.preci >= 0)
		g_info.flags &= (~ZERO);
}
