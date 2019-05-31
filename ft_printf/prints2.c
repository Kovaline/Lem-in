/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikovalen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 13:21:57 by ikovalen          #+#    #+#             */
/*   Updated: 2019/01/21 16:38:46 by ikovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*prepredouble(long double a, t_flag *fl, char *str, intmax_t i)
{
	unsigned int j;

	j = -1;
	while (++j < fl->dot)
		a = a * 10;
	a = a + 0.5;
	j++;
	while (--j > 0)
		a = a / 10;
	i = (intmax_t)a;
	str = ft_itoa(i);
	str = ft_strjoin(str, ".");
	while (j < fl->dot)
	{
		a = (a - i) * 10;
		i = (intmax_t)a;
		str = ft_strjoin(str, ft_itoa(i));
		j++;
	}
	return (str);
}

char	*predouble(long double a, t_flag *fl, char *str)
{
	intmax_t	i;
	int			c;

	c = 0;
	i = 0;
	if (a < 0)
	{
		a = a * -1;
		c = 1;
	}
	if (fl->dot == 0)
	{
		a = a + 0.5;
		i = (intmax_t)a;
		str = ft_itoa(i);
	}
	else
	{
		str = prepredouble(a, fl, str, i);
	}
	if (c == 1)
		str = ft_strjoin("-", str);
	return (str);
}

void	printdouble(va_list var, t_fl *ft, t_flag *fl)
{
	char			*str;
	long double		a;

	str = ft_strnew(0);
	if (fl->isdot == 0)
		fl->dot = 6;
	fl->isdot = 0;
	if (ft->bigl == 0)
		a = (long double)va_arg(var, double);
	else
		a = va_arg(var, long double);
	if (a == (float)5 / 0)
		str = ft_strdup("inf");
	else
		str = predouble(a, fl, str);
	str = applyflagsint(str, ft, fl);
	fl->count = fl->count + ft_strlen(str);
	ft_putstr(str);
	free(str);
}

void	printhexa(va_list var, t_fl *ft, t_flag *fl)
{
	char			*str;
	uintmax_t		i;
	intmax_t		j;

	j = va_arg(var, intmax_t);
	i = (uintmax_t)j;
	i = convertingu(i, ft);
	if (i == 0)
		fl->iszero = 1;
	if (fl->isdot != 0 || i != 0)
		str = ft_utoa_base(i, 16, fl);
	else
		str = ft_strdup("0");
	str = applyflagsint(str, ft, fl);
	j = -1;
	if (fl->type == 'x')
	{
		while (str[++j] != '\0')
			if (str[j] > 64 && str[j] < 91)
				str[j] = str[j] + 32;
	}
	fl->count = fl->count + ft_strlen(str);
	ft_putstr(str);
	free(str);
}

void	printocta(va_list var, t_fl *ft, t_flag *fl)
{
	char			*str;
	uintmax_t		i;
	intmax_t		j;

	j = va_arg(var, intmax_t);
	i = (uintmax_t)j;
	i = convertingu(i, ft);
	if (fl->dot > 0 && fl->sharp == 1)
		fl->dot--;
	if (fl->isdot != 0 || i != 0)
		str = ft_utoa_base(i, 8, fl);
	else
	{
		fl->iszero = 1;
		str = (char *)malloc(1 * sizeof(char));
		str[0] = '0';
		str[1] = '\0';
	}
	str = applyflagsint(str, ft, fl);
	fl->count = fl->count + ft_strlen(str);
	ft_putstr(str);
	free(str);
}
