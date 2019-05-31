/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonusprints.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikovalen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 14:39:17 by ikovalen          #+#    #+#             */
/*   Updated: 2019/01/24 14:39:19 by ikovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		printnone(t_fl *ft, t_flag *fl, char c)
{
	char *str;

	str = ft_strnew(1);
	str[0] = c;
	fl->space = 0;
	fl->sharp = 0;
	fl->plus = 0;
	fl->isdot = 0;
	str = applyflagsint(str, ft, fl);
	fl->count = fl->count + ft_strlen(str);
	ft_putstr(str);
	free(str);
}

void		printbinary(va_list var, t_fl *ft, t_flag *fl)
{
	char			*str;
	uintmax_t		i;
	intmax_t		j;

	j = va_arg(var, intmax_t);
	i = (uintmax_t)j;
	i = convertingu(i, ft);
	if (fl->isdot != 0 || i != 0)
	{
		str = ft_utoa_base(i, 2, fl);
	}
	else
	{
		str = (char *)malloc(1 * sizeof(char));
		str[0] = '0';
		str[1] = '\0';
	}
	str = applyflagsint(str, ft, fl);
	fl->count = fl->count + ft_strlen(str);
	ft_putstr(str);
	free(str);
}
