/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 21:49:15 by hnabil            #+#    #+#             */
/*   Updated: 2019/12/25 21:51:01 by hnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_joinn(char *str, char *to_join, int n)
{
	int		len;
	char	*s2;

	s2 = str;
	len = ft_strlen(str);
	if (n > 0)
		while (++len <= n)
			s2 = ft_strjoin(to_join, s2, 0);
	else
	{
		n *= -1;
		while (++len <= n)
			s2 = ft_strjoin(s2, to_join, 1);
	}
	return (s2);
}

static char		*ft_print_minint(char *str, char neg)
{
	str = ft_joinn(str, "0", g_info.preci);
	if (g_info.flags & ZERO)
	{
		str = ft_joinn(str, "0", g_info.widh);
		if (neg == 1)
		{
			if (str[0] != '0')
				str = ft_strjoin("-", str, 0);
			else
				str[0] = '-';
		}
	}
	else
	{
		if (neg == 1)
			str = ft_strjoin("-", str, 0);
		str = ft_joinn(str, " ", g_info.widh);
	}
	return (str);
}

void			ft_put(char *str, char sign)
{
	int		i;

	i = 0;
	if (!(g_info.flags & MIN))
		str = ft_print_minint(str, sign);
	else
	{
		str = ft_joinn(str, "0", g_info.preci);
		if (sign == 1)
			str = ft_strjoin("-", str, 0);
		str = ft_joinn(str, " ", -g_info.widh);
	}
	ft_putstr(str);
	free(str);
}
