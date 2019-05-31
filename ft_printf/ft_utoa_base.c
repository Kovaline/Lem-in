/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikovalen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 13:21:29 by ikovalen          #+#    #+#             */
/*   Updated: 2018/12/15 13:21:31 by ikovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			base_length(uintmax_t val, int base, t_flag *fl)
{
	int len;
	int i;

	i = fl->dot;
	len = 0;
	while (val > 0)
	{
		val = val / base;
		len++;
	}
	if (i > len)
		len = i;
	return (len);
}

static char			*to_str(uintmax_t val, int len, int i, int base)
{
	static char		*digits = "0123456789ABCDEF";
	char			*out;

	out = ft_strnew(len + 1);
	out[len] = '\0';
	while (val != 0 && len > i)
	{
		out[len - 1] = digits[val % base];
		val = val / base;
		len--;
	}
	while (--len >= i)
		out[len] = '0';
	return (out);
}

char				*ft_utoa_base(uintmax_t nb, int base, t_flag *fl)
{
	int	len;

	if (base < 2 || base > 16)
		return (NULL);
	len = base_length(nb, base, fl);
	return (to_str(nb, len, 0, base));
}
