/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikovalen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 11:46:28 by ikovalen          #+#    #+#             */
/*   Updated: 2018/11/27 11:46:29 by ikovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fillstar(va_list var, t_flag *fl)
{
	int		i;

	if (fl->starwidth == 1)
	{
		i = va_arg(var, int);
		if (i >= 0 && fl->checkstar == 0)
			fl->width = (unsigned int)i;
		else if (fl->checkstar == 0)
		{
			fl->minus = 1;
			i = i * -1;
			fl->width = (unsigned int)i;
		}
	}
	if (fl->stardot == 1)
	{
		i = va_arg(var, int);
		if (i >= 0)
			fl->dot = (unsigned int)i;
		else
		{
			fl->isdot = 0;
			fl->dot = 0;
		}
	}
}

char	*sharp(char *tmp, t_flag *fl, struct s_norme *t)
{
	tmp[t->j++] = '0';
	if (fl->type != 'o')
		tmp[t->j++] = 'X';
	return (tmp);
}

int		validletter(char s)
{
	if (s == 'd' || s == 'i' || s == 'u' || s == 'o'
		|| s == 'x' || s == 'X' || s == 'c' || s == 'p'
		|| s == 's' || s == 'f' || s == '%' || s == 'F'
		|| s == 'O' || s == 'C' || s == 'U' || s == 'D'
		|| s == 'S' || s == 'e' || s == 'E' || s == 'b')
		return (1);
	return (0);
}

int		settype(char s, t_flag *fl, t_fl *ft)
{
	if (s == 'd' || s == 'i' || s == 'u' || s == 'o'
		|| s == 'x' || s == 'X' || s == 'c' || s == 'p'
		|| s == 's' || s == 'f' || s == '%' || s == 'F'
		|| s == 'D' || s == 'O' || s == 'U' || s == 'b')
	{
		fl->type = s;
		if (fl->type == 'D' || fl->type == 'O' || fl->type == 'U')
		{
			F;
		}
		E;
		if (fl->type == 'd' || fl->type == 'i' || fl->type == 'f')
			fl->sharp = 0;
		if ((fl->type == 'c' || fl->type == 's' || fl->type == 'p'))
		{
			C;
		}
		if (fl->type == '%' || fl->type == 'u' || fl->type == 'x'
			|| fl->type == 'X' || fl->type == 'o' || fl->type == 'b')
		{
			D;
		}
		return (1);
	}
	return (0);
}
