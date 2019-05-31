/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikovalen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 13:02:59 by ikovalen          #+#    #+#             */
/*   Updated: 2018/11/26 13:03:00 by ikovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	settozero(t_fl *ft, t_flag *fl)
{
	fl->zero = 0;
	fl->sharp = 0;
	fl->minus = 0;
	fl->plus = 0;
	fl->space = 0;
	fl->width = 0;
	ft->h = 0;
	ft->hh = 0;
	ft->l = 0;
	ft->bigl = 0;
	ft->ll = 0;
	ft->z = 0;
	ft->j = 0;
	fl->type = 0;
	fl->dot = 0;
	fl->isdot = 0;
	fl->iszero = 0;
	fl->starwidth = 0;
	fl->stardot = 0;
	fl->checkstar = 0;
}

int		ft_printf(const char *format, ...)
{
	I;
	A;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i = checkflags((char *)format, ++i, &ft, &fl);
			if (fl.type == 0)
			{
				printnone(&ft, &fl, format[i]);
				if (format[i] != '\0')
					i++;
				continue ;
			}
			J;
		}
		else
		{
			ft_putchar(format[i]);
			fl.count++;
		}
		i++;
	}
	va_end(var);
	return (fl.count);
}
