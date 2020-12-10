/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 14:21:33 by hnabil            #+#    #+#             */
/*   Updated: 2019/12/25 21:51:44 by hnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

# define ZERO    0b00000001
# define MIN     0b00000010
# define POINT   0b00000100

typedef struct	s_flag
{
	int		preci;
	int		widh;
	char	spf;
	char	flags;
}				t_flag;

size_t	g_ret;
t_flag	g_info;
int		g_zero;

int				ft_printf(char *s, ...);
void			ft_collectflags(char *str, va_list s, size_t *index);
char			*ft_itoa_base(unsigned long int value, int base);
void			ft_put(char *str, char sign);
void			ft_putstr(char *s);
void			ft_putchar(char c);
void			ft_printd(va_list pa);
void			ft_printc(va_list pa);
void			ft_printx(va_list pa);
void			ft_prints(va_list pa);
void			ft_printperc(void);
void			ft_printp(va_list pa);
void			ft_printu(va_list pa);

#endif
