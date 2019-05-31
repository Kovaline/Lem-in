/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikovalen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 11:56:47 by ikovalen          #+#    #+#             */
/*   Updated: 2018/11/27 11:56:49 by ikovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		checkfirstflag(char *str, int i, t_flag *fl)
{
	while (str[i] == '#' || str[i] == '+' || str[i] == '-'
		|| str[i] == '0' || str[i] == ' ')
	{
		if (str[i] == '#')
			fl->sharp = 1;
		if (str[i] == '0')
			fl->zero = 1;
		if (str[i] == '+')
			fl->plus = 1;
		if (str[i] == '-')
			fl->minus = 1;
		if (str[i] == ' ')
			fl->space = 1;
		i++;
	}
	if (fl->minus == 1)
		fl->zero = 0;
	if (fl->plus == 1)
		fl->space = 0;
	return (i);
}

int		checksecondflag(char *str, int i, t_fl *ft)
{
	if (str[i] == 'z')
		ft->z = 1;
	else if (str[i] == 'j')
		ft->j = 1;
	else if (str[i] == 'h')
	{
		if (str[i + 1] == 'h')
			ft->hh = 1;
		else
			ft->h = 1;
	}
	else if (str[i] == 'l')
	{
		if (str[i + 1] == 'l')
			ft->ll = 1;
		else
			ft->l = 1;
	}
	else if (str[i] == 'L')
		ft->bigl = 1;
	else
		return (0);
	return (1);
}

int		countwidth(char *str, int i, t_flag *fl)
{
	if (str[i] == '*')
	{
		fl->starwidth++;
		i++;
	}
	if (str[i] > 47 && str[i] < 58)
	{
		H;
		fl->width = ft_atoi(str + i);
	}
	G;
	if (str[i] == '.')
	{
		i++;
		fl->isdot = 1;
	}
	if (str[i] > 47 && str[i] < 58)
		fl->dot = ft_atoi(str + i);
	else if (str[i] == '*' && fl->isdot == 1)
	{
		fl->stardot++;
		i++;
	}
	G;
	return (i);
}

int		checkflags(char *str, int i, t_fl *ft, t_flag *fl)
{
	int count;
	int j;

	count = 0;
	while (str[i] != '\0' && validletter(str[i]) == 0)
	{
		j = i;
		if (j < (i = checkfirstflag(str, i, fl)))
			;
		else if ((str[i] > 47 && str[i] < 58) || str[i] == '.' || str[i] == '*')
			i = countwidth(str, i, fl);
		else if (checksecondflag(str, i, ft) == 1)
		{
			if (ft->ll == 1 || ft->hh == 1)
				i++;
			i++;
		}
		else
			break ;
	}
	settype(str[i], fl, ft);
	return (i);
}
