/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikovalen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 11:46:26 by ikovalen          #+#    #+#             */
/*   Updated: 2018/11/30 11:46:29 by ikovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

intmax_t	convertingd(intmax_t i, t_fl *ft)
{
	if (ft->l == 1)
		return ((long)i);
	if (ft->h == 1)
		return ((short)i);
	if (ft->hh == 1)
		return ((char)i);
	if (ft->ll == 1)
		return ((long long)i);
	if (ft->z == 1)
		return ((size_t)i);
	if (ft->j == 1)
		return ((intmax_t)i);
	return ((int)i);
}

uintmax_t	convertingu(uintmax_t i, t_fl *ft)
{
	if (ft->l == 1)
		return ((unsigned long)i);
	if (ft->h == 1)
		return ((unsigned short)i);
	if (ft->hh == 1)
		return ((unsigned char)i);
	if (ft->ll == 1)
		return ((unsigned long long)i);
	if (ft->z == 1)
		return ((size_t)i);
	if (ft->j == 1)
		return ((uintmax_t)i);
	return ((unsigned int)i);
}

char		*applyflagsint(char *str, t_fl *ft, t_flag *fl)
{
	char			*tmp;
	unsigned int	i;
	unsigned int	size;
	int				j;
	unsigned int	size1;

	i = 0;
	j = 0;
	tmp = NULL;
	ft->hh = ft->hh;
	if (fl->dot > ft_strlen(str))
		size1 = fl->dot;
	else
		size1 = ft_strlen(str);
	if (fl->width > size1)
		size = fl->width;
	else
		size = size1;
	if (fl->minus == 1)
		tmp = applyminus(tmp, str, fl, size);
	else if (fl->zero == 1 && fl->isdot == 0 && fl->width > ft_strlen(str))
		tmp = applyzero(tmp, str, fl);
	else
		tmp = applynone(tmp, str, fl, size);
	return (tmp);
}

void		printu(va_list var, t_fl *ft, t_flag *fl)
{
	char			*str;
	uintmax_t		i;
	intmax_t		j;

	j = va_arg(var, intmax_t);
	i = (uintmax_t)j;
	i = convertingu(i, ft);
	if (fl->isdot != 0 || i != 0)
	{
		str = ft_utoa_base(i, 10, fl);
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

void		printint(va_list var, t_fl *ft, t_flag *fl)
{
	char			*str;
	intmax_t		i;

	i = convertingd(va_arg(var, intmax_t), ft);
	if (fl->isdot != 0 || i != 0)
		str = ft_itoa_base(i, 10, fl);
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
