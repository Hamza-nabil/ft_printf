/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 21:30:21 by hnabil            #+#    #+#             */
/*   Updated: 2020/01/01 14:50:45 by hnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_reset(void)
{
	g_info.preci = 0;
	g_info.widh = 0;
	g_info.spf = 0;
	g_info.flags = 0;
}

static void		ft_print(va_list pa)
{
	if (g_info.spf == 'd' || g_info.spf == 'i')
		ft_printd(pa);
	else if (g_info.spf == 'x' || g_info.spf == 'X')
		ft_printx(pa);
	else if (g_info.spf == 'u')
		ft_printu(pa);
	else if (g_info.spf == 'p')
		ft_printp(pa);
	else if (g_info.spf == 's')
		ft_prints(pa);
	else if (g_info.spf == 'c')
		ft_printc(pa);
	else if (g_info.spf == 'n')
		*(int *)va_arg(pa, int *) = g_ret;
	else
		ft_printperc();
}

int				ft_printf(char *s, ...)
{
	va_list		pa;
	size_t		index;
	size_t		len;

	index = 0;
	g_ret = 0;
	va_start(pa, s);
	len = ft_strlen(s);
	while (index < len)
	{
		g_zero = 0;
		ft_reset();
		while (s[index] && s[index] != '%')
			ft_putchar(s[index++]);
		if (index < len)
		{
			ft_collectflags(&s[index], pa, &index);
			ft_print(pa);
		}
	}
	return (g_ret);
}
