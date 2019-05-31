/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   applyflags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikovalen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 13:01:22 by ikovalen          #+#    #+#             */
/*   Updated: 2018/12/03 13:03:44 by ikovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*applyminus(char *tmp, char *str, t_flag *fl, unsigned int size)
{
	unsigned int i;
	unsigned int j;
	unsigned int len;

	i = 0;
	j = 0;
	len = ft_strlen(str);
	tmp = (char *)malloc(size + 1);
	if (fl->sharp == 1 && fl->iszero == 0)
	{
		tmp[j++] = '0';
		if (fl->type != 'o')
			tmp[j++] = 'X';
	}
	if ((fl->type == 'd' || fl->type == 'i') && fl->plus == 1 && str[i] != '-')
		tmp[j++] = '+';
	if ((fl->type == 'd' || fl->type == 'i') && fl->space == 1 && str[i] != '-')
		tmp[j++] = ' ';
	while (str[i] != '\0')
		tmp[j++] = str[i++];
	while (j < size)
		tmp[j++] = ' ';
	tmp[j] = '\0';
	free(str);
	return (tmp);
}

char	*applysignszero(char *tmp, t_flag *fl, int j, int i)
{
	if (i == 0)
		tmp[j] = '-';
	else if (i == -1)
	{
		fl->width--;
		tmp[j] = '+';
	}
	else if (i == -2)
	{
		fl->width--;
		tmp[j] = ' ';
	}
	else
	{
		fl->width = (fl->type == 'o') ? fl->width - 1 : fl->width - 2;
		tmp[j++] = '0';
		if (fl->type != 'o')
			tmp[j] = 'X';
	}
	return (tmp);
}

char	*applyzero(char *tmp, char *str, t_flag *fl)
{
	struct s_norme t;

	t.i = 0;
	t.j = 0;
	t.len = ft_strlen(str);
	tmp = (char *)malloc(fl->width + 1);
	if (fl->sharp == 1 && fl->iszero == 0)
	{
		tmp = applysignszero(tmp, fl, t.j, -3);
		t.j = (fl->type == 'o') ? t.j + 1 : t.j + 2;
	}
	if (str[0] == '-')
		tmp = applysignszero(tmp, fl, t.j++, t.i++);
	else if (fl->plus == 1 && str[0] != '-')
		tmp = applysignszero(tmp, fl, t.j++, -1);
	else if ((fl->type == 'd' || fl->type == 'i')
		&& fl->space == 1 && str[0] != '-')
		tmp = applysignszero(tmp, fl, t.j++, -2);
	while (fl->width-- > t.len)
		tmp[t.j++] = '0';
	while (str[t.i] != '\0')
		tmp[t.j++] = str[t.i++];
	tmp[t.j] = '\0';
	free(str);
	return (tmp);
}

char	*applynone(char *tmp, char *str, t_flag *fl, unsigned int size)
{
	struct s_norme t;

	t.i = 0;
	t.len = ft_strlen(str);
	t.j = 0;
	tmp = (char *)malloc(size + 1);
	if (fl->sharp == 1 && fl->iszero == 0 && size - t.len > 1)
		size = (fl->type == 'o') ? size : size - 1;
	while (t.j + 1 < size - t.len)
		tmp[t.j++] = ' ';
	if (fl->sharp == 1 && fl->iszero == 0)
		tmp = sharp(tmp, fl, &t);
	if (fl->plus == 1 && str[0] != '-')
		tmp[t.j++] = '+';
	else if (fl->space == 1 && str[0] != '-')
		tmp[t.j++] = ' ';
	else if (str[0] == '-' && size > t.len)
		tmp[t.j++] = ' ';
	else if (size > t.len && (fl->sharp != 1 || fl->iszero == 1))
		tmp[t.j++] = ' ';
	while (str[t.i] != '\0')
		tmp[t.j++] = str[t.i++];
	tmp[t.j] = '\0';
	free(str);
	return (tmp);
}
