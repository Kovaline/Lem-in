/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikovalen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 12:50:42 by ikovalen          #+#    #+#             */
/*   Updated: 2018/11/28 12:50:44 by ikovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printchar(va_list var, t_fl *ft, t_flag *fl)
{
	char	*str;
	char	c;
	int		len;

	c = va_arg(var, int);
	str = ft_strnew(1);
	fl->isdot = 0;
	fl->dot = 0;
	if (fl->minus == 1)
	{
		write(1, &c, 1);
	}
	str = applyflagsint(str, ft, fl);
	len = ft_strlen(str) - 1;
	str[len] = '\0';
	fl->count = fl->count + ft_strlen(str);
	ft_putstr(str);
	free(str);
	fl->count++;
	if (fl->minus == 0)
		write(1, &c, 1);
}

void	printstr(va_list var, t_fl *ft, t_flag *fl)
{
	char			*str;
	unsigned int	i;
	char			*tmp;

	i = -1;
	str = va_arg(var, char *);
	str = (str == NULL) ? "(null)" : str;
	if (fl->isdot == 1 && fl->dot != 0 && fl->dot < ft_strlen(str))
	{
		tmp = ft_strnew(fl->dot);
		while (++i < fl->dot)
			tmp[i] = str[i];
	}
	else if (fl->isdot == 1 && fl->dot == 0)
		tmp = ft_strnew(0);
	else
	{
		tmp = ft_strnew(ft_strlen(str));
		while (++i < ft_strlen(str))
			tmp[i] = str[i];
	}
	B;
	fl->count = fl->count + ft_strlen(tmp);
	ft_putstr(tmp);
	free(tmp);
}

void	printpoint(va_list var, t_fl *ft, t_flag *fl)
{
	char			*str;
	uintmax_t		i;
	intmax_t		j;

	j = va_arg(var, intmax_t);
	i = (unsigned long long)j;
	if (fl->isdot != 0 || i != 0)
		str = ft_utoa_base(i, 16, fl);
	else
		str = ft_strdup("0");
	fl->sharp = 1;
	j = -1;
	fl->dot = 0;
	str = applyflagsint(str, ft, fl);
	while (str[++j] != '\0')
	{
		if (str[j] > 64 && str[j] < 91)
			str[j] = str[j] + 32;
	}
	fl->count = fl->count + ft_strlen(str);
	ft_putstr(str);
	free(str);
}

void	printperc(t_fl *ft, t_flag *fl)
{
	char	*str;

	fl->isdot = 0;
	fl->dot = 0;
	str = ft_strnew(1);
	str[0] = '%';
	str[1] = '\0';
	str = applyflagsint(str, ft, fl);
	fl->count = fl->count + ft_strlen(str);
	ft_putstr(str);
	free(str);
}

void	printit(va_list var, t_fl *ft, t_flag *fl)
{
	if (fl->starwidth != 0 || fl->stardot != 0)
		fillstar(var, fl);
	if (fl->type == 'i' || fl->type == 'd')
		printint(var, ft, fl);
	else if (fl->type == 'u')
		printu(var, ft, fl);
	else if (fl->type == 'c')
		printchar(var, ft, fl);
	else if (fl->type == 's')
		printstr(var, ft, fl);
	else if (fl->type == 'p')
		printpoint(var, ft, fl);
	else if (fl->type == 'x' || fl->type == 'X')
		printhexa(var, ft, fl);
	else if (fl->type == 'o')
		printocta(var, ft, fl);
	else if (fl->type == 'f')
		printdouble(var, ft, fl);
	else if (fl->type == '%')
		printperc(ft, fl);
	else if (fl->type == 'b')
		printbinary(var, ft, fl);
}
